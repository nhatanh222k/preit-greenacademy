using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FlyPathAgent : MonoBehaviour
{
    public FlyPath flypath;
    public float flyspeed;
    private int nextIndex = 1; // Giữ nguyên giá trị 1 để bay tiếp từ vị trí được Spawn theo formation

    void Start()
    {
        // Để trống để giữ nguyên vị trí và khoảng cách formation mà EnemySpawner đã tạo ra
    }

    void Update()
    {
        if (flypath == null || flypath.waypoints.Length == 0) return;

        // Nếu chạy đến điểm cuối cùng, vòng lặp lại từ đầu (Waypoint 0)
        if (nextIndex >= flypath.waypoints.Length)
        {
            nextIndex = 0;
        }

        Vector2 targetPosition = flypath[nextIndex];

        if ((Vector2)transform.position != targetPosition)
        {
            FlyToNextWaypoint(targetPosition);
            LookAt(targetPosition);
        }
        else
        {
            nextIndex++;
        }
    }

    private void FlyToNextWaypoint(Vector2 target)
    {
        transform.position = Vector3.MoveTowards(transform.position, target, flyspeed * Time.deltaTime);
    }

    private void LookAt(Vector2 destination)
    {
        Vector2 position = transform.position;
        var lookDirection = destination - position;
        if (lookDirection.magnitude < 0.01f) return;
        var angle = Vector2.SignedAngle(Vector3.up, lookDirection);
        transform.rotation = Quaternion.Euler(0, 0, angle);
    }
}