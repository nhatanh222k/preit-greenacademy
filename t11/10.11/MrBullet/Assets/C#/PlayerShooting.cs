using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class PlayerShooting : MonoBehaviour
{
    [Header("Shooting Settings")]
    [SerializeField] private GameObject bulletPrefab;
    [SerializeField] private Vector3 bulletOffset = new Vector3(0f, 0f, 0f);

    [Header("Ammo & Star Settings")]
    [SerializeField] private int maxGoldenBullets = 3;  // Số lượng đạn vàng (đạt 3 sao)
    [SerializeField] private int maxGreyBullets = 1;    // Số lượng đạn xám dự phòng

    private int totalMaxAmmo;
    private int currentAmmoLeft;
    private int bulletsFired = 0;
    private bool isGameOver = false;                    // Khóa không cho bắn khi game đã kết thúc

    [Header("UI Bullet Sprites")]
    [SerializeField] private Sprite activeBulletSprite;
    [SerializeField] private Sprite greyBulletSprite;
    [SerializeField] private List<Image> bulletIcons;

    [Header("Panels Kết Quả")]
    [SerializeField] private GameObject panel3Stars;      // Panel 3 sao
    [SerializeField] private GameObject panel2Stars;      // Panel 2 sao
    [SerializeField] private GameObject panel1Star;       // Panel 1 sao
    [SerializeField] private GameObject panel0StarsWin;   // Panel 0 sao (Vẫn THẮNG khi dùng hết sạch đạn)
    [SerializeField] private GameObject losePanel;        // Panel THUA (Hết đạn mà địch chưa chết)

    void Start()
    {
        totalMaxAmmo = maxGoldenBullets + maxGreyBullets;
        currentAmmoLeft = totalMaxAmmo;
        bulletsFired = 0;
        isGameOver = false;

        // Ẩn toàn bộ các bảng kết quả khi bắt đầu màn chơi
        //HideAllPanels();

        UpdateAmmoUI();
    }

    void Update()
    {
        if (isGameOver) return;

        // Bắn đạn ngay khi thả nút chuột trái
        if (Input.GetMouseButtonUp(0))
        {
            ShootBullet();
        }
    }

    private void ShootBullet()
    {
        if (currentAmmoLeft <= 0)
        {
            Debug.Log("Đã hết sạch đạn! Không thể bắn.");
            return;
        }

        if (bulletPrefab == null)
        {
            Debug.LogWarning("Chưa gán Bullet Prefab!");
            return;
        }

        // 1. Tăng số đạn đã bắn và giảm số đạn còn lại
        bulletsFired++;
        currentAmmoLeft--;

        // 2. Cập nhật lại giao diện UI đạn
        UpdateAmmoUI();

        // 3. Spawn viên đạn bay ra trong game
        Camera cam = Camera.main;
        if (cam == null) cam = FindObjectOfType<Camera>();

        if (cam != null)
        {
            Vector3 mousePosition = cam.ScreenToWorldPoint(Input.mousePosition);
            mousePosition.z = 0f;

            Vector3 spawnPosition = transform.TransformPoint(bulletOffset);
            Vector2 direction = (mousePosition - spawnPosition).normalized;

            float angle = Mathf.Atan2(direction.y, direction.x) * Mathf.Rad2Deg;
            Quaternion rotation = Quaternion.Euler(new Vector3(0, 0, angle));

            Instantiate(bulletPrefab, spawnPosition, rotation);
        }

        Debug.Log("Số sao hiện tại: " + GetCurrentStars());

        // 4. Nếu bắn hết sạch viên đạn cuối cùng (cả vàng lẫn xám) mà chưa thắng -> Kiểm tra điều kiện Thua sau một khoảng trễ nhỏ
        if (currentAmmoLeft <= 0)
        {
            StartCoroutine(CheckLoseConditionAfterDelay());
        }
    }

    // Hàm cập nhật hiển thị icon đạn trên UI (mất dần từ trái qua phải)
    private void UpdateAmmoUI()
    {
        for (int i = 0; i < bulletIcons.Count; i++)
        {
            if (bulletIcons[i] != null)
            {
                if (i < bulletsFired)
                {
                    bulletIcons[i].gameObject.SetActive(false); // Đã bắn -> Ẩn icon đi
                }
                else
                {
                    bulletIcons[i].gameObject.SetActive(true);  // Chưa bắn -> Hiện icon

                    if (i < maxGoldenBullets)
                    {
                        if (activeBulletSprite != null)
                            bulletIcons[i].sprite = activeBulletSprite;
                    }
                    else
                    {
                        if (greyBulletSprite != null)
                            bulletIcons[i].sprite = greyBulletSprite;
                    }
                }
            }
        }
    }

    // Hàm tính số sao người chơi đạt được dựa trên số đạn đã bắn
    // Hàm tính số sao người chơi đạt được dựa trên số đạn đã bắn
    public int GetCurrentStars()
    {
        if (bulletsFired <= maxGoldenBullets)
        {
            return 3; // Dùng trong hạn mức đạn vàng -> 3 sao tuyệt đối!
        }
        else if (bulletsFired == maxGoldenBullets + 1)
        {
            return 2; // Lẹm sang viên đạn xám thứ nhất -> 2 sao
        }
        else if (bulletsFired < totalMaxAmmo)
        {
            return 1; // Vẫn còn trước viên đạn xám cuối cùng -> 1 sao
        }
        else if (bulletsFired == totalMaxAmmo)
        {
            return 0; // Dùng đến viên đạn cuối cùng mới hạ gục được địch -> 0 sao (Vẫn tính là thắng!)
        }

        return 0;
    }

    // --- CÁC HÀM XỬ LÝ THẮNG / THUA (GỌI TỪ BÊN NGOÀI HOẶC KHI HẾT ĐẠN) ---


    // Gọi hàm này khi tiêu diệt hết kẻ địch trong màn
    public void TriggerWin()
    {
        if (isGameOver) return;
        isGameOver = true;

        int earnedStars = GetCurrentStars();
        Debug.Log("CHIẾN THẮNG! Đạt được: " + earnedStars + " sao.");

        // Ẩn tất cả trước, sau đó bật đúng Panel theo số sao đạt được
        HideAllPanels();

        switch (earnedStars)
        {
            case 3:
                if (panel3Stars != null) panel3Stars.SetActive(true);
                break;
            case 2:
                if (panel2Stars != null) panel2Stars.SetActive(true);
                break;
            case 1:
                if (panel1Star != null) panel1Star.SetActive(true);
                break;
            default:
                if (panel0StarsWin != null) panel0StarsWin.SetActive(true);
                break;
        }
    }

    // Đợi 1.5 giây sau khi bắn viên đạn cuối cùng xem địch đã chết chưa, nếu chưa thì hiện bảng Thua
    private IEnumerator CheckLoseConditionAfterDelay()
    {
        yield return new WaitForSeconds(1.5f);

        // Kiểm tra xem trong scene còn enemy nào mang tag "Enemy" không
        int remainingEnemies = GameObject.FindGameObjectsWithTag("Enemy").Length;

        if (remainingEnemies > 0 && !isGameOver)
        {
            TriggerLose();
        }
    }

    public void TriggerLose()
    {
        if (isGameOver) return;
        isGameOver = true;

        Debug.Log("THẤT BẠI! Hết đạn mà chưa tiêu diệt hết kẻ địch.");

        // Ẩn tất cả và chỉ bật Panel 0 sao (Thua)
        HideAllPanels();
        if (losePanel != null) losePanel.SetActive(true);
    }
    private void HideAllPanels()
    {
        if (panel3Stars != null) panel3Stars.SetActive(false);
        if (panel2Stars != null) panel2Stars.SetActive(false);
        if (panel1Star != null) panel1Star.SetActive(false);
        if (panel0StarsWin != null) panel0StarsWin.SetActive(false);
        if (losePanel != null) losePanel.SetActive(false);
    }
}