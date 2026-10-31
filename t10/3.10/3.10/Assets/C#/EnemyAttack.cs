using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyAttack : MonoBehaviour
{
    public EnemyHealth health;
    public int damage;

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