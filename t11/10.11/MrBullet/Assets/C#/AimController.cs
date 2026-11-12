using UnityEngine;

public class AimController : MonoBehaviour
{
    [Header("Cài đặt thành phần")]
    public Transform firePoint;       // Kéo object FirePoint (nòng súng) vào đây
    public GameObject crosshairObj;   // Kéo object Crosshair vào đây
    public LineRenderer lineRenderer; // Kéo component LineRenderer của tay vào đây

    private Camera mainCam;

    void Start()
    {
        mainCam = Camera.main;

        // Ban đầu ẩn tâm ngắm và laser đi
        if (crosshairObj) crosshairObj.SetActive(false);
        if (lineRenderer) lineRenderer.enabled = false;
    }

    void Update()
    {
        // Khi người chơi NHẤN GIỮ chuột trái hoặc chạm màn hình
        if (Input.GetMouseButton(0))
        {
            // Bật hiển thị tâm ngắm và laser
            if (crosshairObj) crosshairObj.SetActive(true);
            if (lineRenderer) lineRenderer.enabled = true;

            // Xử lý ngắm bắn và xoay tay
            AimAndShootLogic();
        }
        else
        {
            // Khi THẢ chuột ra
            if (crosshairObj) crosshairObj.SetActive(false);
            if (lineRenderer) lineRenderer.enabled = false;
        }
    }

    void AimAndShootLogic()
    {
        // 1. Lấy vị trí chuột/ngón tay trong không gian game
        Vector3 mousePos = mainCam.ScreenToWorldPoint(Input.mousePosition);
        mousePos.z = 0f;

        // 2. Di chuyển tâm ngắm đến vị trí chuột
        if (crosshairObj)
        {
            crosshairObj.transform.position = mousePos;
        }

        // 3. Vẽ tia laser kéo dài theo hướng ngắm (thay vì dừng ở chuột)
        if (lineRenderer && firePoint)
        {
            lineRenderer.positionCount = 2;
            lineRenderer.SetPosition(0, firePoint.position); // Điểm đầu ở súng

            // Tính hướng từ súng đến chuột, rồi nhân lên một khoảng cách rất xa (ví dụ 50 đơn vị)
            Vector3 directionToMouse = (mousePos - firePoint.position).normalized;
            Vector3 longEndPoint = firePoint.position + directionToMouse * 50f;

            lineRenderer.SetPosition(1, longEndPoint); // Điểm cuối kéo dài tít ra xa
        }

        // 4. Tính vector hướng từ vai đến chuột để xoay tay
        Vector2 direction = (mousePos - transform.position).normalized;

        // Tính góc cơ bản và cộng 90 độ (theo đúng cấu hình sprite của bạn)
        float angle = Mathf.Atan2(direction.y, direction.x) * Mathf.Rad2Deg + 90f;

        // 5. Áp dụng góc xoay vào trục Z
        transform.rotation = Quaternion.Euler(0f, 0f, angle);
    }
}