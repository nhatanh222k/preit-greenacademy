using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemySpawner : MonoBehaviour
{
    [Header("Cài đặt Quái thường")]
    public EnemyWave[] enemyWaves;
    private int currentWave = 0;
    private int aliveEnemiesCount = 0;      // Đếm số lượng quái đang sống
    private bool allWavesSpawned = false;   // Cờ kiểm tra đã sinh hết wave chưa

    [Header("Cài đặt Boss")]
    public GameObject bossPrefab;           // Prefab của Boss
    public FlyPath bossFlyPath;             // Đường bay riêng dành cho Boss
    public float bossFlySpeed = 3f;         // Tốc độ bay của Boss
    public bool bossSpawned = false;       // Đảm bảo Boss chỉ spawn 1 lần

    void Start()
    {
        SpawnEnemyWave();
    }

    private void SpawnEnemyWave()
    {
        // Nếu đã chạy quá số wave hiện có thì dừng lại
        if (currentWave >= enemyWaves.Length) return;

        var waveInfo = enemyWaves[currentWave];
        var startPosition = waveInfo.flyPath[0];

        for (int i = 0; i < waveInfo.numberOfEnemy; i++)
        {
            var enemy = Instantiate(waveInfo.enemyPrefab, startPosition, Quaternion.identity);

            var agent = enemy.GetComponent<FlyPathAgent>();
            if (agent != null)
            {
                agent.flypath = waveInfo.flyPath;
                agent.flyspeed = waveInfo.speed;
            }

            var health = enemy.GetComponent<EnemyHealth>();
            if (health != null)
            {
                health.onEnemyKilled += OnEnemyKilled;
            }

            aliveEnemiesCount++;
            startPosition += waveInfo.formationOffset;
        }

        currentWave++;

        // KIỂM TRA ĐOẠN NÀY:
        if (currentWave < enemyWaves.Length)
        {
            // Vẫn còn wave tiếp theo thì tiếp tục hẹn giờ spawn
            Invoke(nameof(SpawnEnemyWave), waveInfo.nextWaveDelay);
        }
        else
        {
            
            allWavesSpawned = true;
            Debug.Log("Đã spawn xong tất cả các wave quái thường!");
        }
    }

    // Hàm này nhận tín hiệu khi có 1 con quái chết
    public void OnEnemyKilled(EnemyHealth enemy)
    {
        aliveEnemiesCount--;
        if (aliveEnemiesCount < 0) aliveEnemiesCount = 0;

        Debug.Log($"Quái chết. Số quái còn lại trong hàng đợi: {aliveEnemiesCount} | Đã xong tất cả wave: {allWavesSpawned}");
    }

    private void Update()
    {
        // Kiểm tra liên tục: Nếu đã sinh hết các wave quái thường, 
        // toàn bộ quái trên màn hình đã bị tiêu diệt sạch (<= 0) và Boss chưa từng được gọi
        if (allWavesSpawned && EnemyHealth.LivingEnemyCount <= 0 && !bossSpawned)
        {
            Debug.Log("Tất cả quái thường đã tiêu diệt. Tiến hành gọi Boss!");
            SpawnBoss();
        }
    }

    private void SpawnBoss()
    {
        if (bossPrefab == null)
        {
            Debug.LogError("EnemySpawner: Chưa gán Boss Prefab trong Inspector!");
            return;
        }

        bossSpawned = true;
        Debug.Log("Đang tiến hành Spawn Boss!");

        // Xác định vị trí xuất hiện của Boss
        Vector3 spawnPos = (bossFlyPath != null && bossFlyPath.waypoints.Length > 0)
                           ? (Vector3)bossFlyPath[0]
                           : transform.position;

        // Tạo Boss ra màn hình
        var boss = Instantiate(bossPrefab, spawnPos, Quaternion.identity);

        // Gán đường bay và tốc độ cho Boss
        var bossAgent = boss.GetComponent<BossFlyPath>();
        if (bossAgent != null)
        {
            bossAgent.flypath = bossFlyPath;
            bossAgent.flyspeed = bossFlySpeed;
        }

        // [TÙY CHỌN] Nếu bạn muốn khi Boss chết mới hiện bảng Win, 
        // bạn có thể đăng ký sự kiện onEnemyKilled của Boss ở đây tương tự quái thường.
    }
}