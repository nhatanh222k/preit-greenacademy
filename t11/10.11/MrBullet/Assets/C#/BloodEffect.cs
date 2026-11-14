using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BloodEffect : MonoBehaviour
{
    [SerializeField] private ParticleSystem bloodParticle;
    // Start is called before the first frame update
    void Start()
    {
        if (bloodParticle != null)
        {
            bloodParticle.Play();
            Destroy(gameObject,
                bloodParticle.main.duration +
                bloodParticle.main.startLifetime.constantMax);
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
