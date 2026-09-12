// b1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
struct Nhanvien{
    char MaNV[5];
    char HoTen[50];
    char ChVu[20];
    int TNCT;
    int NP;
};
int main()
{
    Nhanvien dsNV[5] = {
        {"DI01","Nguyen Kim Long","Giam doc",47,17},
        {"AC05","Dau Thi Duyen","Ke toan",47,25},
        {"HR03","Tran Ha Lan","Nhan su",22,7},
        {"TR02","Tran Ngoc Thoa","Giao vu",13,9},
        {"IT04","Tran Ngoc Dang","IT",4,2},
    };
    cout <<left<< setw(8) << "Ma NV" << setw(22) << "Ho ten" << setw(15) << "Chuc vu" << setw(8) << "TNCT" << setw(5) << "Phep\n";
    cout << "----------------------------------------------------------------------------\n";
    for (int i = 0; i < 5; i++) {
        cout << left
            << setw(8) << dsNV[i].MaNV
            << setw(22) << dsNV[i].HoTen
            << setw(15) << dsNV[i].ChVu
            << setw(8) << dsNV[i].TNCT
            << dsNV[i].NP << "\n";
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
