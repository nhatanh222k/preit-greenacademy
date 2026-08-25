// b6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void inMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[6] = { 2, 3, 4, 5 };
    int n = 4;
    cout << "Mang ban dau: ";
    inMang(a, n);
    if (n < 6) {
        a[n] = 6; 
        n++;     
    }
    cout << "Sau khi them 6 vao cuoi: ";
    inMang(a, n);  
    if (n < 6) {
        for (int i = n; i > 0; i--) {
            a[i] = a[i - 1];
        }
        a[0] = 1;
        n++;
    }
    cout << "Sau khi them 1 vao dau: ";
    inMang(a, n);

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
