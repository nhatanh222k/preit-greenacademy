// b13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int TimvsXoa(int &n, int a[], int x) {
    bool timthay = false;
    for (int i = 0;i < n;i++) {
        if (a[i] == x) {
            timthay = true;
            for (int j = i;j < n - 1;j++) {
                a[j] = a[j + 1];
            }
            i--;
            n--;
        }
    }
    if (timthay == false) {
        return -1;
    }
    return 0;
}
int main()
{
    int n, a[100],x;
    cout << "Nhap vao so phan tu cua mang a: ";
    cin >> n;
    cout << "Nhap vao gia tri cac phan tu co trong a: ";
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    cout << "Nhap vao phan tu x can xoa: ";
    cin >> x;
    int kq = TimvsXoa(n, a, x);
    if (kq == -1) {
        cout << "Mang khong ton tai phan tu x";
    }
    else {
        cout << "Mang sau khi xoa phan tu x la: ";
        for (int i = 0;i < n;i++) {
            cout << a[i] << " ";
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
