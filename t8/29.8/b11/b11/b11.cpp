// b11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void Sxmang(int n, int a[]) {
    for (int i = 0;i < n - 1;i++) {
        for (int j = 0;j < n - i - 1;j++) {
            if (a[j] > a[j + 1]) {
                int tg = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tg;
            }
        }
    }
    for (int i = 0;i < n;i++) {
        cout << a[i] << " ";
    }
}
void Themx(int n, int a[], int x) {
    int vt=n;
    for (int i = 0;i < n;i++) {
        if (a[i] > x) {
            vt = i;
            break;
        }
    }
    for (int i = n;i > vt;i--) {
        a[i] = a[i - 1];
    }
    a[vt] = x;
    n++;
    for (int i = 0;i < n;i++) {
        cout << a[i] << " ";
    }
}
int main()
{
    int n,x;
    int a[100];
    cout << "Nhap vao so phan tu co trong mang a: ";
    cin >> n;
    cout << "Nhap vao mang a: ";
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    Sxmang(n, a);
    cout << "\nNhap vao so x can chen: ";
    cin >> x;
    cout << "Mang a sau khi chen them phan tu la: ";
    Themx(n, a, x);
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
