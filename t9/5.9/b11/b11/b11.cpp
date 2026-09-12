// b11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cmath>
using namespace std;
int GiaiPhuongTrinh(float a, float b, float c, float &x, float &y) {
	float delta;
	delta = b * b - 4 * a * c;
	if (a == 0 && b != 0) {
		x = -c / b;
		cout << "Phuong trinh co 1 nghiem la: " << x;
	}
	if (a == 0 && b == 0 && c == 0) {
		cout << "Phuong trinh vo so no";
		return 0;
	}
	if (delta < 0) {
		cout << "Phuong trinh vo no";
		return -1;
	}
	else if (delta == 0) {
		x = -b /(2 * a);
		cout << "Phuong trinh co 1 no kep la: " << x;
		return 1;
	}
	else if (delta > 0&& a != 0 ) {
		x = (-b + sqrt(delta)) / (2 * a);
		y = (-b - sqrt(delta)) / (2 * a);
		cout << "Phuong trinh co 2 no la: " << x <<" va "<<y;
	}
}
int main()
{
	float a, b, c;
	cout << "Nhap vao lan luot 3 he so a, b va c: ";
	cin >> a >> b >> c;
	float x, y;
	GiaiPhuongTrinh(a, b, c, x, y);
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
