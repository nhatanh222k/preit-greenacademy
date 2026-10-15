using UnityEngine;

public class EnemyHealth : Health
{
    public static int LivingEnemyCount { get; private set; }

    private bool countedAsAlive = false;

    private void Awake()
    {
        LivingEnemyCount++;
        countedAsAlive = true;

        Debug.Log("Enemy spawned. Living enemies: " + LivingEnemyCount);
    }

    protected override void Die()
    {
        if (countedAsAlive)
        {
            LivingEnemyCount--;
            countedAsAlive = false;
        }

        Debug.Log("Enemy died. Living enemies: " + LivingEnemyCount);

        base.Die();
    }

    private void OnDestroy()
    {
        // Nếu địch bị xóa mà không chết qua TakeDamage,
        // vẫn cập nhật bộ đếm.
        if (countedAsAlive)
        {
            LivingEnemyCount--;
            countedAsAlive = false;
        }
    }
}