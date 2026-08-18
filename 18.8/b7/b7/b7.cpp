// b7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    float t, v, a, tb;
    cout << "Nhap vao lan luot 3 diem toan, van, anh: \n";
    cin >> t >> v >> a;
    tb = (t + v + a) / 3;
    cout << "Diem trung binh la: " << tb<<"\n";
    if (tb >= 8.5) {
        cout << "Loai A";
    }
    else if (tb >= 6.5 && tb <= 8.49) {
        cout << "Loai B";
    }
    else if (tb >= 5 && tb <= 6.49) {
        cout << "Loai C";
    }
    else if (tb >= 3.5 && tb <= 4.99) {
        cout << "Loai D";
    }
    else if  (tb <3.5) {
        cout << "Loai F";
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
