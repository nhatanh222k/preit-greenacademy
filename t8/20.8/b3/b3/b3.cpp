// b3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int n,a=0,b=0,c=0,d=0,dau=1;
    cout << "Nhap vao so nguyen N: ";
    cin >> n;
    //tong cac so le den n
    for (int i = 1;i <= n;i+=2) {
        a = a + i;
    }
    cout <<"Tong cac so le den N la: "<< a;
    //tong cac so chan den n
    for (int i = 2;i <= n;i += 2) {
        b = b + i;
    }
    cout << "\nTong cac so chan den N la: " << b;
    //tong binh phuong cac so den n
    for (int i = 1;i <= n;i++) {
        int x = pow(i, 2);
        c = c + x;
    }
    cout << "\nTong binh phuong cac so den N la: " << c;
    //tong cac so den N theo cau truc+-
    for (int i = 1;i <= n;i++) {
        d = d +(dau * i);
        dau *= -1;
    }
    cout << "\nTong cac so den N theo cau truc+- la: " << d;
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
