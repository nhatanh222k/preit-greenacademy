using UnityEngine;
using UnityEngine.SceneManagement;

public class MainMenu : MonoBehaviour
{
    public void OnPlayButtonClicked()
    {
        // Đảm bảo game không bị dừng từ ván trước
        Time.timeScale = 1f;

        // Bắt đầu màn chơi mới
        SceneManager.LoadScene("Battle");
    }
}