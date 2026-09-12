// b5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	int a, b, c, d, h;
	cout << "Nhap lan luot 2 canh day: ";
	cin >> a >> b;
	cout << "Nhap lan luot 2 canh ben: ";
	cin >> c >> d;
	cout << "Nhap chieu cao:";
	cin >> h;
	cout << "Dien tich hinh thang la: " << 0.5 * (a + b) * h << "\nChu vi hinh thang la: " << a + b + c + d;
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
