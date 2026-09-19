// b2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<fstream>
using namespace std;
struct Date {
	int ngay;
	int thang;
	int nam;
};
int main()
{
	string tencty;
	string tenthuctap;
	string truong;
	string nganh;
	int thoigianthuctap;
	Date ngaybd, ngayvtdon;
	cout << "Nhap ten cong ty thuc tap: ";
	getline(cin, tencty);
	cout << "Nhap ten thuc tap sinh: ";
	getline(cin, tenthuctap);
	cout << "Nhap ten truong dang theo hoc: ";
	getline(cin, truong);
	cout << "Nhap chuyen nganh: ";
	getline(cin, nganh);
	cout << "Nhap ngay bat dau thuc tap: ";
	cin >> ngaybd.ngay >> ngaybd.thang >> ngaybd.nam;
	cout << "Nhap thoi gian thuc tap ( thang ): ";
	cin >> thoigianthuctap;
	cout << "Nhap ngay viet don: ";
	cin >> ngaybd.ngay >> ngaybd.thang >> ngaybd.nam;
	ofstream outfile("DonXinThucTap.txt");
	if (!outfile) {
		cerr << "Khong the tao/mo file de ghi" << endl;
		return 1;
	}
	outfile << "                      CONG HOA XA HOI CHU NGHIA VIET NAM\n";
	outfile << "                         Doc lap - Tu do - Hanh phuc\n";
	outfile << "                                  =======\n";
	outfile << "                              DON XIN THUC TAP\n";
	outfile << "Kinh gui: " << tencty << ".\n";
	outfile << "Toi ten la: " << tenthuctap << ".\n";
	outfile << "Hien toi dang la sinh vien cua truong: " << truong << ", chuyen nganh: " << nganh << ".\n";
	outfile << "Kinh xin quy co quan cho toi duoc thuc tap tai cong ty trong thoi gian 24 thang, bat dau tu ngay ";
	if (ngaybd.ngay < 10) {
		outfile << "0" << ngaybd.ngay;
	}
	else {
		outfile << ngaybd.ngay;
	}
	outfile << "/";
	if (ngaybd.thang < 10) {
		outfile << "0" << ngaybd.thang;
	}
	else {
		outfile << ngaybd.thang;
	}
	outfile << "/";
	outfile << ngaybd.nam << "\n";
	outfile << "Trong qua trinh thuc tap toi xin cam doan se thuc hien dung noi quy cong ty.\n\n";
	outfile << "Toi xin chan thanh cam on.\n";
	outfile << "TPHCM, ngay ";
	if (ngaybd.ngay < 10) {
		outfile << "0" << ngaybd.ngay;
	}
	else {
		outfile << ngaybd.ngay;
	}
	outfile << " thang ";
	if (ngaybd.thang < 10) {
		outfile << "0" << ngaybd.thang;
	}
	else {
		outfile << ngaybd.thang;
	}
	outfile << " nam " << ngaybd.nam <<"\n\n";
	outfile << tenthuctap;
	outfile.close();
	cout << "Da xuat file thanh cong";
	return 0;
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
