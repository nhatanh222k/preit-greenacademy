// b9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void NhapSoNguyen(int &a, int &b) {
	cout << "Nhap vao 2 so nguyen a va b: ";
	cin >> a >> b;
	if (a < 0) {
		a = -a;
	}
	if (b < 0) {
		b = -b;
	}
}
void TimUCLN(int a, int b) {
	int x;
	if (a >= b) {
		x = a;
	}
	if (a == b && b == 0) {
		cout << "Khong xac dinh ";
	}
	if (a < b) {
		x = b;
	}
	
	for (int i = x;i > 0;i--) {
		if (a % i == 0 && b % i == 0) {
			cout << "Uoc chung lon nhat cua a va b la: " << i;
			break;
		}
	}
}
int main()
{
	int a, b;
	NhapSoNguyen(a, b);
	TimUCLN(a, b);
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
