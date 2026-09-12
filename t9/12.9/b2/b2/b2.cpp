// b2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<iomanip>
using namespace std;
struct Sach
{
	char TuaDe[100];
	char TG[50];
	int Trang;
	int Gia;
};
int main()
{
	int a;
	Sach dsSach[50];
	cout << "Nhap vao so luong sach can luu tru: ";
	cin >> a;
	cin.ignore();
	cout << "Nhap vao thong tin sach: \n";
	for (int i = 0;i < a;i++) {
		cout << "Cuon thu " << i+1<<": \n";
		cout << "Tua de: ";
		cin.getline(dsSach[i].TuaDe,100);
		cout << "Tac gia: ";
		cin.getline(dsSach[i].TG, 50);
		cout << "So trang: ";
		cin >> dsSach[i].Trang;
		cout << "Gia tien: ";
		cin >> dsSach[i].Gia;
		cin.ignore();
	}
	cout << left
		<< setw(15) << "Tua de"
		<< setw(15) << "Tac gia"
		<< setw(10) << "So trang"
		<< setw(10) << "Gia tien"<<endl;
	for (int i = 0;i < a;i++) {
		cout << left
			<< setw(15) << dsSach[i].TuaDe
			<< setw(15) << dsSach[i].TG
			<< setw(10) << dsSach[i].Trang
			<< setw(10) << dsSach[i].Gia << endl;
	}
	cout << "Nhung cuon sach co tu 200 trang tro len la: \n";
	for (int i = 0;i < a;i++) {
		if (dsSach[i].Trang >= 200) {
			cout << dsSach[i].TuaDe << "||";
		}
	}
	cout << "\nNhung cuon sach co gia tu 90000 tro xuong la: \n";
	for (int i = 0;i < a;i++) {
		if (dsSach[i].Gia <= 90000) {
			cout << dsSach[i].TuaDe << "||";
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
