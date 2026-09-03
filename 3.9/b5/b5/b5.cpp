// b5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int NhapSoNguyen() {
	int x;
	cout << "Nhap vao 1 so nguyen duong: ";
	cin >> x;
	while (x < 0) {
		cout << "Nhap lai so nguyen duong: ";
		cin >> x;
	}
	return x;
}
int GiaiThua(int x) {
	int gt = 1;
	for (int i = 1; i <= x; i++) {
		gt *= i;
	}
	return gt;
}
int main()
{
	int a,b,c;
	int Tong = 0;
	cout << "Nhap gia tri cho A:\n";
	a = NhapSoNguyen();

	cout << "Nhap gia tri cho B:\n";
	b = NhapSoNguyen();

	cout << "Nhap gia tri cho C:\n";
	c = NhapSoNguyen();
	Tong = GiaiThua(a) + GiaiThua(b) + GiaiThua(c);
	cout << "Tong cac giai thua S = A! + B! + C! la: " << Tong;
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
