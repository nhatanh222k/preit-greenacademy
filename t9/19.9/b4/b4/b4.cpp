// b4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("ngan_hang_de_thi.txt");
    if (!file) {
        cout << "Khong the tao file!" << endl;
        return 1;
    }
    file << "Cho biet 1 van co gia tri so nao?\t1\t10\t1000\t10000\tD\t5\n";
    file << "Thu do cua Viet Nam la thanh pho nao?\tHue\tHa Noi\tDa Nang\tHai Phong\tB\t5\n";
    file << "Ket qua cua phep tinh 12 + 8 la bao nhieu?\t18\t19\t20\t21\tC\t5\n";
    file << "Hanh tinh nao gan Mat Troi nhat?\tTrai Dat\tSao Hoa\tSao Kim\tSao Thuy\tD\t5\n";
    file << "Nuoc co cong thuc hoa hoc la gi?\tCO2\tH2O\tO2\tNaCl\tB\t5\n";
    file << "Mot nam thong thuong co bao nhieu thang?\t10\t11\t12\t13\tC\t5\n";
    file << "Tac gia cua Truyen Kieu la ai?\tNguyen Du\tNguyen Trai\tHo Xuan Huong\tNam Cao\tA\t5\n";
    file << "Ket qua cua phep tinh 7 * 8 la bao nhieu?\t54\t56\t58\t64\tB\t5\n";
    file << "Don vi do cuong do dong dien la gi?\tVon\tAmpe\tOm\tOat\tB\t5\n";
    file << "Quoc gia nao co hinh dang lanh tho giong chiec ung tren ban do chau Au?\tPhap\tDuc\tY\tTay Ban Nha\tC\t5\n";
    file.close();
    cout << "Da luu ngan hang de thi vao file ngan_hang_de_thi.txt" << endl;
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
