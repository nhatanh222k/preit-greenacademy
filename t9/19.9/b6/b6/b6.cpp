// b6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Cấu trúc lưu thông tin của một lớp học
struct LopHoc {
    string chiNhanh;
    string monHoc;
    string buoiHoc;
    string gioHoc;
    string phong;
};
// Hàm giải mã một mã lớp chỉ dùng các thao tác cơ bản
LopHoc giaiMaLopHoc(string maLop) {
    LopHoc lh;
    // 1. Giải mã Chi nhánh (2 ký tự đầu)
    if (maLop[0] == 'K' && maLop[1] == 'T') {
        lh.chiNhanh = "Khang Thong";
    }
    else if (maLop[0] == 'T' && maLop[1] == 'B') {
        lh.chiNhanh = "Tan Binh";
    }
    // Tìm vị trí của 2 dấu gạch nối '-'
    int gach1 = -1;
    int gach2 = -1;
    for (int i = 0; i < maLop.length(); i++) {
        if (maLop[i] == '-') {
            if (gach1 == -1) {
                gach1 = i;
            }
            else {
                gach2 = i;
                break;
            }
        }
    }
    // 2. Giải mã Môn học (nằm giữa gach1 và gach2)
    string codeMon = "";
    for (int i = gach1 + 1; i < gach2; i++) {
        codeMon += maLop[i];
    }
    if (codeMon == "CDEV") {
        lh.monHoc = "C Developer";
    }
    else if (codeMon == "FDEV") {
        lh.monHoc = "Fullstack Developer";
    }
    else if (codeMon == "JDEV") {
        lh.monHoc = "Java Developer";
    }
    else if (codeMon == "WDEV") {
        lh.monHoc = "Web Design";
    }
    // 3. Giải mã Giờ học (ký tự ngay sau gach2)
    char codeGio = maLop[gach2 + 1];
    if (codeGio == 'A') {
        lh.gioHoc = "09:00-12:00";
    }
    else if (codeGio == 'B') {
        lh.gioHoc = "13:00-16:00";
    }
    else if (codeGio == 'C') {
        lh.gioHoc = "18:30-21:30";
    }
    // 4. Giải mã Buổi học (ký tự tiếp theo)
    char codeNgay = maLop[gach2 + 2];
    if (codeNgay == 'C') {
        lh.buoiHoc = "T2/T4/T6";
    }
    else if (codeNgay == 'L') {
        lh.buoiHoc = "T3/T5/T7";
    }
    // 5. Giải mã Số phòng (các ký tự số từ vị trí gach2 + 3 đến hết)
    lh.phong = "";
    for (int i = gach2 + 3; i < maLop.length(); i++) {
        lh.phong += maLop[i];
    }
    return lh;
}
int main() {
    ifstream fileInput("ma_lop.txt");
    if (!fileInput.is_open()) {
        cout << "Khong the mo file!" << endl;
        return 1;
    }
    int n;
    fileInput >> n;
    LopHoc* dsLopHoc = new LopHoc[n];
    string maLop;

    for (int i = 0; i < n; i++) {
        fileInput >> maLop;
        dsLopHoc[i] = giaiMaLopHoc(maLop);
    }
    fileInput.close();
    cout << left
        << setw(18) << "Chi nhanh"
        << setw(24) << "Mon hoc"
        << setw(12) << "Buoi hoc"
        << setw(16) << "Gio hoc"
        << right << setw(6) << "Phong" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    
    for (int i = 0; i < n; i++) {
        cout << left
            << setw(18) << dsLopHoc[i].chiNhanh
            << setw(24) << dsLopHoc[i].monHoc
            << setw(12) << dsLopHoc[i].buoiHoc
            << setw(16) << dsLopHoc[i].gioHoc
            << right << setw(6) << dsLopHoc[i].phong << endl;
    }
    delete[] dsLopHoc;
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
