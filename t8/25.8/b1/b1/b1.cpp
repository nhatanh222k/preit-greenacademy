// b1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	int n[] = { 10,25,-4,32,63,81,19,-24,13,18,45,12,72,42,-6 };
	int a = size(n);
	//yc1
	cout << "Cac vi tri va gia tri cua phan tu la so chan la: \n";
	for (int i = 0;i < a ;i++) {
		if (n[i] % 2 == 0) {
			cout << "Vi tri thu " << i << " voi gia tri la " << n[i] << "\n";
		}
	}
	//yc2
	int dem = 0;
	cout << "So phan tu co gia tri chia het cho 3 va 9 la: ";
	for (int i = 0;i < a ;i++) {
		if(n[i]%9==0){
			dem++;
		}
	}
	cout << dem << "\n";
	//yc3
	int tong = 0;
	cout << "Tong cac phan tu co tri so chan la: ";
	for (int i = 0;i < a ;i++) {
		if (n[i] % 2 == 0) {
			tong = tong + n[i];
		}
	}
	cout << tong << "\n";
	//yc4
	cout << "Vi tri va gia tri cua cac phan tu co gia tri am la: \n";
	for (int i = 0;i < a;i++) {
		if (n[i] < 0) {
			cout << "Vi tri thu " << i << " voi gia tri la: " << n[i] << "\n";
			n[i] = 0;
		}
	}
	cout << "Mang sau khi thay the gia tri la: ";
	for (int i = 0;i < a;i++) {
		cout << n[i] << " ";
		
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
