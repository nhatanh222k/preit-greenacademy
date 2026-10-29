using UnityEngine;
using UnityEngine.SceneManagement;

public class BattleFlow : MonoBehaviour
{
    [Header("UI & Audio")]
    [SerializeField] private GameObject gameOverUI;
    [SerializeField] private GameObject gameWinUI;
    [SerializeField] private GameObject bgMusic;

    [Header("References")]
    [SerializeField] private PlayerHealth playerHealth;

    private bool isGameOver;
    private bool isGameWon;

    private void Awake()
    {
        isGameOver = false;
        isGameWon = false;
        Time.timeScale = 1f;
    }

    private void Start()
    {
        Debug.Log("Battle bắt đầu - số địch hiện tại: "
          + EnemyHealth.LivingEnemyCount);
        if (gameOverUI != null)
            gameOverUI.SetActive(false);
        else
            Debug.LogError("BattleFlow: Chưa gán Game Over UI!");

        if (gameWinUI != null)
            gameWinUI.SetActive(false);
        else
            Debug.LogError("BattleFlow: Chưa gán Game Win UI!");

        if (bgMusic != null)
            bgMusic.SetActive(true);

        if (playerHealth == null)
            playerHealth = FindFirstObjectByType<PlayerHealth>();

        if (playerHealth != null)
        {
            playerHealth.onDead -= OnGameOver;
            playerHealth.onDead += OnGameOver;
        }
        else
        {
            Debug.LogError("BattleFlow: Không tìm thấy PlayerHealth!");
        }

        Debug.Log("BattleFlow đã khởi tạo. Số địch: "
                  + EnemyHealth.LivingEnemyCount);
    }

    private void Update()
    {
        if (isGameOver || isGameWon)
            return;

        // Tìm EnemySpawner trong scene
        EnemySpawner spawner = FindFirstObjectByType<EnemySpawner>();

        if (spawner != null)
        {
            // ĐIỀU KIỆN THẮNG: 
            // 1. Boss bắt buộc phải đã được spawn ra rồi (tránh việc thắng ngay đầu game lúc chưa có quái)
            // 2. Tổng số lượng enemy/boss sống trên màn hình (LivingEnemyCount) đã về 0 (tức là Boss đã chết)
            if (spawner.bossSpawned && EnemyHealth.LivingEnemyCount <= 0)
            {
                OnGameWin();
            }
        }
    }

    private void OnDestroy()
    {
        if (playerHealth != null)
            playerHealth.onDead -= OnGameOver;
    }

    private void OnGameOver()
    {
        if (isGameOver || isGameWon)
            return;

        isGameOver = true;

        if (gameOverUI != null)
            gameOverUI.SetActive(true);

        if (bgMusic != null)
            bgMusic.SetActive(false);

        Debug.Log("GAME OVER - Đã bật Game Over UI");
    }

    private void OnGameWin()
    {
        if (isGameWon || isGameOver)
            return;

        isGameWon = true;

        if (gameWinUI != null)
        {
            gameWinUI.SetActive(true);
            Debug.Log("GAME WIN - Đã bật Game Win UI");
        }
        else
        {
            Debug.LogError("GAME WIN nhưng gameWinUI chưa được gán!");
        }

        if (bgMusic != null)
            bgMusic.SetActive(false);

        if (playerHealth != null)
            playerHealth.gameObject.SetActive(false);
    }

    public void ReturnToMainMenu()
    {
        Time.timeScale = 1f;
        SceneManager.LoadScene("MainMenu");
    }
}