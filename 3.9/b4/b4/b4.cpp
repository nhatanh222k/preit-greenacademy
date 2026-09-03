// b4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int KiemTraSNT(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2;i * i <= n;i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
void LietKeSNT(int n) {
    cout << "Cac so nguyen to nho hon N la: ";
    for (int i = 2;i < n;i++) {
        if (KiemTraSNT(i) == 1) {
            cout << i << " ";
        }
    }
}
int main()
{
    int n;
    cout << "Nhap vao 1 so n: ";
    cin >> n;
    int kq = KiemTraSNT(n);
    if (kq == 0) {
        cout << "N ko phai la so nguyen to";
    }
    else if (kq == 1) {
        cout << "N la so nguyen to\n";
        LietKeSNT(n);
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
