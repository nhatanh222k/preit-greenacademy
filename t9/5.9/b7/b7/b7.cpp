// b7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void TinhCan(int y) {
	int can;
	can = y % 10;
	switch (can) {
	case 0:cout << "Canh";break;
	case 1:cout << "Tan";break;
	case 2:cout << "Nham";break;
	case 3:cout << "Quy";break;
	case 4:cout << "Giap";break;
	case 5:cout << "At";break;
	case 6:cout << "Binh";break;
	case 7:cout << "Dinh";break;
	case 8:cout << "Mau";break;
	case 9:cout << "Ky";break;
	}
}
void TinhChi(int y) {
	int chi;
	chi = (y - 1800) % 12;
	switch (chi) {
	case 0:cout << " Than";break;
	case 1:cout << " Dau";break;
	case 2:cout << " Tuat";break;
	case 3:cout << " Hoi";break;
	case 4:cout << " Ti";break;
	case 5:cout << " Suu";break;
	case 6:cout << " Dan";break;
	case 7:cout << " Meo";break;
	case 8:cout << " Thin";break;
	case 9:cout << " Ti";break;
	case 10:cout << " Ngo";break;
	case 11:cout << " Mui";break;
	}
}
int main()
{
	int y;
	cout << "Nhap vao nam sinh: ";
	cin >> y;
	TinhCan(y);
	TinhChi(y);
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
