using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyAttack : MonoBehaviour

{
    public EnemyHealth health;
    public int damage;

    private void OnTriggerEnter2D(Collider2D collision)
    {
        var PlayerHealth = collision.GetComponent<PlayerHealth>();
        if (PlayerHealth != null)
        {
            PlayerHealth.TakeDamage(damage);
            health.TakeDamage(1000);
        }
 }
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
