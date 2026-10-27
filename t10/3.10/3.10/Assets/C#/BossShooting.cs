using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BossShooting : MonoBehaviour
{
    [Header("Cài đặt đạn")]
    public GameObject enemyBulletPrefab;
    public Vector3 bulletOffset = new Vector3(0, -1f, 0);

    [Header("Cài đặt chu kỳ bắn và nghỉ")]
    public float timeBetweenBullets = 0.2f; // Thời gian nghỉ giữa các viên đạn trong một đợt bắn liên tục
    public float burstDuration = 3.0f;      // Thời gian kéo dài của một đợt bắn liên tục (giây)
    public float restDuration = 4.0f;       // Thời gian ngưng bắn (nghỉ) giữa các đợt (giây)

    private float stateTimer = 0f;          // Bộ đếm thời gian chung cho trạng thái
    private float bulletTimer = 0f;         // Bộ đếm thời gian để rải đạn trong đợt bắn
    private bool isShooting = true;         // Trạng thái hiện tại: True = Đang bắn, False = Đang nghỉ

    void Start()
    {
        // Khởi tạo ban đầu
        stateTimer = burstDuration;
    }

    void Update()
    {
        // Cộng dồn thời gian
        stateTimer -= Time.deltaTime;

        if (isShooting)
        {
            // === TRẠNG THÁI ĐANG BẮN LIÊN TỤC ===
            bulletTimer += Time.deltaTime;

            // Cứ đủ thời gian giữa các viên thì bắn 1 viên
            if (bulletTimer >= timeBetweenBullets)
            {
                ShootBullet();
                bulletTimer = 0f;
            }

            // Khi hết thời gian của đợt bắn -> Chuyển sang trạng thái Nghỉ
            if (stateTimer <= 0f)
            {
                isShooting = false;
                stateTimer = restDuration; // Đặt lại thời gian nghỉ
                // Debug.Log("Boss bắt đầu nghỉ ngơi...");
            }
        }
        else
        {
            // === TRẠNG THÁI ĐANG NGHỈ NGƠI ===
            // Trong thời gian này không gọi hàm bắn đạn

            // Khi hết thời gian nghỉ -> Chuyển lại sang trạng thái Bắn
            if (stateTimer <= 0f)
            {
                isShooting = true;
                stateTimer = burstDuration; // Đặt lại thời gian bắn
                bulletTimer = 0f;
                // Debug.Log("Boss bắt đầu xả đạn trở lại!");
            }
        }
    }

    private void ShootBullet()
    {
        if (enemyBulletPrefab == null) return;

        // Tạo viên đạn tại vị trí của Boss + khoảng cách lệch
        Instantiate(enemyBulletPrefab, transform.position + bulletOffset, transform.rotation);
    }
}