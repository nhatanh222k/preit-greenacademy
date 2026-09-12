// b10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void gtam(int n, int a[],int b[],int x) {
    int dem=0;
    for (int i = 0;i < n;i++) {
        if (a[i] < 0) {
            b[x] = a[i];
            x++;
            dem++;
        }
    }
    int tong = 0;
    for (int i = 0;i < x;i++) {
        tong = tong + b[i];
    }
    if (tong == 0) {
        cout << "0";
    }
    else {
        cout << "Gia tri trung binh cua cac phan tu co gia tri am la: " << float(tong) / dem;
    }
    
}
void gtduong(int n, int a[], int c[], int y) {
    int dem = 0;
    for (int i = 0;i < n;i++) {
        if (a[i] > 0) {
            c[y] = a[i];
            y++;
            dem++;
        }
    }
    int tong = 0;
    for (int i = 0;i < y;i++) {
        tong = tong + c[i];
    }
    if (tong == 0) {
        cout << "0";
    }
    else {
        cout << "\nGia tri trung binh cua cac phan tu co gia tri duong la: " << float(tong) / dem;
    }
}
void chanchia3(int n, int a[], int d[], int z) {
    int dem = 0;
    int tong = 0;
    for (int i = 0;i < n;i++) {
        if (a[i] % 2 == 0 && a[i] % 3 == 0) {
            d[z] = a[i];
            z++;
            dem++;
        }
    }
    for (int i = 0;i < z;i++) {
        tong = tong + d[i];
    }
    if (tong == 0) {
        cout << "0";
    }
    else {
        cout << "\nGia tri trung binh cua cac phan tu chan va chia het cho 3 la: " << float(tong) / dem;
    }
}
int main()
{
    int n,a[100];
    int b[100], x = 0;//khai bao cho chuoi gt duong
    int c[100], y = 0;//khai bao cho chuoi gt am
    int d[100], z = 0;
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
    gtam(n, a, b, x);
    gtduong(n, a, c, y);
    chanchia3(n, a, d, z);
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
