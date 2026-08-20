// b6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int x, n;
    float a, tong1 = 0,tong2 = 0,b, mau = 1;
    cout << "Nhap vao lan luot so nguyen x va n: ";
    cin >> x >> n;
    //pt1
    for (float i = 1;i <= n;i++) {
        a = x / i;
        tong1 = tong1 + a;
    }
    cout << "Ket qua cua phep tinh 1 la: " << tong1;
    //pt2
    for (int a = 1;a <= n;a++) {
        int giaithua = 1;
        for (float i = 1;i <= a;i++) {
            giaithua = giaithua * i;
        }
        mau = mau * x;
        b = giaithua / mau;
        tong2 = tong2 + b;
    }
    cout << "\nKet qua cua phep tinh 2 la: " << tong2;
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
