using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PlayerShooting : MonoBehaviour
{
    [Header("Shooting Settings")]
    [SerializeField] private GameObject bulletPrefab;
    [SerializeField] private Vector3 bulletOffset = new Vector3(0f, 0f, 0f);

    [Header("Ammo & Star Settings")]
    [SerializeField] private int maxGoldenBullets = 3;  // Số lượng đạn vàng (đạt 3 sao - ví dụ 3 viên đầu)
    [SerializeField] private int maxGreyBullets = 1;    // Số lượng đạn xám dự phòng thêm (ví dụ 1 viên cuối)

    private int totalMaxAmmo;       // Tổng số đạn (Vàng + Xám)
    private int currentAmmoLeft;    // Số đạn còn lại trong nòng
    private int bulletsFired = 0;   // Đếm số viên đã bắn ra

    [Header("UI Bullet Sprites")]
    [SerializeField] private Sprite activeBulletSprite;   // Hình viên đạn vàng (chuẩn 3 sao)
    [SerializeField] private Sprite greyBulletSprite;     // Hình viên đạn xám (đã bắn / đạn phụ bị trừ sao)
    [SerializeField] private List<Image> bulletIcons;     // Kéo thả toàn bộ UI Image hình viên đạn vào đây (từ trái qua phải)

    void Start()
    {
        totalMaxAmmo = maxGoldenBullets + maxGreyBullets;
        currentAmmoLeft = totalMaxAmmo;
        bulletsFired = 0;
        UpdateAmmoUI();
    }

    void Update()
    {
        // Bắn đạn ngay khi thả nút chuột trái
        if (Input.GetMouseButtonUp(0))
        {
            ShootBullet();
        }
    }

    private void ShootBullet()
    {
        // Nếu đã hết sạch cả đạn vàng lẫn đạn xám thì chặn không cho bắn
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

        // 2. Cập nhật lại giao diện UI
        UpdateAmmoUI();

        // 3. Spawn viên đạn bay ra trong game
        Camera cam = Camera.main;
        if (cam == null)
        {
            cam = FindObjectOfType<Camera>();
        }

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

        // Kiểm tra xem hiện tại người chơi đang được mấy sao
        Debug.Log("Số sao hiện tại: " + GetCurrentStars());
    }

    // Hàm cập nhật hiển thị icon đạn trên UI
    private void UpdateAmmoUI()
    {
        for (int i = 0; i < bulletIcons.Count; i++)
        {
            if (bulletIcons[i] != null)
            {
                // Nếu vị trí icon nhỏ hơn số viên đã bắn -> Biến mất (Ẩn đi)
                if (i < bulletsFired)
                {
                    bulletIcons[i].gameObject.SetActive(false); // Mất đi
                }
                else
                {
                    // Nếu chưa bắn -> Vẫn hiện lên
                    bulletIcons[i].gameObject.SetActive(true);

                    // Kiểm tra xem nên hiển thị icon vàng hay xám dựa trên giới hạn
                    if (i < maxGoldenBullets)
                    {
                        if (activeBulletSprite != null)
                            bulletIcons[i].sprite = activeBulletSprite; // Vẫn là đạn vàng
                    }
                    else
                    {
                        if (greyBulletSprite != null)
                            bulletIcons[i].sprite = greyBulletSprite;   // Là đạn xám dự phòng
                    }
                }
            }
        }
    }

    // Hàm tính số sao người chơi đạt được dựa trên số đạn đã bắn (Dùng cho màn hình Win)
    public int GetCurrentStars()
    {
        if (bulletsFired <= maxGoldenBullets)
        {
            return 3; // Dùng trong hạn mức đạn vàng -> Đạt 3 sao tuyệt đối!
        }
        else if (bulletsFired <= maxGoldenBullets + 1)
        {
            return 2; // Lẹm sang 1 viên đạn xám -> Còn 2 sao
        }
        else if (bulletsFired <= totalMaxAmmo)
        {
            return 1; // Dùng đến viên đạn xám cuối cùng -> Còn 1 sao
        }

        return 0; // Hết sạch đạn
    }
}