using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    public float flySpeed;
    public int damage = 1; // 1. Khai báo biến sát thương ở đây

    void Start()
    {

    }

    void Update()
    {
        var newPosition = transform.position;
        newPosition.y += Time.deltaTime * flySpeed;
        transform.position = newPosition;
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        Health EnemyHealth = collision.GetComponent<Health>();

        if (EnemyHealth != null)
        {
            EnemyHealth.TakeDamage(damage); // 2. Truyền biến damage vào đây
            Destroy(gameObject);
        }
    }
}