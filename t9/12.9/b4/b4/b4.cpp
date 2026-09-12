// b4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
struct music {
    char Ma[7];
    char Ten[100];
    int nghe;
};
int main()
{
    music dsnhac[100] = {
        {"A001","Loser",5000000},
        {"A002","Let not fall in love",5000007},
        {"A003","Bang bang bang",5000004},
        {"A004","If you",5000002},
        {"A005","Lies",5000006},
        {"A006","Blue",5000001},
    };
    int n = 6;
    music hit = dsnhac[0];
    for (int i = 1; i < n; i++) {
        if (dsnhac[i].nghe > hit.nghe) {
            hit = dsnhac[i];
        }
    }
    cout << "CA KHUC HIT:" << endl;
    cout << "Ma bai hat: " << hit.Ma << endl;
    cout << "Ten bai hat: " << hit.Ten << endl;
    cout << "Luot nghe: " << hit.nghe << endl;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (dsnhac[j].nghe < dsnhac[j + 1].nghe) {
                music temp = dsnhac[j];
                dsnhac[j] = dsnhac[j + 1];
                dsnhac[j + 1] = temp;
            }
        }
    }
    cout << "\nBANG XEP HANG:" << endl;
    cout << left
        << setw(8) << "Hang"
        << setw(10) << "Ma"
        << setw(25) << "Ten bai hat"
        << setw(15) << "Luot nghe"
        << endl;
    for (int i = 0; i < n; i++) {
        cout << left
            << setw(8) << i + 1
            << setw(10) << dsnhac[i].Ma
            << setw(25) << dsnhac[i].Ten
            << setw(15) << dsnhac[i].nghe
            << endl;
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
