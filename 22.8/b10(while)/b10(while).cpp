// b10(while).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int a, b, n, tong = 0;

    cout << "Nhap lan luot 3 so nguyen a,b,n(a,b<n): ";
    cin >> a >> b >> n;

    if (a >= n || b >= n) {
        cout << "Nhap vao khong hop le";
    }
    else {
        int i = 1;

        while (i < n) {
            if (i % a == 0 && i % b != 0) {
                tong = tong + i;
            }

            i++;
        }

        cout << "Tong cac so nho hon n chia het cho a nhung khong chia het cho b la: " << tong;
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
