// b7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct phanso {
    int tuso;
    int mauso;
};
void NhapPhanSo(phanso& ps) {
    cout << "Nhap vao tu so: ";
    cin >> ps.tuso;
    do {
        cout << "Nhap vao mau so: ";
        cin >> ps.mauso;
        if (ps.mauso == 0) {
            cout << "Mau so phai khac 0. Vui long nhap lai!\n";
        }
    } while (ps.mauso == 0);
}
void XuatPhanSo(phanso ps) {
    cout << ps.tuso << "/" << ps.mauso;
}
int UCLN(int a, int b) {
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
phanso Tong2PS(phanso ps1, phanso ps2) {
    phanso ketqua;
    ketqua.tuso = ps1.tuso * ps2.mauso + ps2.tuso * ps1.mauso;
    ketqua.mauso = ps1.mauso * ps2.mauso;
    return ketqua;
}

phanso Hieu2PS(phanso ps1, phanso ps2) {
    phanso ketqua;
    ketqua.tuso = ps1.tuso * ps2.mauso - ps2.tuso * ps1.mauso;
    ketqua.mauso = ps1.mauso * ps2.mauso;
    return ketqua;
}
phanso RutGonPS(phanso ps) {
    int ucln = UCLN(ps.tuso, ps.mauso);
    if (ps.tuso == 0) {
        ps.mauso = 1;
        return ps;
    }
    ps.tuso /= ucln;
    ps.mauso /= ucln;
    if (ps.mauso < 0) {
        ps.tuso = -ps.tuso;
        ps.mauso = -ps.mauso;
    }

    return ps;
}
int KiemTraPS(phanso ps) {
    if (ps.tuso == 0) {
        return 0;
    }
    if (ps.tuso * ps.mauso > 0) {
        return 1;
    }
    return -1;
}
int main() {
    phanso ps1, ps2;
    phanso tong, hieu;
    cout << "===== NHAP PHAN SO 1 =====\n";
    NhapPhanSo(ps1);
    cout << "\n===== NHAP PHAN SO 2 =====\n";
    NhapPhanSo(ps2);
    cout << "\nPhan so 1: ";
    XuatPhanSo(ps1);
    cout << "\nPhan so 2: ";
    XuatPhanSo(ps2);
    // Tính tổng
    tong = Tong2PS(ps1, ps2);
    tong = RutGonPS(tong);
    cout << "\n\nTong 2 phan so: ";
    XuatPhanSo(tong);
    // Tính hiệu
    hieu = Hieu2PS(ps1, ps2);
    hieu = RutGonPS(hieu);
    cout << "\nHieu 2 phan so: ";
    XuatPhanSo(hieu);
    int ktradau = KiemTraPS(ps1);
    if (ktradau == 1) {
        cout << "\nPhan so 1 la phan so duong.";
    }
    else if (ktradau == -1) {
        cout << "\nPhan so 1 la phan so am.";
    }
    else {
        cout << "\nPhan so 1 bang 0.";
    }
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
