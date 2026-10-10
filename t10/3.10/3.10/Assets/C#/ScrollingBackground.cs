using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ScrollingBackground : MonoBehaviour
{
    public float speed = 2f;
    public float imageSize = 10f; // Chiều cao của ảnh background
    public Transform otherBackground; // Kéo background còn lại vào đây trong Inspector
    // Start is called before the first frame update

    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        // Cho cả 2 background di chuyển xuống dưới
        transform.Translate(Vector3.down * speed * Time.deltaTime);
        otherBackground.Translate(Vector3.down * speed * Time.deltaTime);

        // Khi background này chạy ra khỏi màn hình (vượt quá chiều cao), đưa nó lên phía trên background kia
        if (transform.position.y <= -imageSize)
        {
            Vector3 newPos = otherBackground.position + new Vector3(0, imageSize, 0);
            transform.position = newPos;
        }
    }
}
