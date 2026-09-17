// b10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<iomanip>
using namespace std;
struct PHONGHOC {
    char MaPH[6];
    char LoaiPH[2];
    int SL;
    int TT;
};
PHONGHOC dsph[50];
int SoLuongPH = 0;
int KiemTraMaPhong(char maphong[]) {
    for (int i = 0;i < SoLuongPH;i++) {
        if (strcmp(dsph[i].MaPH, maphong) == 0) {
            return 1;
        }
    }
    return 0;
}
void TaoPhongHoc(PHONGHOC& ph) {
    do {
        cout << "Nhap ma phong hoc: ";
        cin >> ph.MaPH;
        if (KiemTraMaPhong(ph.MaPH)==1) {
            cout << "Ma phong da ton tai! Nhap ma khac!\n";
        }
        else {
            break;
        }
    } while (true);
    do {
        cout << "Nhap loai phong hoc( LT/TH ): ";
        cin >> ph.LoaiPH;
        if (strcmp(ph.LoaiPH, "LT") == 0 || strcmp(ph.LoaiPH, "TH") == 0) {
            break;
        }
        else {
            cout << "Loai phong chi duoc la 'LT' hoac 'TH'. Nhap lai!\n";
        }
    } while (true);
    do {
        cout << "  - Nhap so luong cho ngoi: ";
        cin >> ph.SL;

        if (ph.SL >= 0) {
            break;
        }
        else {
            cout << "So luong cho ngoi phai lon hon hoac bang 0. Nhap lai!\n";
        }
    } while (true);
    int tinhTrang;
    do {
        cout << "Nhap tinh trang (0: Ranh, 1: Ban): ";
        cin >> tinhTrang;
        if (tinhTrang == 0 || tinhTrang == 1) {
            ph.TT = (tinhTrang == 1);
            break;
        }
        else {
            cout << "Tinh trang chi nhap 0 hoac 1!\n";
        }
    } while (true);
}
void TaoCacPhongHoc() {

}
int main()
{
  
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
