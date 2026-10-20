using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HealthBar : MonoBehaviour
{
    public RectTransform mask;
    public Health health;

    private float originalWidth;

    void Start()
    {
        if (mask != null)
        {
            originalWidth = mask.sizeDelta.x;
        }

        if (health != null)
        {
            // Đăng ký nhận sự kiện khi máu thay đổi
            health.onHealthChanged += UpdateHealthValue;

            // Cập nhật giá trị thanh máu ngay khi bắt đầu
            UpdateHealthValue();
        }
    }

    private void OnDestroy()
    {
        // Hủy đăng ký sự kiện khi đối tượng bị hủy để tránh lỗi bộ nhớ (Memory Leak)
        if (health != null)
        {
            health.onHealthChanged -= UpdateHealthValue;
        }
    }

    private void UpdateHealthValue()
    {
        if (health == null || mask == null) return;

        // Tính tỷ lệ máu từ biến defaultHealthPoint và hàm GetCurrentHealthPoint()
        float scale = (float)health.GetCurrentHealthPoint() / health.defaultHealthPoint;

        // Cập nhật lại chiều rộng của khung mask
        mask.sizeDelta = new Vector2(scale * originalWidth, mask.sizeDelta.y);
    }
}