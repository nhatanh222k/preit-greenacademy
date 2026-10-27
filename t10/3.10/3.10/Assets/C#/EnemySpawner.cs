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
    private bool bossSpawned = false;       // Đảm bảo Boss chỉ spawn 1 lần

    // Start is called before the first frame update
    void Start() => SpawnEnemyWave();

    private void SpawnEnemyWave()
    {
        var waveInfo = enemyWaves[currentWave];
        var startPosition = waveInfo.flyPath[0];

        for (int i = 0; i < waveInfo.numberOfEnemy; i++)
        {
            var enemy = Instantiate(waveInfo.enemyPrefab, startPosition, Quaternion.identity);

            // Gán đường bay cho quái thường
            var agent = enemy.GetComponent<FlyPathAgent>();
            if (agent != null)
            {
                agent.flypath = waveInfo.flyPath;
                agent.flyspeed = waveInfo.speed;
            }

            // Đăng ký sự kiện khi quái chết để trừ số lượng
            var health = enemy.GetComponent<EnemyHealth>();
            if (health != null)
            {
                health.onEnemyKilled += OnEnemyKilled;
            }

            aliveEnemiesCount++; // Tăng số lượng quái đang sống lên 1
            startPosition += waveInfo.formationOffset;
        }

        currentWave++;

        // Nếu còn wave tiếp theo thì tiếp tục lên lịch spawn
        if (currentWave < enemyWaves.Length)
        {
            Invoke(nameof(SpawnEnemyWave), waveInfo.nextWaveDelay);
        }
        else
        {
            allWavesSpawned = true; // Đã sinh xong toàn bộ các wave quái thường
        }
    }

    // Hàm này nhận tín hiệu khi có 1 con quái chết
    public void OnEnemyKilled()
    {
        aliveEnemiesCount--;

        // Nếu đã sinh hết quái, số lượng quái sống bằng 0 và Boss chưa xuất hiện -> Spawn Boss!
        if (allWavesSpawned && aliveEnemiesCount <= 0 && !bossSpawned)
        {
            SpawnBoss();
        }
    }

    private void SpawnBoss()
    {
        if (bossPrefab == null) return;

        bossSpawned = true;

        // Xác định vị trí xuất hiện của Boss (lấy waypoint đầu tiên của đường bay Boss, hoặc vị trí Spawner)
        Vector3 spawnPos = (bossFlyPath != null && bossFlyPath.waypoints.Length > 0)
                           ? (Vector3)bossFlyPath[0]
                           : transform.position;

        // Tạo Boss ra màn hình
        var boss = Instantiate(bossPrefab, spawnPos, Quaternion.identity);

        // [QUAN TRỌNG] Tự động gán đường bay và tốc độ cho Boss ngay khi sinh ra
        var bossAgent = boss.GetComponent<BossFlyPath>();
        if (bossAgent != null)
        {
            bossAgent.flypath = bossFlyPath;
            bossAgent.flyspeed = bossFlySpeed;
        }
    }

    // Update is called once per frame
    void Update()
    {

    }
}