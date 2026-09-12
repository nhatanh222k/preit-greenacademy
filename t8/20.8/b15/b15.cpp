// b15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	char cau1, cau2, cau3, cau4, cau5;
	int diem=0;
	//cau 1
	cout << "1.Ten cua ironman la gi?\n";
	cout << "A. Steve Rogers\tB. Tony Stark\tC. Bruce Banner\tD. Peter Parker\n";
	while (true) {
		cin >> cau1;
		if (cau1 == 'b' || cau1 == 'B') {
			diem = diem + 10;
			break;
		}
		else {
			cout << "Dap an sai! Yeu cau chon lai!\n";
			diem = diem - 1;
		}
	}
	//cau 2
	cout << "2. Captain America su dung vu khi nao noi tieng nhat?\n";
	cout << "A. Bua Mjolnir\tB. Cung ten\tC. Khien\tD. Kiem\n";
	while (true) {
		cin >> cau2;
		if (cau2 == 'c' || cau2 == 'C') {
			diem = diem + 10;
			break;
		}
		else {
			cout << "Dap an sai! Yeu cau chon lai!\n";
			diem = diem - 1;
		}
	}
	//cau 3
	cout << "3. Thor la con trai cua vi than nao?\n";
	cout << "A. Odin\tB. Loki\tC. Zeus\tD. Heimdall\n";
	while (true) {
		cin >> cau3;
		if (cau3 == 'a' || cau3 == 'A') {
			diem = diem + 10;
			break;
		}
		else {
			cout << "Dap an sai! Yeu cau chon lai!\n";
			diem = diem - 1;
		}
	}
	//cau 4
	cout << "4. Ten that cua Spider-Man la gi?\n";
	cout << "A. Peter Parker\tB. Wade Wilson\tC. Scott Lang\tD. Stephen Strange\n";
	while (true) {
		cin >> cau4;
		if (cau4 == 'a' || cau4 == 'A') {
			diem = diem + 10;
			break;
		}
		else {
			cout << "Dap an sai! Yeu cau chon lai!\n";
			diem = diem - 1;
		}
	}
	//cau 5
	cout << "5. Vien da nao cho phep Thanos dieu khien thoi gian?\n";
	cout << "A. Space Stone\tB. Power Stone\tC. Time Stone\tD. Mind Stone\n";
	while (true) {
		cin >> cau5;
		if (cau5 == 'c' || cau5 == 'C') {
			diem = diem + 10;
			break;
		}
		else {
			cout << "Dap an sai! Yeu cau chon lai!\n";
			diem = diem - 1;
		}
	}
	cout << "Tong diem cua ban la: " << diem;

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
