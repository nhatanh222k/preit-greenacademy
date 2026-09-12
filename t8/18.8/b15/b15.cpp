// b15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    char kytu;
    cout << "Hay nhap vao ky tu: ";
    cin >> kytu;
    switch (kytu) {
        case 'u':
        case 'e':
        case 'o':
        case 'a':
        case 'i':
        case 'U':
        case 'E':
        case 'O':
        case 'A':
        case 'I':cout << "Ky tu nhap vao la nguyen am";break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':cout << "Ky tu nhap vao la so";break;
        default: 
            if ((kytu >= 'a' && kytu <= 'z') || (kytu >= 'A' && kytu <= 'Z')) {
                cout << "Ky tu nhap vao la phu am";
            }
            else {
                cout << "Ky tu dac biet";
            }
    }
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
