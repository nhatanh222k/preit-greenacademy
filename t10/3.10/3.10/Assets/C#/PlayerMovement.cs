using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    [Header("Movement Settings")]
    [SerializeField] private float smoothSpeed = 5f; // Giảm xuống từ 15f để máy bay di chuyển chậm và từ tốn hơn

    private Camera mainCamera;
    private Vector3 targetPosition;
    private bool isMoving = false;

    void Start()
    {
        mainCamera = Camera.main;
        targetPosition = transform.position;
    }

    void Update()
    {
        bool isPressed = false;
        Vector3 inputPosition = Vector3.zero;

        // 1. Kiểm tra cảm ứng trên điện thoại
        if (Input.touchCount > 0)
        {
            isPressed = true;
            inputPosition = Input.GetTouch(0).position;
        }
        // 2. Dự phòng bằng chuột trái trên PC (coi như ngón tay)
        else if (Input.GetMouseButton(0))
        {
            isPressed = true;
            inputPosition = Input.mousePosition;
        }

        // Nếu người chơi đang bấm/chạm, cập nhật vị trí mục tiêu
        if (isPressed)
        {
            Vector3 worldPoint = mainCamera.ScreenToWorldPoint(inputPosition);
            worldPoint.z = 0;
            targetPosition = worldPoint;
            isMoving = true;
        }

        // Di chuyển máy bay mượt mà đến vị trí đích với tốc độ chậm hơn
        if (isMoving)
        {
            transform.position = Vector3.Lerp(transform.position, targetPosition, smoothSpeed * Time.deltaTime);
        }
    }
}