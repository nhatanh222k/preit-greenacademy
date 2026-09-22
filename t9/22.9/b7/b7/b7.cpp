// b7.cpp : Read and search reservation schedule
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct LICHHEN {
    string maban;
    int sokhach;
    string ten;
    int giodatban[2];
    int ngaydatban[3];
};

LICHHEN dsach[50];
int SoLuongLichHen = 0;

void doc_tung_dong(ifstream& file) {
    char rac;
    getline(file >> ws, dsach[SoLuongLichHen].maban, '|');

    // Đọc số khách
    file >> dsach[SoLuongLichHen].sokhach >> rac; // Đọc số khách và dấu '|'

    // Đọc giờ (Giờ:Phút|)
    file >> dsach[SoLuongLichHen].giodatban[0] >> rac; // GIỜ và dấu ':'
    file >> dsach[SoLuongLichHen].giodatban[1] >> rac; // PHÚT và dấu '|'

    // Đọc ngày (Ngày/Tháng/Năm|)
    file >> dsach[SoLuongLichHen].ngaydatban[0] >> rac; // NGÀY và dấu '/'
    file >> dsach[SoLuongLichHen].ngaydatban[1] >> rac; // THÁNG và dấu '/'
    file >> dsach[SoLuongLichHen].ngaydatban[2] >> rac; // NĂM và dấu '|'

    // Bỏ qua khoảng trắng thừa sau dấu '|' trước khi đọc Tên (nếu có)
    file >> ws;

    // Đọc tên khách hàng đến hết dòng
    getline(file, dsach[SoLuongLichHen].ten);

    // Xóa '\r' nếu file lưu theo định dạng Windows (CRLF)
    if (!dsach[SoLuongLichHen].ten.empty() && dsach[SoLuongLichHen].ten.back() == '\r') {
        dsach[SoLuongLichHen].ten.pop_back();
    }

    SoLuongLichHen++;
}

void docfile() {
    ifstream file("thongtindatban.txt");
    if (!file.is_open()) {
        cout << "Loi! Khong the mo file thongtindatban.txt\n";
        return;
    }

    int n;
    if (file >> n) {
        for (int i = 0; i < n && SoLuongLichHen < 50; i++) {
            doc_tung_dong(file);
        }
    }

    file.close();
    cout << "\nDoc file thanh cong! Da luu " << SoLuongLichHen << " lich hen.\n\n";
}

string TimLichHen(string tenkhach, int songuoidicung, int ngaydat[3], int giodat[2]) {
    int tongSoNguoi = songuoidicung + 1; // Khách + người đi cùng

    for (int i = 0; i < SoLuongLichHen; i++) {
        if (tenkhach == dsach[i].ten &&
            tongSoNguoi == dsach[i].sokhach &&
            ngaydat[0] == dsach[i].ngaydatban[0] &&
            ngaydat[1] == dsach[i].ngaydatban[1] &&
            ngaydat[2] == dsach[i].ngaydatban[2] &&
            giodat[0] == dsach[i].giodatban[0] &&
            giodat[1] == dsach[i].giodatban[1]) {

            return dsach[i].maban;
        }
    }

    return "Khong tim thay";
}

int main() {
    docfile();

    string tenkhach;
    int songuoidicung;
    int ngaydat[3];
    int giodat[2];

    cout << "Nhap ten khach: ";
    getline(cin, tenkhach);

    cout << "So nguoi di cung: ";
    cin >> songuoidicung;

    cout << "Nhap ngay dat (ngay thang nam): ";
    cin >> ngaydat[0] >> ngaydat[1] >> ngaydat[2];

    cout << "Nhap gio dat (gio phut): ";
    cin >> giodat[0] >> giodat[1];

    string ketQua = TimLichHen(tenkhach, songuoidicung, ngaydat, giodat);
    cout << "\nKet qua tim kiem - Ma ban: " << ketQua << endl;

    return 0;
}