// b9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void Sapxep(int n, int a[],int b[],int x) {
	for (int i = 0;i < n;i++) {
		if (a[i] % 2 == 0) {
			b[x] = a[i];
			x++;
		}
	}
	int tg;
	for (int j = 0;j < x-1;j++) {
		for (int i = 0;i < x-j-1;i++) {
			if (b[i] > b[i + 1]) {
				tg = b[i];
				b[i] = b[i + 1];
				b[i + 1] = tg;
			}
		}
	}
	cout << "Mang sau khi sap xep cac so chan theo thu tu tang dan la: ";
	for (int i = 0;i < x;i++) {
		cout << b[i] << " ";
	}
}
int main()
{
	int a[100],n;
	int b[100],x=0;
	cout << "Nhap vao so luong phan tu trong mang a: ";
	cin >> n;
	cout << "Nhap vao lan luot gia tri cac phan tu trong mang a: ";
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	Sapxep(n, a, b, x);
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
