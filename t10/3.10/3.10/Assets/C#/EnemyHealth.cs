using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyHealth : Health
{
    protected override void Die()
    {
        // Gọi lại logic nổ và hủy đối tượng từ lớp cha (Health)
        base.Die();

        Debug.Log("Enemy died");
    }
}