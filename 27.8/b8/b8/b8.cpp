// b8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void Ptmax(int n, int a[]) {
    int max=a[0];
    for (int i = 1;i < n;i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    cout << max;
}
void Ptmin(int n, int a[]) {
    int min = a[0];
    for (int i = 1;i < n;i++) {
        if (min > a[i]) {
            min = a[i];
        }
    }
    cout << min;
}
void Posf(int n, int a[],int x) {
    cout << "Vi tri dau tien so x xuat hien trong mang la: ";
    for (int i = 0;i < n;i++) {
        if (a[i] == x) {
            cout << i+1;
            break;
        }
    }
}
void Posl(int n, int a[], int x) {
    cout << "\nVi tri cuoi cung so x xuat hien trong mang la: ";
    for (int i = n-1;i >= 0;i--) {
        if (a[i] == x) {
            cout << i+1;
            break;
        }
    }
}
void Dempt(int n, int a[], int x,int dem) {
    for (int i = 0;i < n;i++) {
        if (a[i] == x) {
            dem++;
        }
    }
    cout << "\nSo la xuat hien cua phan tu x la: " << dem;
}
int main()
{
    int n;
    int a[100];
    int x;
    int dem=0;
    cout << "Nhap vao so luong phan tu cua mang: ";
    cin >> n;
    while (n < 1 || n > 100) {
        cout << "Nhap lai so luong phan tu cua mang(1<=n<=100): ";
        cin >> n;
    }
    
    cout << "Nhap vao lan luot cac phan tu trong mang: ";
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    cout << "Phan tu co gia tri lon nhat trong mang la: ";
    Ptmax(n, a);
    cout << "\nPhan tu co gia tri nho nhat trong mang la: ";
    Ptmin(n, a);
    cout << "\nNhap vao 1 so x co trong mang: ";
    cin >> x;
    Posf(n, a, x);
    Posl(n, a, x);
    Dempt(n, a, x, dem);
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
