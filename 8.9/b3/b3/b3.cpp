// b3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<cctype>
using namespace std;
int main()
{
    string a;
    cout << "Nhap vao 1 chuoi: ";
    getline(cin, a);
    int dai = a.length();
    int kytu = 0,
        kyso = 0,
        khtrang = 0;
    for (int i = 0;i < dai;i++) {
        if (isalpha(a[i])) {
            kytu++;
        }
        else if (isdigit(a[i])) {
            kyso++;
        }
        else if (isspace(a[i])) {
            khtrang++;
        }
    }
    cout << "So Ky tu trong chuoi la: " << kytu;
    cout << "\nSo Ky so trong chuoi la: " << kyso;
    cout << "\nSo Khoang trang trong chuoi la: " << khtrang;
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
