using UnityEngine;

public class EnemyBullet : MonoBehaviour
{
    public float flySpeed = 5f;

    void Start()
    {
       
        transform.rotation = Quaternion.Euler(0f, 0f, 0f);
    }

    void Update()
    {
        // Đạn địch bay xuống dưới theo trục Y âm
        var newPosition = transform.position;
        newPosition.y -= Time.deltaTime * flySpeed;
        transform.position = newPosition;
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        // Nếu chạm vào Player thì trừ máu Player
        PlayerHealth playerHealth = collision.GetComponent<PlayerHealth>();
        if (playerHealth != null)
        {
            playerHealth.TakeDamage(1);
            Destroy(gameObject); // Hủy viên đạn sau khi trúng Player
        }
    }
}