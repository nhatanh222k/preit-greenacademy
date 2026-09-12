// b4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<cctype>
using namespace std;
int main()
{
    string a, b;
    cout << "Nhap vao chuoi s1: ";
    getline(cin, a);
    cout << "Nhap vao chuoi s2: ";
    getline(cin, b);
    if (a.length() == b.length()) {
        cout << "Do dai cua 2 chuoi bang nhau";
    }
    else if (a.length() > b.length()) {
        cout << "Chuoi s1 dai hon s2";
    }
    else {
        cout << "Chuoi s1 ngan hon s2";
    }
    if (a.find(b)!=string::npos) {
        cout << "\nChuoi s2 co ton tai trong chuoi s1";
    }
    else {
        cout << "\nChuoi s2 khong ton tai trong chuoi s1";
    }
    cout <<"\n"<< a+b;
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
