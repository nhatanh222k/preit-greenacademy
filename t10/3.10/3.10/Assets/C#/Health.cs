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

    // Khai báo sự kiện khi đối tượng bị tiêu diệt hoặc máu thay đổi
    public System.Action onDead;
    public System.Action onHealthChanged;

    private void Start()
    {
        healthPoint = defaultHealthPoint;
        onHealthChanged?.Invoke();
    }

    // Hàm nhận sát thương cơ bản (dùng khi không quan tâm vị trí, mặc định tạo ở tâm nhân vật)
    public void TakeDamage(int damage)
    {
        TakeDamage(damage, transform.position);
    }

    // NÂNG CẤP: Hàm nhận sát thương có kèm vị trí dính đạn chính xác
    public virtual void TakeDamage(int damage, Vector2 hitPoint)
    {
        if (healthPoint <= 0) return;

        // 1. Tạo hiệu ứng trúng (Hit Effect) ngay tại vị trí dính đạn thay vì tâm nhân vật
        if (hitEffectPrefab != null)
        {
            var hitEffect = Instantiate(hitEffectPrefab, hitPoint, Quaternion.identity);
            Destroy(hitEffect, 0.2f); // Tự hủy hiệu ứng trúng sau 0.2 giây
        }

        // 2. Trừ máu
        healthPoint -= damage;

        // 3. Gọi sự kiện báo cho thanh máu cập nhật giao diện
        onHealthChanged?.Invoke();

        // 4. Nếu máu giảm về 0 hoặc nhỏ hơn: Gọi hàm Die()
        if (healthPoint <= 0)
        {
            Die();
        }
    }

    protected virtual void Die()
    {
        // Tạo hiệu ứng nổ lớn khi chết tại tâm nhân vật
        if (explosionPrefab != null)
        {
            var explosion = Instantiate(explosionPrefab, transform.position, transform.rotation);
            Destroy(explosion, 0.4f);
        }

        onDead?.Invoke();
        Destroy(gameObject);
    }

    public int GetCurrentHealthPoint()
    {
        return healthPoint;
    }
}