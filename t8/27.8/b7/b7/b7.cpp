// b7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int a[10] = { 1,2,3,4,5,6,7,8,9 };
int n = 9;
void AddValue(int value, int pos) {
    for (int i = n;i > pos;i--) {
        a[i] = a[i - 1];
    }
    a[pos] = value;
    n++;

}
void RemoveValue(int pos) {
    for (int i = pos;i < n - 1;i++) {
        a[i] = a[i + 1];
    }
    n--;
}
void OutputArray() {
    for (int i = 0;i < n;i++) {
        cout << a[i] << " ";
    }
}
int main()
{
    int value, pos;
    OutputArray();
    cout << "\nNhap vao vi tri can them: ";
    cin >> pos;
    cout << "Nhap vao gia tri muon them: ";
    cin >> value;
    AddValue(value, pos);
    cout << "Ham sau khi them vao la:\n";
    OutputArray();
    cout << "\nNhap vao vi tri phan tu can xoa: ";
    cin >> pos;
    RemoveValue(pos);
    cout << "Ham sau khi xoa vi tri thu " << pos << " la: ";
    OutputArray();
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
