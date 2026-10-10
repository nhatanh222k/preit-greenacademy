using UnityEngine;

public class enemybullet : MonoBehaviour
{
    public float flySpeed = 5f;

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
        playerhealth playerhealth = collision.GetComponent<playerhealth>();
        if (playerhealth != null)
        {
            playerhealth.TakeDamage(1);
            Destroy(gameObject); // Hủy viên đạn sau khi trúng Player
        }
    }
}