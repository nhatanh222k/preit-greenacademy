// b12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace	std;
int EmailValidation(string email) {
	if (email.find('@') != string::npos && email.find('.') != string::npos)
	{
		return 1;
	}
	return 0;
}
int PasswordValidation(string mk) {
	int dai = mk.length();
	if (dai != 8) {
		return 0;
	}
	for (int i = 0;i < dai;i++) {
		if (mk.find(isupper(mk[i])) != string::npos && mk.find(islower(mk[i])) != string::npos) {
			return 1;
		}
	}
}
int ConfirmValidation(string mk, string xnmk) {
	if (mk == xnmk)
	{
		return 1;
	}
	return 0;
}
int main()
{
	string email,mk,xnmk;
	cout << "Nhap Email: ";
	getline(cin, email);
	while (EmailValidation(email) == 0) {
		cout << "Email khong hop le yeu cau nhap lai: ";
		getline(cin, email);
	}
	cout << "Nhap vao mat khau: ";
	getline(cin, mk);
	while (PasswordValidation(mk) == 0) {
		cout << "Mat khau khong hop le yeu cau nhap lai: ";
		getline(cin, mk);
	}
	cout << "Xac nhan lai mat khau: ";
	getline(cin, xnmk);
	while (ConfirmValidation(mk,xnmk) == 0) {
		cout << "Mat khau nhap lai khong giong yeu cau nhap lai: ";
		getline(cin, xnmk);
	}
	cout << "Register successfully";
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
