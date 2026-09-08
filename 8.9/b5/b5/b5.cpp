// b5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<cctype>
using namespace std;
int KiemTraTonTai(char c, string chuoidai) {
    for (int i = 0; i < chuoidai.length(); i++) {
        if (chuoidai[i] == c) {
            return 1;
        }
    }
    return 0;
}
int main()
{
    string a, b;
    cout << "Nhap vao chuoi ky tu s1: ";
    getline(cin, a);
    cout << "Nhap vao chuoi ky tu s2: ";
    getline(cin, b);
    string chuoidai,chuoingan;
    if (a.length() >= b.length()) {
        chuoidai = a;
        chuoingan = b;
    }
    else {
        chuoidai = b;
        chuoingan = a;
    }
    cout << "Ky tu xuat hien trong ca 2 chuoi la: ";
    for (int i = 0;i < chuoingan.length();i++) {
        char c = chuoingan[i];
        if (KiemTraTonTai(c, chuoidai)==1) {
            cout << chuoingan[i];
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
