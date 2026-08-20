// b8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    bool chan=true;
    cout << "Nhap vao so nguyen N( lon hon 2 chu so): ";
    cin >> n;
    while (n > 0) {
        int a = n % 10;
        if (a % 2 == 0) {
            n = n / 10;
        }
        else {
            chan = false;
            break;
        }
    }
    if (chan == true) {
        cout << "N toan chu so chan";
    }
    else {
        cout << "N khong toan chan";
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
