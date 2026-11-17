using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    [Header("Bullet Settings")]
    [SerializeField] private float speed = 10f;
    [SerializeField] private float lifetime = 10f;
    [SerializeField] private int maxBounces = 10;
    [SerializeField] private float minCollisionInterval = 0.1f;

    [Header("Effects")]
    [SerializeField] private GameObject bloodEffectPrefab; // Kéo Prefab máu vào đây

    private Rigidbody2D rb;

    private int bounceCount = 0;
    private float lastCollisionTime = -1f;

    private Vector2 moveDirection;

    // Ghi nhớ Enemy đã trúng
    private HashSet<Enemy> hitEnemies = new HashSet<Enemy>();

    void Start()
    {
        rb = GetComponent<Rigidbody2D>();

        rb.gravityScale = 0f;

        moveDirection = transform.right.normalized;
        rb.velocity = moveDirection * speed;

        Destroy(gameObject, lifetime);
    }

    // Phát hiện Enemy (Is Trigger ON)
    private void OnTriggerEnter2D(Collider2D other)
    {
        Enemy enemy = other.GetComponentInParent<Enemy>();

        if (enemy == null) return;

        // Mỗi Enemy chỉ nhận sát thương một lần
        if (hitEnemies.Add(enemy))
        {
            // Truyền thêm hướng di chuyển của đạn sang cho Enemy
            Vector2 hitDir = rb != null ? rb.velocity.normalized : transform.right;
            enemy.TakeDamage(1, hitDir);

            // --- THÊM PHẦN TẠO HIỆU ỨNG MÁU ---
            if (bloodEffectPrefab != null)
            {
                // Lấy vị trí tâm của Collider hoặc vị trí hiện tại của viên đạn làm điểm phun máu
                Vector2 hitPoint = transform.position;

                // (Nâng cao) Nếu muốn máu văng chuẩn sát mép va chạm, có thể dùng ClosestPoint:
                // Vector2 hitPoint = other.ClosestPoint(transform.position);

                GameObject blood = Instantiate(bloodEffectPrefab, hitPoint, Quaternion.identity);

                // Tự hủy hiệu ứng máu sau 1 giây để dọn dẹp bộ nhớ
                Destroy(blood, 1f);
            }
        }
    }

    // Phát hiện Wall (Is Trigger OFF)
    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (Time.time - lastCollisionTime < minCollisionInterval)
            return;

        lastCollisionTime = Time.time;

        bounceCount++;

        if (bounceCount > maxBounces)
        {
            Destroy(gameObject);
        }
    }
}