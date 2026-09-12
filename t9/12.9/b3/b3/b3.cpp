// b3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
struct ttsv {
    char MaSV[7];
    char HoTen[51];
    char Lop[7];
    float toan, van, tin;
    float dtb;
    string xl;
};
int main()
{
    ttsv dssv[100];
    int a;
    string x;
    int gioi = 0, kha = 0, tb = 0, yeu = 0, kem = 0;
    cout << "Nhap vao so luong sinh vien can luu tru: " << endl;
    cin >> a;
    cin.ignore();
    for (int i = 0;i < a;i++) {
        cout << "Sinh vien thu " << i+1 << ": \n";
        cout << "Nhap MSSV: ";
        cin.getline(dssv[i].MaSV, 7);
        cout << "Nhap Ho va ten: ";
        cin.getline(dssv[i].HoTen, 51);
        cout << "Nhap Lop: ";
        cin.getline(dssv[i].Lop, 7);
        cout << "Nhap diem toan: ";
        cin >> dssv[i].toan;
        cout << "Nhap diem van: ";
        cin >> dssv[i].van;
        cout << "Nhap diem tin: ";
        cin >> dssv[i].tin;
        cin.ignore();
        dssv[i].dtb = (dssv[i].toan + dssv[i].van + dssv[i].tin) / 3;
        if (dssv[i].dtb >= 8) {
            dssv[i].xl = "Gioi";
            gioi++;
        }
        else if (dssv[i].dtb >= 6.5 && dssv[i].dtb < 8) {
            dssv[i].xl = "Kha";
            kha++;
        }
        else if (dssv[i].dtb >= 5 && dssv[i].dtb < 6.5) {
            dssv[i].xl = "Trung binh";
            tb++;
        }
        else if (dssv[i].dtb >= 3.5 && dssv[i].dtb < 5) {
            dssv[i].xl = "Yeu";
            yeu++;
        }
        else if (dssv[i].dtb < 3.5) {
            dssv[i].xl = "Kem";
            kem++;
        }
    }
    cout<<left
        << setw(7) << "MSSV"
        << setw(18) << "Ho ten"
        << setw(7) << "Lop"
        << setw(5) << "Toan"
        << setw(5) << "Van"
        << setw(5) << "Tin"
        << setw(5) << "DTB"
        << setw(10) << "Xep loai" << endl;
    for (int i = 0;i < a;i++) {
        cout << left
            << setw(7) << dssv[i].MaSV
            << setw(18) << dssv[i].HoTen
            << setw(7) << dssv[i].Lop
            << setw(5) << dssv[i].toan
            << setw(5) << dssv[i].van
            << setw(5) << dssv[i].tin
            << setw(5) << fixed << setprecision(1) << dssv[i].dtb
            << setw(10) << dssv[i].xl << endl;
    }
    cout << "So hoc sinh Gioi la: " << gioi
        << "\nSo hoc sinh Kha la: " << kha
        << "\nSo hoc sinh Trung binh la: " << tb
        << "\nSo hoc sinh Yeu la: " << yeu
        << "\nSo hoc sinh Kem la: " << kem << endl;
    cout << "Nhap vao MSSV: ";
    getline(cin, x);
    cout << "Thong tin sinh vien can tim la: ";
    for (int i = 0;i < a;i++) {
        if (string(dssv[i].MaSV) == x) {
            cout << left
                << setw(7) << dssv[i].MaSV
                << setw(18) << dssv[i].HoTen
                << setw(7) << dssv[i].Lop
                << setw(5) << dssv[i].toan
                << setw(5) << dssv[i].van
                << setw(5) << dssv[i].tin
                << setw(5) << fixed << setprecision(1) << dssv[i].dtb
                << setw(10) << dssv[i].xl << endl;
        }
    }
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
