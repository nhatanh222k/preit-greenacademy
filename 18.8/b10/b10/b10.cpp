// b10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    float a;
    float tongtien;
    cout << "Nhap vao so km da di: ";
    cin >> a;
    if (a <= 1) {
        tongtien = a * 15000;
    }
    else if (a > 1 && a <= 5) {
        tongtien = (a-1) * 13500 + 15000;
    }
    else if (a > 5) {
        tongtien = 15000 + 5 * 13500 + (a - 6) * 11000;
        if (a >= 20) {
            tongtien = (15000 + 5 * 13500 + (a - 6) * 11000) * 0.9;
        }
    }
    cout << "Tong tien = " << tongtien;
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
