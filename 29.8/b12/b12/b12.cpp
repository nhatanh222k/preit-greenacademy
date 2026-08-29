// b12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int a[100], n;
void XoaPhanTu(int vtxoa) {
    for (int i = vtxoa;i < n - 1;i++) {
        a[i] = a[i + 1];
    }
    n--;
}
int KiemTra(int x) {
    if (x % 4 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}
void HienThi(int n, int a[]) {
    for (int i = 0;i < n;i++) {
        cout << a[i] << " ";
    }
}
int main()
{
    cout << "Nhap vao so phan tu cua mang a: ";
    cin >> n;
    cout << "Nhap vao mang a: ";
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    for (int i = 0;i < n;i++) {
        if (KiemTra(a[i]) == 1) {
            XoaPhanTu(i);
            i--;
        }
    }
    HienThi(n, a);
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
