// b7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<conio.h>
using namespace std;
int main()
{
    int a, b, c;
    cout << "Nhap so luong bang cassette: ";
    cin >> a;
    cout << "Nhap so luong bang video: ";
    cin >> b;
    cout << "Nhap so luong dia VCD: ";
    cin >> c;
    int ga, gb, gc, datcoc=0;
    ga = a * 1000;
    gb = b * 5000;
    gc = c * 10000;
    if (a != 0) {
        datcoc = datcoc + 10000;
    }
    if (b != 0) {
        datcoc = datcoc + 50000;
    }
    if (c != 0) {
        datcoc = datcoc + 100000;
    }
    float tgian;
    tgian = (a * 0.5) + (b * 3) + (c * 5);
    cout << "\t\t\tBIEN LAI THU TIEN BANG GIA\n";
    cout << "======================================================================\n";
    cout << "\t Loai bang\t          So luong \t       Gia tien\n";
    cout << "\t Bang cassette\t\t         " << a << "\t\t" << ga << " VND\n";
    cout << "\t Bang tu video\t\t         " << b << "\t\t" << gb << " VND\n";
    cout << "\t Dia VCD\t\t         " << c << "\t\t" << gc << " VND\n";
    cout << "\t Phi dat coc\t\t\t\t\t"<<datcoc<<" VND\n";
    cout << "======================================================================\n";
    cout << "Tong so tien phai tra: " << datcoc + ga + gb + gc<<" VND\n";
    cout << "Ban duoc thue trong thoi gian la " << tgian << " ngay.";
    _getch();
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
