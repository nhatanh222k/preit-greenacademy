// b11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int a, b,max;
    cout << "Nhap vao 2 so nguyen duong a va b: ";
    cin >> a >> b;
    if (a == 0) {
        cout << "Uoc chung lon nhat la: " << b;
    }
    else if (b == 0) {
        cout << "Uoc chung lon nhat la: " << a;
    }
    else{
        while (a != b) {
            if (a > b) {
                a = a - b;
            }
            else {
                b = b - a;
            }
        }
        cout << "Uoc chung lon nhat cua 2 so la: " << a;
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
