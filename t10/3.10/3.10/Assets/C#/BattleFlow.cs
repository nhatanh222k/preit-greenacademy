using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BattleFlow : MonoBehaviour
{
    public GameObject gameOverUI;
    public playerhealth playerhealth;
    public GameObject bgMusic;
    // Start is called before the first frame update
    void Start()
    {
        gameOverUI.SetActive(false);
        playerhealth.onDead += OnGameOver;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    private void OnGameOver()
    {
        gameOverUI.SetActive(true);
        bgMusic.SetActive(false);
    }
}
