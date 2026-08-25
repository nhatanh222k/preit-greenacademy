// b3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "Nhap so luong phan tu cua mang: ";
	cin >> n;
	int a[100];
	cout << "Nhap cac gia tri cua mang: ";
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	//yc1
	int A;
	cout << "Nhap vao gia tri A: \n";
	cin >> A;
	cout << "Cac phan tu tri so chan nho hon A la: ";
	for (int i = 0;i < n;i++) {
		if (a[i] % 2 == 0 && a[i] <= A) {
			cout << a[i]<<" ";
		}
	}
	//yc2
	int B,dem=0;
	cout << "\nNhap vao gia tri B: \n";
	cin >> B;
	cout << "So lan xuat hien cac phan tu bang B la: ";
	for (int i = 0;i < n;i++) {
		if (a[i] == B ) {
			dem++;
		}
	}
	cout << dem;
	//yc3
	int X, Y;
	cout << "\nNhap vao lan luot gia tri cua X va Y: ";
	cin >> X >> Y;
	cout << "Cac gia tri nao trong khoang X va Y la: ";
	for (int i = 0;i < n;i++) {
		if (a[i] < Y && a[i] > X) {
			cout << a[i] << " ";
		}
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
