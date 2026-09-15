// b6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
struct tttp {
    char tenhang[51];
    char mahang[7];
    int soluong;
    int dongia;
};
int slhang;
tttp danhsach[100];
void nhaphang() {
    cin.ignore();
    for (int i = 0;i < slhang;i++) {
        cout << "Nhap ten mat hang: ";
        cin.getline(danhsach[i].tenhang, 51);
        cout << "Nhap ma mat hang: ";
        cin.getline(danhsach[i].mahang, 7);
        cout << "nhap vao so luong hang trong kho: ";
        cin >> danhsach[i].soluong;
        cout << "Nhap vao don gia: ";
        cin >> danhsach[i].dongia;
    }
}
void xemttsp() {
    cout << left
        << setw(20) << "Ten hang hoa"
        << setw(14) << "Ma hang"
        << setw(14) << "So luong"
        << setw(14) << "Don gia";
    for (int i = 0;i < slhang;i++) {
        cout << left
            << setw(20) << danhsach[i].tenhang
            << setw(14) << danhsach[i].mahang
            << setw(14) << danhsach[i].soluong
            << setw(14) << danhsach[i].dongia;
    }
}
void timsp() {
    char ma[7];
    cout << "Nhap ma hang can tim: ";
    cin.getline(ma, 7);
    bool timThay = false;
    for (int i = 0;i<slhang;i++) {
        if (strcmp(ma, danhsach[i].mahang) == 0) {
            cout
                << "Ten hang:" << danhsach[i].tenhang
                << "\tMa hang" << danhsach[i].mahang
                << "\tSo luong:" << danhsach[i].soluong
                << "\tDon gia:" << danhsach[i].dongia;
            timThay = true;
        }
    }
    if (!timThay) {
        cout << "Không tìm thấy" << endl;
    }
}
void muahang() {
    char ma[7];
    int slMua;
    cout << "Nhap ma hang can mua: ";
    cin.getline(ma, 7);
    cout << "Nhap so luong mua: ";
    cin >> slMua;
    cin.ignore();
    bool timThay = false;
    for (int i = 0; i < slhang; i++) {
        if (strcmp(ma, danhsach[i].mahang) == 0) {
            timThay = true; 
            if (slMua > danhsach[i].soluong) {
                cout << "Không đủ hàng" << endl;
            }
            else {
                danhsach[i].soluong -= slMua;
                cout << "Mua hang thanh cong!" << endl;
                cout << "San pham: " << danhsach[i].tenhang
                    << " | So luong con lai: " << danhsach[i].soluong << endl;
            }
            break;
        }
    }
    if (!timThay) {
        cout << "Không tìm thấy" << endl;
    }
}
int main()
{
    int a;
    char lc;
    cout << "Nhap so luong don hang: ";
    cin >> slhang;
    nhaphang();
    do {
        cout << "\nChon chuc nang: ";
        cout << "\n1. Xem thong tin san pham dang co";
        cout << "\n2. Tim san pham theo ma hang";
        cout << "\n3. Mua hang";
        cout << "\nChon chuc nang: ";
        cin >> a;
        cin.ignore();
        switch (a) {
        case 1: xemttsp(); break;
        case 2: timsp(); break;
        case 3: muahang(); break;
        default: cout << "Chuc nang khong hop le!" << endl;
        }

        cout << "\nBan co muon tiep tuc khong? (y/n): ";
        cin >> lc;
        cin.ignore(); // Xóa bộ đệm trước khi lặp lại vòng mới

    } while (lc == 'y' || lc == 'Y');
    
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
