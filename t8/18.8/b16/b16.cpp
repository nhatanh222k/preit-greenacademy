// b16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int a,n,x;
    cout << "\t    VUI LONG CHON LOAI TIEN DOI\n";
    cout << "\t1.USD\t2.EUR\t3.AUD\t4.HKD\t5SGD\n";
    cin >> a;
    switch (a) {
    case 1:n = 21080;break;
    case 2:n = 28276;break;
    case 3:n = 19151;break;
    case 4:n = 2679;break;
    case 5:n = 16624;break;
    default:cout << "Nhap vao khong hop le!";break;
    }
    cout << "Nhap menh gia can doi: ";
    cin >> x;
    cout << "Ket qua sau khi doi la: " << x*n;
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
