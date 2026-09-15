// b7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct tttk {
    char Matk[13];
    char Tentk[51];
    int Sodu;
};
tttk dsTK[10];
int soLuongTK = 0;
int TraCuuTK(char ma[])
{
    for (int i = 0; i < soLuongTK; i++)
    {
        if (strcmp(dsTK[i].Matk, ma) == 0)
        {
            return i;
        }
    }
    return -1;
}
void TaoTaiKhoan()
{
    if (soLuongTK >= 10)
    {
        cout << "Danh sach tai khoan da day!\n";
        return;
    }
    cout << "\nTAO TAI KHOAN\n";
    do
    {
        cout << "Nhap ma tai khoan (12 chu so): ";
        cin >> dsTK[soLuongTK].Matk;
        if (strlen(dsTK[soLuongTK].Matk) != 12)
        {
            cout << "Ma tai khoan phai co dung 12 chu so!\n";
        }
        else if (TraCuuTK(dsTK[soLuongTK].Matk) != -1)
        {
            cout << "Ma tai khoan da ton tai!\n";
        }
        else
        {
            break;
        }
    } while (true);
    cin.ignore();
    cout << "Nhap ten tai khoan: ";
    cin.getline(dsTK[soLuongTK].Tentk, 51);
    do
    {
        cout << "Nhap so du: ";
        cin >> dsTK[soLuongTK].Sodu;
        if (dsTK[soLuongTK].Sodu < 0)
        {
            cout << "So du khong duoc am!\n";
        }
    } while (dsTK[soLuongTK].Sodu < 0);
    soLuongTK++;
    cout << "Tao tai khoan thanh cong!\n";
}
void TimTK()
{
    char ma[13];
    cout << "\nTim tai khoan\n";
    cout << "Nhap ma tai khoan can tim: ";
    cin >> ma;
    int vt = TraCuuTK(ma);
    if (vt != -1)
    {
        cout << "\nTHONG TIN TAI KHOAN\n";
        cout << "Ma tai khoan : " << dsTK[vt].Matk << endl;
        cout << "Ten tai khoan: " << dsTK[vt].Tentk << endl;
        cout << "So du        : " << dsTK[vt].Sodu << endl;
    }
    else
    {
        cout << "Tai khoan khong tim thay!\n";
    }
}
void ChuyenKhoan()
{
    char maChuyen[13];
    char maNhan[13];
    cout << "\nCHUYEN KHOAN\n";
    cout << "Nhap ma tai khoan chuyen: ";
    cin >> maChuyen;
    int vtChuyen = TraCuuTK(maChuyen);
    if (vtChuyen == -1)
    {
        cout << "Tai khoan chuyen khong tim thay!\n";
        return;
    }
    cout << "Nhap ma tai khoan nhan: ";
    cin >> maNhan;
    int vtNhan = TraCuuTK(maNhan);
    if (vtNhan == -1)
    {
        cout << "Tai khoan nhan khong tim thay!\n";
        return;
    }
    if (vtChuyen == vtNhan)
    {
        cout << "Khong the chuyen tien cho chinh tai khoan!\n";
        return;
    }
    int tien;
    do
    {
        cout << "Nhap so tien muon chuyen: ";
        cin >> tien;
        if (tien <= 0)
        {
            cout << "So tien phai lon hon 0!\n";
        }
        else if (tien > dsTK[vtChuyen].Sodu)
        {
            cout << "So du khong du de chuyen!\n";
        }

    } while (tien <= 0 || tien > dsTK[vtChuyen].Sodu);
    dsTK[vtChuyen].Sodu -= tien;
    dsTK[vtNhan].Sodu += tien;
    cout << "\nChuyen khoan thanh cong!\n";
    cout << "Tai khoan chuyen: " << dsTK[vtChuyen].Matk << endl;
    cout << "Tai khoan nhan  : " << dsTK[vtNhan].Matk << endl;
    cout << "So tien         : " << tien << endl;
    cout << "So du con lai   : " << dsTK[vtChuyen].Sodu << endl;
}
void Menu()
{
    cout << "\n====================================\n";
    cout << "       CHUONG TRINH NGAN HANG\n";
    cout << "====================================\n";
    cout << "1. Dang ky tai khoan ngan hang\n";
    cout << "2. Xem thong tin so du tai khoan\n";
    cout << "3. Chuyen khoan\n";
    cout << "0. Thoat\n";
    cout << "====================================\n";
    cout << "Nhap lua chon: ";
}
int main()
{
    int chon;
    do
    {
        Menu();
        cin >> chon;
        switch (chon)
        {
        case 1:
            TaoTaiKhoan();
            break;
        case 2:
            TimTK();
            break;
        case 3:
            ChuyenKhoan();
            break;
        case 0:
            cout << "Ket thuc chuong trinh!\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (chon != 0);
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
