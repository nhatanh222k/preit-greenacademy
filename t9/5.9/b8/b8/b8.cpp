// b8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
float DienTichHinhTron(float r) {
    float S;
    S = r * r * 3.14;
    return S;
}
float ChuViHinhTron(float r) {
    float V;
    V = 2 * r * 3.14;
    return V;
}
float DienTichHinhVuong(int c) {
    float S;
    S = c * c;
    return S;
}
float ChuViHinhVuong(int c) {
    float V;
    V = 4 * c;
    return V;
}
float DienTichHCN(int a, int b) {
    float S;
    S = a * b;
    return S;
}
float ChuViHCN(int a, int b) {
    float V;
    V = ( a + b ) * 2;
    return V;
}
void XuatKetQua(int x, float S, float V) {
    if (x == 1) {
        cout << "Dien tich hinh tron la: " << S;
        cout << "\nChu vi hinh tron la: " << V;
    }
    else if (x == 2) {
        cout << "Dien tich hinh vuong la: " << S;
        cout << "\nChu vi hinh vuong la: " << V;
    }
    else if (x == 3) {
        cout << "Dien tich hinh chu nhat la: " << S;
        cout << "\nChu vi hinh chu nhat la: " << V;
    }
}
int main()
{
    int x,c,a,b;
    float r,S,V;
    cout << "Chon hinh: \n";
    cout << "1.Hinh tron\n";
    cout << "2.Hinh vuong\n";
    cout << "3.Hinh chu nhat\n";
    cin >> x;
    switch (x) {
    case 1:cout << "Nhap vao ban kinh: ";
        cin>>r;
        S=DienTichHinhTron(r);
        V=ChuViHinhTron(r);
        break;
    case 2:cout << "Nhap vao canh: ";
        cin >> c;
        S=DienTichHinhVuong(c);
        V=ChuViHinhVuong(c);
        break;
    case 3:cout<<"Nhap canh a va b: ";
        cin >> a >> b;
        S=DienTichHCN(a, b);
        V=ChuViHCN(a, b);
        break;
    }
    XuatKetQua(x, S, V);
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
