using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class playershooting : MonoBehaviour
{
    // Start is called before the first frame update
    public GameObject bulletPrefab;

    public Transform firePointLeft;
    public Transform firePointMiddle;
    public Transform firePointRight;
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            Shoot(firePointLeft);
            Shoot(firePointMiddle);
            Shoot(firePointRight);
        }
    }

    void Shoot(Transform firePoint)
    {
        Instantiate(bulletPrefab, firePoint.position, firePoint.rotation);
    }
}
