// b1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d, e;
    //pb1
    cout << "Nhap nhiet do soi cua nuoc: ";
    cin >> a;
    if (a >= 100) {
        cout << "Nuoc soi";
    }
    else {
        cout << "Nuoc chua du nhiet do";
    }
    //pb2
    cout << "\nNhap so tien tiet kiem: ";
    cin >> b;
    if (b >= 40000000) {
        cout << "Du tien mua xe";
    }
    else {
        cout << "Chua du tien mua xe";
    }
    //pb3
    cout << "\nHom nay la thu 7 dung khong? (1:co/0:khong)";
    cin >> c;
    if (c == 1) {
        cout << "duoc nghi";
    }
    else if (c == 0) {
        cout << "Hom nay la chu nhat dung khong? (1:co/0:khong)";
        cin >> c;
        if (c == 1) {
            cout << "duoc nghi";
        }
        else if (c == 0) {
            cout << "Hom nay la ngay le dung khong? (1:co/0:khong)";
            cin >> c;
            if (c == 1) {
                cout << "duoc nghi";
            }
            else if (c == 0) {
                cout << "Den truong";
            }
            else {
                cout << "Nhap vao khong hop le";
            }
        }
        else {
            cout << "Nhap vao khong hop le";
        }
    }
    else {
        cout << "Nhap vao khong hop le";
    }
    //pb4
    cout << "\nNhap vao lan luot so buoi nghi va so buoi di tre: ";
    cin >> d >> e;
    if (d >= 4 || (d < 2 && e>4)) {
        cout << "Cam thi";
    }
    else {
        cout << "Du dieu kien thi";
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
