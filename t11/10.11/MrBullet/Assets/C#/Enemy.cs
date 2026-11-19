
using UnityEngine;

public class Enemy : MonoBehaviour
{
    [Header("Enemy Settings")]
    [SerializeField] private int health = 1;
    [SerializeField] private float ragdollForce = 3f;

    [Header("Head Settings")]
    [SerializeField] private SpriteRenderer headRenderer;
    [SerializeField] private Sprite deadHead;

    private bool isDead = false;

    public bool IsDead => isDead;

    public void TakeDamage(int damage, Vector2 hitDirection)
    {
        if (isDead) return;

        health -= damage;

        if (health <= 0)
        {
            Die(hitDirection);
        }
    }

    private void Die(Vector2 hitDirection)
    {
        if (isDead) return;

        isDead = true;
        gameObject.tag = "Untagged";
        PlayerShooting player = FindObjectOfType<PlayerShooting>();
        if (player != null)
        {
            player.TriggerWin(); // Báo cho Player biết để hiển thị Panel chiến thắng tương ứng (3s, 2s, 1s, hoặc 0s)
        }

        // 1. Đổi hình ảnh đầu chết
        if (headRenderer != null && deadHead != null)
        {
            headRenderer.sprite = deadHead;
        }

        // 2. Chuyển toàn bộ Enemy sang DeadEnemy
        int deadLayer = LayerMask.NameToLayer("DeadEnemy");

        if (deadLayer != -1)
        {
            SetLayerRecursively(transform, deadLayer);
        }
        else
        {
            Debug.LogWarning("Chưa tạo Layer DeadEnemy!");
        }

        // 3. Tắt Rigidbody và Collider của object cha
        Collider2D parentCol = GetComponent<Collider2D>();
        if (parentCol != null)
            parentCol.enabled = false;

        Rigidbody2D parentRb = GetComponent<Rigidbody2D>();
        if (parentRb != null)
            parentRb.simulated = false;

        // 4. Lấy Rigidbody và Collider của các bộ phận
        Rigidbody2D[] childRbs = GetComponentsInChildren<Rigidbody2D>();
        Collider2D[] childCols = GetComponentsInChildren<Collider2D>();

        // 5. Thiết lập Collider cho ragdoll
        foreach (Collider2D col in childCols)
        {
            if (col.transform == transform) continue;

            col.enabled = true;
            col.isTrigger = false;
        }

        // 6. Tạo vật liệu ma sát
        PhysicsMaterial2D slipMat =
            new PhysicsMaterial2D("NoSlipMaterial");

        slipMat.friction = 1f;
        slipMat.bounciness = 0f;

        foreach (Collider2D col in childCols)
        {
            if (col.transform == transform) continue;

            col.sharedMaterial = slipMat;
        }

        // 7. Chuyển các bộ phận thành Dynamic
        foreach (Rigidbody2D rb in childRbs)
        {
            if (rb.gameObject == gameObject) continue;

            rb.bodyType = RigidbodyType2D.Dynamic;
            rb.simulated = true;
            rb.gravityScale = 3f;
            rb.constraints = RigidbodyConstraints2D.None;
            rb.drag = 5f;

            // Lực đẩy theo hướng viên đạn
            rb.AddForce(
                hitDirection.normalized * ragdollForce,
                ForceMode2D.Impulse
            );

            // Xoay nhẹ ngẫu nhiên
            rb.AddTorque(
                Random.Range(-2f, 2f),
                ForceMode2D.Impulse
            );
        }

        Debug.Log("Enemy đã chết!");
    }

    // Chuyển Layer cho toàn bộ GameObject con và cháu
    private void SetLayerRecursively(Transform obj, int layer)
    {
        obj.gameObject.layer = layer;

        foreach (Transform child in obj)
        {
            SetLayerRecursively(child, layer);
        }
    }
}
