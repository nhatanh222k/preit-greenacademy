// b5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
struct giay {
	char id[6];
	float size;
	int gtinh;
	int sl;
	int gia;
};
giay dsgiay[50];
int slgiay;
void NhapGiay() {
	cin.ignore();
	cout << "Nhap thong tin giay: ";
	for (int i = 0;i < slgiay;i++) {
		cout << "\nNhap vao ma giay: ";
		cin.getline(dsgiay[i].id, 6);
		cout << "Nhap vao kich co giay: ";
		cin >> dsgiay[i].size;
		cout << "Nhap vao gioi tinh( 0.nu,1.nam,2.unisex): ";
		cin >> dsgiay[i].gtinh;
		cout << "Nhap vao so luong: ";
		cin >> dsgiay[i].sl;
		cout << "Nhap vao gia tien: ";
		cin >> dsgiay[i].gia;
		cin.ignore();
	}
}
void XuatGiay() {
	string gioitinh;
	cout << "Danh sach giay co trong kho la: ";
	cout << left << setw(15) << "\nMa giay"
		<< setw(15) << "Kich co"
		<< setw(15) << "Gioi tinh"
		<< setw(15) << "So luong"
		<< setw(15) << "Gia tien";
	cout << "\n---------------------------------------------------------------------------------------------------\n";
	for (int i = 0;i < slgiay;i++) {
		if (dsgiay[i].gtinh == 1) {
			gioitinh = "nam";
		}
		else if (dsgiay[i].gtinh == 0) {
			gioitinh = "nu";
		}
		else if (dsgiay[i].gtinh == 2) {
			gioitinh = "unisex";
		}
		cout << left << setw(14) << dsgiay[i].id
			<< setw(15) << dsgiay[i].size
			<< setw(15) << gioitinh
			<< setw(15) << dsgiay[i].sl
			<< setw(20) << dsgiay[i].gia<<endl;
	}
}
void TimGiay() {
	string ttgt;
	float ttsz;
	int ttgtdangso;
	cout << "Nhap thong tin giay can tim: \n";
	cout << "Nhap vao gioi tinh: ";
	cin >> ttgt;
	if (ttgt == "nam") {
		ttgtdangso = 1;
	}
	else if (ttgt == "nu") {
		ttgtdangso = 0;
	}
	else if (ttgt == "unisex") {
		ttgtdangso = 2;
	}
	cout << "Nhap vao kich thuoc: ";
	cin >> ttsz;
	for (int i = 0;i < slgiay;i++) {
		if (dsgiay[i].gtinh == ttgtdangso) {
			if (dsgiay[i].size == ttsz) {
				cout << "Mau ban can tim la: \n";
				cout << left << setw(14) << dsgiay[i].id
					<< setw(15) << dsgiay[i].size
					<< setw(15) << ttgt
					<< setw(15) << dsgiay[i].sl
					<< setw(20) << dsgiay[i].gia << endl;
				break;
			}
		}
	}
}
void MuaGiay() {
	int slmua;
	char mamua[6];
	bool timthay = false;
	cout << "Nhap vao ma giay muon mua: ";
	cin >> mamua;
	cout << "Nhap vao so luong giay muon mua: ";
	cin >> slmua;
	for (int i = 0; i < slgiay; i++) {
		if (strcmp(mamua, dsgiay[i].id) == 0) {
			timthay = true;
			if (slmua <= dsgiay[i].sl) {
				int tien = slmua * dsgiay[i].gia;
				dsgiay[i].sl -= slmua;
				cout << "Mua giay thanh cong!\n";
				cout << "So tien ban can tra la: " << tien << endl;
				cout << "So luong con lai trong kho: "
					<< dsgiay[i].sl << endl;
			}
			else {
				cout << "So luong giay trong kho khong du!" << endl;
			}

			break;
		}
	}
	if (!timthay) {
		cout << "Khong tim thay ma giay!" << endl;
	}
}

int main()
{
	cout << "Nhap vao so luong giay co trong kho: ";
	cin >> slgiay;
	NhapGiay();
	XuatGiay();
	TimGiay();
	MuaGiay();
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
