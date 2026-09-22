// b8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<string>
using namespace std;
struct VE {
    char hang;
    int so;
    int rap;
};
VE dsach[50];
int SoLuongVe = 0;
void docfile() {
    ifstream file("vexemphim.txt");
    if (!file.is_open()) {
        cout<<"Loi! Khong doc duoc file!";
        return;
    }
    int n;
    file >> n;
    VE ve;
    char daugach;
    while(file>>ve.hang>>ve.so>>daugach>>ve.rap&&SoLuongVe<50){
        dsach[SoLuongVe] = ve;
        SoLuongVe++;
    }
}
void HienThiSoDoChoNgoi(int marap) {
    cout << "\t\t\t\tSO DO CHO NGOI";
    cout << "\n=================================================================================\n";
    cout << "MAN HINH\n";
    for (char i = 'A';i <= 'J';i++) {
        cout << i << "     ";
        for (int j = 1;j <= 12;j++) {
            if (j < 10) {
                cout << "  " << "[0" << j << "]";
            }
            else {
                cout << "  [" << j << "]";
            }
        }
        cout << "\n";
    }
}
int main()
{
    int marap;
    cout << "Moi nhap rap: ";
    cin >> marap;
    docfile();
    HienThiSoDoChoNgoi(marap);
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
