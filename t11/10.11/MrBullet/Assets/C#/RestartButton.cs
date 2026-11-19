using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class RestartButton : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    
        // Hàm này chỉ chuyên làm nhiệm vụ tải lại màn chơi hiện tại
    public void RestartCurrentScene()
    {
     string currentSceneName = SceneManager.GetActiveScene().name;
     SceneManager.LoadScene(currentSceneName);
    }
    
}
