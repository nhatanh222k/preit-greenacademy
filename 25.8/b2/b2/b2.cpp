// b2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    float n[] = { 36.5,98, 27.8, 63, 78.1, 48.3, 69, 72, 41.5, 32, 29.5, 120, 52.3, 23, 50.2, 56, 72.5, 70, 68.4, 65 };
    int a = size(n);
    //yc1
    cout << "Danh sach nhung nguoi thieu can, thua can la: \n";
    for (int i = 0;i < a;i++) {
        if (n[i] > 75 || n[i] < 38) {
            cout << n[i] << " ";
        }
    }
    //yc2
    float max=n[0], min=n[0];
    cout << "\nUng vien co can nang cao nhat la: ";
    for (int i = 0;i < a;i++) {
        if (max < n[i]) {
            max = n[i];
        }
    }
    cout << max;
    cout << "\nUng vien co can nang thap nhat la: ";
    for (int i = 0;i < a;i++) {
        if (min > n[i]) {
            min = n[i];
        }
    }
    cout << min;
    //yc3
    float dem = 0;
    cout << "\nSo luong ung vien dat tieu chuan la: ";
    for (int i = 0;i < a;i++) {
        if (n[i] <= 75 && n[i] >= 38) {
            dem++;
        }
    }
    cout << dem;
    //yc4
    cout << "\nCan nang trung binh cua cac ung vien dat tieu chuan la: ";
    int tong = 0;
    for (int i = 0;i < a;i++) {
        if (n[i] <= 75 && n[i] >= 38) {
            tong+=n[i];
        }
    }
    cout << tong / dem;
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
