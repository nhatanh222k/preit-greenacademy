
using UnityEngine;

public class Enemy : MonoBehaviour
{
    [Header("Enemy Settings")]
    [SerializeField] private int health = 1;

    [Header("Head Settings")]
    [SerializeField] private SpriteRenderer headRenderer;
    [SerializeField] private Sprite deadHead;

    private bool isDead = false;

    public void TakeDamage(int damage)
    {
        if (isDead) return;

        health -= damage;

        if (health <= 0)
        {
            Die();
        }
    }

    private void Die()
    {
        isDead = true;

        if (headRenderer != null && deadHead != null)
        {
            headRenderer.sprite = deadHead;
        }

        Debug.Log("Enemy đã chết và đổi đầu!");
    }
}
