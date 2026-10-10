using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class enemyshooting : MonoBehaviour
{
    public GameObject enemyBulletPrefab; // Prefab đạn của địch
    public float fireRate = 2f;          // Thời gian giữa các lần bắn (giây)
    private float fireTimer;

    void Update()
    {
        // Đếm thời gian liên tục
        fireTimer += Time.deltaTime;

        // Khi đủ thời gian thì thực hiện bắn
        if (fireTimer >= fireRate)
        {
            Shoot();
            fireTimer = 0f; // Reset lại bộ đếm
        }
    }

    void Shoot()
    {
        if (enemyBulletPrefab != null)
        {
            // Tạo viên đạn tại vị trí của enemy
            Instantiate(enemyBulletPrefab, transform.position, transform.rotation);
        }
    }
}