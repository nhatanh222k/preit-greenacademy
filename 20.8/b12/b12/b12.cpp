// b12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int hinh,dang,dai,rong,cao;
    cout << "Chon hinh rong hoac khong rong(rong:0/Khong rong:1):";
    cin >> hinh;
    if (hinh == 1) {
        cout << "Chon hinh chu nhat hoac tam giac(chu nhat:0/tam giac:1): ";
        cin >> dang;
        //chu nhat va vuong kin
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
        //tam giac vuong can kin
        else if (dang == 1) {
            cout << "Nhap vao chieu cao tam giac vuong: ";
            cin >> cao ;
            for (int i = 1;i <= cao;i++) {
                for (int j = 1; j <= i;j++) {
                     cout << "*";
                }
                cout << "\n";
            }
        }
    }
    else if (hinh == 0) {
        cout << "Chon hinh chu nhat hoac tam giac(chu nhat:0/tam giac:1): ";
        cin >> dang;
        //chu nhat va vuong rong
        if (dang == 0) {
            cout << "Nhap vao lan luot chieu dai va rong cua hinh chu nhat:";
            cin >> dai >> rong;
            for (int i = 1;i <= rong;i++) {
                for (int j = 1;j <= dai;j++) {
                    if (i == 1 || i == rong || j == 1 || j == dai) {
                        cout << "*";
                    }
                    else {
                        cout << " ";
                    }
                }
                cout << "\n";
            }
        }
        //tam giac vuong can rong
        else if (dang == 1) {
            cout << "Nhap vao chieu cao tam giac vuong: ";
            cin >> cao;
            for (int i = 1;i <= cao;i++) {
                for (int j = 1; j <= i;j++) {
                    if (i == cao || j == 1 || i == j) {
                        cout << "*";
                    }
                    else {
                        cout<<" ";
                    }
                }
                cout << "\n";
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
