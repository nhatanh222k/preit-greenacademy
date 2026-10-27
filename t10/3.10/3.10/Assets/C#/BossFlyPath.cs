using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BossFlyPath : MonoBehaviour
{
    public FlyPath flypath;
    public float flyspeed;
    private int nextIndex = 0; // Bắt đầu từ waypoint đầu tiên

    void Start()
    {
        // Giữ nguyên góc xoay ban đầu của Boss (không gọi hàm xoay hướng)
    }

    void Update()
    {
        // Kiểm tra an toàn xem đã gán đường bay chưa
        if (flypath == null || flypath.waypoints == null || flypath.waypoints.Length == 0) return;

        // Lấy vị trí mục tiêu hiện tại
        Vector2 targetPosition = flypath[nextIndex];

        // Kiểm tra xem Boss đã đến gần waypoint chưa
        if (Vector2.Distance(transform.position, targetPosition) > 0.05f)
        {
            FlyToNextWaypoint(targetPosition);
            // Đã xóa hàm LookAt ở đây để Boss không bị xoay đầu
        }
        else
        {
            // Đã đến nơi, chuyển sang waypoint tiếp theo
            nextIndex++;

            // Nếu chạy đến điểm cuối cùng, vòng lặp lại từ đầu (Waypoint 0)
            if (nextIndex >= flypath.waypoints.Length)
            {
                nextIndex = 0;
            }
        }
    }

    private void FlyToNextWaypoint(Vector2 target)
    {
        transform.position = Vector3.MoveTowards(transform.position, target, flyspeed * Time.deltaTime);
    }
}