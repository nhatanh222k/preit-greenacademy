// b2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cmath>
using namespace std;
int BinhPhuong(int so) {
    int x=2;
    cout <<"Binh phuong cua "<<so<<" la: "<< pow(so, x);
    return 0;
}
float CanBacHai(int so) {
    int x=2;
    cout << "\nCan bac 2 cua " << so << " la: " << sqrt(so);
    return 0;
}
int main()
{
    int so;
    cout << "Nhap vao so n: ";
    cin >> so;
    BinhPhuong(so);
    CanBacHai(so);
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
