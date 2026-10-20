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

        // 2. Trừ máu (chỉ trừ 1 lần duy nhất)
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
        // Tạo hiệu ứng nổ lớn khi chết
        if (explosionPrefab != null)
        {
            var explosion = Instantiate(explosionPrefab, transform.position, transform.rotation);
            Destroy(explosion, 1f); // Tự hủy hiệu ứng nổ sau 1 giây
        }

        // Thông báo sự kiện chết cho các script khác đang lắng nghe
        onDead?.Invoke();

        // Xóa đối tượng khỏi màn chơi
        Destroy(gameObject);
    }
    public int GetCurrentHealthPoint()
    {
        return healthPoint;
    }
}