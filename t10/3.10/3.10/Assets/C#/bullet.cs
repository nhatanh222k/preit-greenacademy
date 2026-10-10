using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class bullet : MonoBehaviour
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
        Health enemyHealth = collision.GetComponent<Health>();

        if (enemyHealth != null)
        {
            enemyHealth.TakeDamage(damage); // 2. Truyền biến damage vào đây
            Destroy(gameObject);
        }
    }
}