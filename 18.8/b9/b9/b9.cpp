// b9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Nhap vao tham nien cong tac (thang) : ";
    cin >> n;
    float a = 1.92, b = 2.34, c = 3, d = 4.5;
    int h = 650000;
    if (n < 12) {
        cout << "Luong = " << int(a * h);
    }
    else if (n >= 12 && n < 36) {
        cout << "Luong = " << int(b * h);
    }
    else if (n >= 36 && n < 60) {
        cout << "Luong = " << int(c * h);
    }
    else if (n>=60) {
        cout << "Luong = " << int(d * h);
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
