// b12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int KiemTraChuSoToanChan(int songuyen) {
    int x;
    if (songuyen < 0) {
        songuyen = -songuyen;
    }
    while (songuyen > 0) {
        x = songuyen % 10;
        if (x % 2 == 1) {
            return 0;
        }
        songuyen = songuyen / 10;
    }
    return 1;
}
int KiemTraTangDan(int songuyen) {
    int dem = 0,temp = songuyen ,sau,x,y;
    while (temp > 0) {
        dem++;
        temp = temp / 10;
    }
    for (int i = dem;i > 1;i--) {
        sau = songuyen % 10;
        x = songuyen / 10;
        y = x % 10;
        if (y >= sau) {
            return 0;
        }
        songuyen = x;
    }
    return 1;
}
void DemSoChanLe(int songuyen, int& DemChan, int& DemLe) {
    int x;
    DemChan = 0;
    DemLe = 0;
    while (songuyen > 0) {
        x = songuyen % 10;
        if (x % 2 == 1) {
            DemLe++;
        }
        else {
            DemChan++;
        }
        songuyen /= 10;
    }
}
int main()
{
    int songuyen, DemChan=0, DemLe=0;
    cout << "Nhap vao so nguyen lon hon 2 chu so: ";
    cin >> songuyen;
    int a = KiemTraChuSoToanChan(songuyen);
    if (a == 1) {
        cout << "So cua ban la so chua toan ky tu chan";
    }
    else if (a == 0) {
        cout << "So cua ban co chua ky tu le";
    }
    int b = KiemTraTangDan(songuyen);
    if (b == 1) {
        cout <<"\nSo "<< songuyen << " la so co cac ky tu so tang dan";
    }
    else if (b == 0) {
        cout << "\nSo " << songuyen << " la so khong co cac ky tu so tang dan";
    }
    DemSoChanLe(songuyen,DemChan,DemLe);
    cout << "\nSo luong chu so chan: " << DemChan;
    cout << "\nSo luong chu so le: " << DemLe;
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
