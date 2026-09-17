// b9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct maytinh {
    int mamay;
    int giovao[2]; // [0]: gio, [1]: phut
    int giora[2];  // [0]: gio, [1]: phut
    int trangthai; // 0: ranh, 1: ban
};
maytinh ds[12];
// Kiểm tra trạng thái máy: 1 (bận), 0 (rảnh)
int KiemTraTrangThai(int mamay) {
    for (int i = 0; i < 12; i++) {
        if (ds[i].mamay == mamay) {
            return ds[i].trangthai;
        }
    }
    return -1; // Không tìm thấy máy
}
// Mở khóa máy
void MoKhoaMay(int maMay) {
    if (KiemTraTrangThai(maMay) == 0) {
        for (int i = 0; i < 12; i++) {
            if (ds[i].mamay == maMay) {
                cout << "Nhap gio vao: ";
                cin >> ds[i].giovao[0];
                cout << "Nhap phut vao: ";
                cin >> ds[i].giovao[1];
                ds[i].trangthai = 1; // Chuyển sang bận
                cout << "Mo khoa may thanh cong!\n";
                return;
            }
        }
    }
    else {
        cout << "May hien da co khach. Vui long chon may khac.\n";
    }
}
// Tính tiền dịch vụ (10.000 VNĐ / giờ)
int TinhTien(int maMay) {
    for (int i = 0; i < 12; i++) {
        if (ds[i].mamay == maMay) {
            int tongPhutVao = ds[i].giovao[0] * 60 + ds[i].giovao[1];
            int tongPhutRa = ds[i].giora[0] * 60 + ds[i].giora[1];
            int thoiLuong = tongPhutRa - tongPhutVao;
            if (thoiLuong < 0) thoiLuong += 24 * 60; // Xử lý nếu chơi qua đêm
            int tien = thoiLuong * 10000 / 60;
            return tien;
        }
    }
    return 0;
}
// Khóa máy và tính tiền
void KhoaMay(int maMay) {
    if (KiemTraTrangThai(maMay) == 1) {
        for (int i = 0; i < 12; i++) {
            if (ds[i].mamay == maMay) {
                cout << "Nhap gio ra: ";
                cin >> ds[i].giora[0];
                cout << "Nhap phut ra: ";
                cin >> ds[i].giora[1];
                int tien = TinhTien(maMay);
                cout << "So tien can thanh toan: " << tien << " VND\n";
                // Reset giờ và trạng thái
                ds[i].giovao[0] = 0; ds[i].giovao[1] = 0;
                ds[i].giora[0] = 0;  ds[i].giora[1] = 0;
                ds[i].trangthai = 0; // Chuyển về rảnh

                cout << "May da duoc khoa!\n";
                return;
            }
        }
    }
    else {
        cout << "May hien khong co khach, khong the khoa may.\n";
    }
}
void TimMayRanh() {
    cout << "\n=== DANH SACH MAY RANH ===\n";
    bool coMayRanh = false;
    for (int i = 0; i < 12; i++) {
        if (ds[i].trangthai == 0) {
            cout << "PC" << setfill('0') << setw(2) << ds[i].mamay << " ";
            coMayRanh = true;
        }
    }
    if (!coMayRanh) cout << "Khong co may nao ranh!";
    cout << "\n";
}
void HienThiDS() {
    cout << "\n" << left
        << setw(12) << "Ma may"
        << setw(12) << "Gio vao"
        << setw(12) << "Gio ra"
        << "Trang thai" << endl;
    cout << "---------------------------------------------" << endl;
    for (int i = 0; i < 12; i++) {
        string maStr = string("PC") + (ds[i].mamay < 10 ? "0" : "") + to_string(ds[i].mamay);
        string gioVaoStr = (ds[i].giovao[0] < 10 ? "0" : "") + to_string(ds[i].giovao[0]) + ":" +
            (ds[i].giovao[1] < 10 ? "0" : "") + to_string(ds[i].giovao[1]);
        string gioRaStr = (ds[i].giora[0] < 10 ? "0" : "") + to_string(ds[i].giora[0]) + ":" +
            (ds[i].giora[1] < 10 ? "0" : "") + to_string(ds[i].giora[1]);
        string trangThaiStr = (ds[i].trangthai == 1) ? "Ban" : "Ranh";
        cout << left
            << setw(12) << maStr
            << setw(12) << gioVaoStr
            << setw(12) << gioRaStr
            << trangThaiStr << endl;
    }
}
int main() {
    // Khởi tạo thông tin 12 máy
    for (int i = 0; i < 12; i++) {
        ds[i].mamay = i + 1;
        ds[i].giovao[0] = 0; ds[i].giovao[1] = 0;
        ds[i].giora[0] = 0;  ds[i].giora[1] = 0;
        ds[i].trangthai = 0;
    }
    int luachon, maMay;
    do {
        cout << "\n================ MENU ================\n";
        cout << "1. Mo may\n";
        cout << "2. Khoa may\n";
        cout << "3. Hien thi danh sach phong may\n";
        cout << "4. Tim kiem may ranh\n";
        cout << "0. Thoat\n";
        cout << "======================================\n";
        cout << "Chon chuc nang: ";
        cin >> luachon;
        switch (luachon) {
        case 1:
            cout << "Nhap ma may (1-12): ";
            cin >> maMay;
            MoKhoaMay(maMay);
            break;
        case 2:
            cout << "Nhap ma may (1-12): ";
            cin >> maMay;
            KhoaMay(maMay);
            break;
        case 3:
            HienThiDS();
            break;
        case 4:
            TimMayRanh();
            break;
        case 0:
            cout << "Da thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai!\n";
        }
    } while (luachon != 0);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
