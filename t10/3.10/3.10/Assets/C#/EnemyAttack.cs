using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyAttack : MonoBehaviour
{
    // Biểu thị lượng máu của Enemy (dùng để tiêu diệt enemy sau khi va chạm)
    public EnemyHealth health;

    // Lượng sát thương mà Enemy này gây ra cho người chơi
    public int damage;

    // Hàm này được Unity tự động gọi khi có một Collider khác đi vào vùng va chạm (Trigger) của Enemy
    private void OnTriggerEnter2D(Collider2D collision)
    {
        // Cố gắng lấy component 'PlayerHealth' từ đối tượng vừa va chạm vào
        var PlayerHealth = collision.GetComponent<PlayerHealth>();

        // Kiểm tra xem đối tượng vừa va chạm có phải là Player hay không (nếu có component PlayerHealth tức là Player)
        if (PlayerHealth != null)
        {
            // Gây sát thương cho Player dựa trên biến 'damage' đã cấu hình
            PlayerHealth.TakeDamage(damage);

            // Lập tức trừ 1000 máu của Enemy (thường dùng để enemy tự hủy/chết ngay sau khi tông vào Player)
            health.TakeDamage(1000);
        }
    }

    
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
       
    }
}