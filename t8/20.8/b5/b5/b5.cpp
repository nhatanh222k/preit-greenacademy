// b5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int n,giaithua=1;
    int tong=0;
    cout << "Nhap so nguyen n: ";
    cin >> n;
    //giai thua
    for (int i = n;i > 0;i--) {
        giaithua = giaithua * i;
    }
    cout << "Giai thua cua " << n << " la: " << giaithua;
    //tong giai thua tu 1 den N
    for (int a = 1;a <= n;a++) {
        int tich = 1;
        for (int i = 1;i <= a;i++) {
            tich = tich * i;
        }
        tong = tong + tich;
    }
    cout << "\nTong cac giai thua tu 1 den " << n << " la: " << tong;
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
