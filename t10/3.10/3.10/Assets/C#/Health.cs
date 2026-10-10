using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Health : MonoBehaviour
{
    [Header("Effects")]
    public GameObject hitEffectPrefab;       // Hiệu ứng khi bị trúng đạn (chớp sáng/tóe lửa)
    public GameObject explosionPrefab;     // Hiệu ứng nổ lớn khi chết

    [Header("Health Settings")]
    public int defaultHealthPoint = 3;     // Máu mặc định (đặt là 3)
    private int healthPoint;

    private void Start()
    {
        healthPoint = defaultHealthPoint;
    }

    // Hàm nhận sát thương
    public void TakeDamage(int damage)
    {
        if (healthPoint <= 0) return;

        // 1. Mỗi lần trúng đạn: Tạo hiệu ứng trúng (Hit Effect) ngay tại vị trí nhân vật
        if (hitEffectPrefab != null)
        {
            var hitEffect = Instantiate(hitEffectPrefab, transform.position, transform.rotation);
            Destroy(hitEffect, 0.5f); // Tự hủy hiệu ứng trúng sau 0.5 giây để nhẹ game
        }

        // Trừ máu
        healthPoint -= damage;

        // 2. Nếu máu giảm về 0 (đủ 3 viên): Kích hoạt hiệu ứng nổ và tiêu diệt đối tượng
        if (healthPoint <= 0)
        {
            Die();
        }
    }

    protected virtual void Die()
    {
        // Tạo hiệu ứng nổ lớn khi chết
        if (explosionPrefab != null)
        {
            var explosion = Instantiate(explosionPrefab, transform.position, transform.rotation);
            Destroy(explosion, 1f); // Tự hủy hiệu ứng nổ sau 1 giây
        }

        // Xóa đối tượng khỏi màn chơi
        Destroy(gameObject);
    }
}