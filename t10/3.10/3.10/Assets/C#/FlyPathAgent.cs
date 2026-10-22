using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FlyPathAgent : MonoBehaviour
{
    public FlyPath flypath;
    public float flyspeed;
    private int nextIndex = 1;

    // Start is called before the first frame update
    //id Start() => transform.position = flypath[0];

    // Update is called once per frame
    void Update()
    {
        if (flypath == null) return;
        if (nextIndex >= flypath.waypoints.Length) return;
        if(transform.position != flypath[nextIndex])
        {
            FlyToNextWaypoint();
            LookAt(flypath[nextIndex]);
        }
        else
        {
            nextIndex++;
        }
    }
    private void FlyToNextWaypoint() => transform.position = Vector3.MoveTowards(transform.position, flypath[nextIndex], flyspeed * Time.deltaTime);
    private void LookAt(Vector2 destination)
    {
        Vector2 position = transform.position;
        var lookDirection = destination - position;
        if (lookDirection.magnitude < 0.01f) return;
        var angle = Vector2.SignedAngle(Vector3.up, lookDirection);
        transform.rotation = Quaternion.Euler(0, 0, angle);
    }
}
