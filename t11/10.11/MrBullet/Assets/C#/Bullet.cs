
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    [Header("Bullet Settings")]
    [SerializeField] private float speed = 10f;
    [SerializeField] private float lifetime = 10f;
    [SerializeField] private int maxBounces = 10;
    [SerializeField] private float minCollisionInterval = 0.1f;

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
            enemy.TakeDamage(1);
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
