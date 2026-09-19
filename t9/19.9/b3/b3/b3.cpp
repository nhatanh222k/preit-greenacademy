// b3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
    int a[50];
    int n;
    do {
        cout << "Nhap so luong phan tu (1-50): ";
        cin >> n;
    } while (n < 1 || n > 50);
    for (int i = 0;i < n;i++) {
        cout << "Nhap a[" << i << "] = ";
        cin >> a[i];
    }
    ofstream file("tep_gia_tri.txt");
    if (!file) {
        cout << "Khong the mo/ghi tap tin!" << endl;
        return 1;
    }
    file << "So luong phan tu su dung trong mang: " << n;
    file << "\nGia tri cac phan tu la: ";
    for (int i = 0;i < n;i++) {
        file << a[i];
        if (i != n - 1) {
            file << " ";
        }
    }
    file << ".";
    file.close();
    cout << "Da tao thanh cong tep tin!";
    return 0;
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
