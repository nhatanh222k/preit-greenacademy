// b12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int thang;
    cout << "Nhap vao mot thang bang so (1->12): ";
    cin >> thang;
    switch (thang) {
    case 1: cout << "January";break;
    case 2: cout << "February";break;
    case 3: cout << "March";break;
    case 4: cout << "April";break;
    case 5: cout << "May";break;
    case 6: cout << "June";break;
    case 7: cout << "July";break;
    case 8: cout << "August";break;
    case 9: cout << "September";break;
    case 10: cout << "October";break;
    case 11: cout << "November";break;
    case 12: cout << "December";break;
    default: cout << "Nhap vao khong hop le";break;
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
