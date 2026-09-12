// 11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cout << "Nhap vao 3 so nguyen duong: \n";
    cin >> a >> b >> c;
    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) {
            cout << "La tam gia deu";
        }
        else if ((a == b && a != c) || (b == c && a != b) || (a == c && a != b)) {
            if (a * a + b * b == c * c || a * a + c * c == b * b || c * c + b * b == a * a) {
                cout << "La tam giac vuong can";
            }
            else {
                cout << "La tam gia can";
            }
        }
        else if (a * a + b * b == c * c || a * a + c * c == b * b || c * c + b * b == a * a) {
            cout << "La tam giac vuong ";
        }
        else {
            cout << "La tam giac thuong";
        }
    }
    else {
        cout << "Khong phai 3 canh cua tam giac";
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
