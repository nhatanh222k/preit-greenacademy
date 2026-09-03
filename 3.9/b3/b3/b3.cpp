// b3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int Tong(int a, int b) {
	cout << a << " + " << b << " = " << a + b;
	return 0;
}
int Hieu(int a, int b) {
	cout << a << " - " << b << " = " << a - b;
	return 0;
}
int Tich(int a, int b) {
	cout << a << " * " << b << " = " << a * b;
	return 0;
}
int Thuong(int a, int b) {
	cout << a << " / " << b << " = " << float(a) / b;
	return 0;
}
int main()
{
	int a, b,n;
	cout << "Nhap vao lan luot 2 so a va b: ";
	cin >> a >> b;
	cout << "Nhap vao phep tinh muon tinh: ";
	cout << "\n1.Tong a+b\n2.Hieu a-b\n3.Tich a*b\n4.Thuong a/b\n";
	cin >> n;
	switch (n) {
	case 1:Tong(a, b);break;
	case 2:Hieu(a, b);break;
	case 3:Tich(a, b);break;
	case 4:Thuong(a, b);break;
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
