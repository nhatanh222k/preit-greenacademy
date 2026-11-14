using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerShooting : MonoBehaviour
{
    [Header("Shooting Settings")]
    [SerializeField] private GameObject bulletPrefab;
    [SerializeField] private Vector3 bulletOffset = new Vector3(0f, 0f, 0f);

    void Update()
    {
        // Bắn đạn ngay khi thả nút chuột trái
        if (Input.GetMouseButtonUp(0))
        {
            ShootBullet();
        }
    }

    private void ShootBullet()
    {
        if (bulletPrefab == null)
        {
            Debug.LogWarning("Chưa gán Bullet Prefab!");
            return;
        }

        // Đảm bảo luôn tìm được camera ngay cả khi Camera.main bị lỗi
        Camera cam = Camera.main;
        if (cam == null)
        {
            cam = FindObjectOfType<Camera>();
            if (cam == null)
            {
                Debug.LogError("Không tìm thấy Camera nào trong Scene!");
                return;
            }
        }

        Vector3 mousePosition = cam.ScreenToWorldPoint(Input.mousePosition);
        mousePosition.z = 0f;

        Vector3 spawnPosition = transform.TransformPoint(bulletOffset);
        Vector2 direction = (mousePosition - spawnPosition).normalized;

        float angle = Mathf.Atan2(direction.y, direction.x) * Mathf.Rad2Deg;
        Quaternion rotation = Quaternion.Euler(new Vector3(0, 0, angle));

        Instantiate(bulletPrefab, spawnPosition, rotation);
    }
}