// b9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<cctype>
using namespace std;
int main()
{
    string fname;
    cout << "Nhap vao ho ten day du: ";
    getline(cin, fname);
    int dai = fname.length();
    int op;
    cout << "Chon quy tac lap email: \n(1)Quy tac 1: ten.ho_vs_ten_lot @greenacademy.edu.vn\n(2)Quy tac 2: ten_vs_ten_ky_tu_viet_tat @greenacademy.edu.vn\n";
    cin >> op;
    switch (op) {
    case 1: 
        for (int i = dai - 1;i >= 0;i--) {//Viet ten
            if (isspace(fname[i])) {
                for (int j = i + 1;j < dai;j++) {
                    cout << (char)tolower(fname[j]);
                }
                break;
            }
        }
        cout << ".";
        for (int i = dai - 1;i >= 0;i--) {//Viet ho va ten lot
            if (isspace(fname[i])) {
                for (int j = 0;j < i;j++) {
                    if (!isspace(fname[j])) {
                        cout << (char)tolower(fname[j]);
                    }
                }
                break;
            }
        }
        cout << "@greenacademy.edu.vn";
        break;
    case 2:
        for (int i = dai - 1;i >= 0;i--) {//Viet ten
            if (isspace(fname[i])) {
                for (int j = i + 1;j < dai;j++) {
                    cout << (char)tolower(fname[j]);
                }
                break;
            }
        }
        cout << "." << (char)tolower(fname[0]);
        for (int i = dai - 1;i >= 0;i--) {
            if (isspace(fname[i])) {
                for (int j = 1;j < i;j++) {
                    if (isspace(fname[j - 1])) {
                        cout << (char)tolower(fname[j]);
                    }
                }
                break;
            }
        }
        cout << "@greenacademy.edu.vn";
        break;
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
