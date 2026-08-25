// b5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void NhapMang(int &SoLuong, int Arr[]) {
    cout << "Nhap vao so luong phan tu: ";
    cin >> SoLuong;
    while (SoLuong < 1 || SoLuong > 20) {
        cout << "Nhap lai so luong phan tu: ";
        cin >> SoLuong;
    }
    cout << "Nhap vao cac phan thu: ";
    for (int i = 0;i < SoLuong;i++) {
        cin >> Arr[i];
    }
}
void XuatMang(int SoLuong, int Arr[]) {
    for (int i = 0;i < SoLuong;i++) {
        cout << Arr[i]<<" ";
    }
}
void HoanVi(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}
void BubbleSort(int SoLuong, int Arr[]) {
    for (int i = 0;i < SoLuong-1;i++) {
        for(int j = 0;j < SoLuong - 1 - i;j++) {
            if (Arr[j] > Arr[j + 1]) {
                HoanVi(Arr[j], Arr[j + 1]);
            }
        }
    }
}
void SelectionSort(int SoLuong, int Arr[]) {
    for (int i = 0;i < SoLuong - 1;i++) {
        for (int j = 0;j < SoLuong - 1 - i;j++) {
            if (Arr[j] < Arr[j + 1]) {
                HoanVi(Arr[j], Arr[j + 1]);
            }
        }
    }
}
int main()
{
    int SoLuong;
    int Arr[20];
    NhapMang(SoLuong, Arr);
    cout << "Mang vua nhap vao la: ";
    XuatMang(SoLuong, Arr);
    BubbleSort(SoLuong, Arr);
    cout << "\nMang sau khi sap xep theo trinh tu tang dan la: ";
    XuatMang(SoLuong, Arr);
    SelectionSort(SoLuong, Arr);
    cout << "\nMang sau khi sap xep theo trinh tu giam dan la: ";
    XuatMang(SoLuong, Arr);
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
