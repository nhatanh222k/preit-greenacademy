using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    public float flySpeed;
    public int damage = 1;

    void Update()
    {
        var newPosition = transform.position;
        newPosition.y += Time.deltaTime * flySpeed;
        transform.position = newPosition;
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        Health targetHealth = collision.GetComponent<Health>();

        if (targetHealth != null)
        {
            // Lấy điểm tiếp xúc chính xác trên Collider của mục tiêu
            Vector2 hitPoint = collision.ClosestPoint(transform.position);

            // Gây sát thương và truyền vị trí dính đạn vào Health
            targetHealth.TakeDamage(damage, hitPoint);

            // Hủy viên đạn
            Destroy(gameObject);
        }
    }
}