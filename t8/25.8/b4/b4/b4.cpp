// b4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "Nhap vao so luong phan tu trong mang: ";
	cin >> n;
	int a[100];
	cout << "Nhap vao 1 mang so nguyen: ";
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	bool doixung = true;
	for (int i = 0;i < n / 2;i++) {
		if (a[i] != a[n - i - 1]) {
			doixung = false;
		}
	}
	if (doixung) {
		cout << "Day la 1 mang doi xung";
	}
	else {
		cout << "Day la 1 mang ko doi xung";
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
