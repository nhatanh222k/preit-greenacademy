// b12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int hinh,dang,dai,rong,day,cao;
    cout << "Chon hinh rong hoac khong rong(rong:0/Khong rong:1):";
    cin >> hinh;
    if (hinh == 1) {
        cout << "Chon hinh chu nhat hoac tam giac(chu nhat:0/tam giac:1): ";
        cin >> dang;
        if (dang == 0) {
            cout << "Nhap vao lan luot chieu dai va rong cua hinh chu nhat:";
            cin >> dai >> rong;
            for (int i = 1;i <= rong;i++) {
                for (int j = 1;j <= dai;j++) {
                    cout << "*";
                }
                cout << "\n";
            }
        }
        else if (dang == 1) {
            cout << "Nhap vao lan luot chieu cao va do dai day tam giac vuong: ";
            cin >> cao >> day;
            for (int i = 1;i <= cao;i++) {
                for (int j = 1;j <= day;j++) {
                    for (int a = 1; a <= j;a++) {
                        cout << "*";
                    }
                    cout << "\n";
              }
          }
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
