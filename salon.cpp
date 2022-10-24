#include <iostream>
#include <iomanip>
using namespace std;
#include "salon.h"


SalonDesigner::SalonDesigner(string name, int id, char gender, string job)
 : Person(name, id, gender, job) { }

void SalonDesigner::showMenu()
{
    int w = 20;
    cout << left << setw(w) << setfill(' ') << " ";
    cout << left << setw(w) << setfill(' ') << "남";
    cout << left << setw(w) << setfill(' ') << "여" << endl;

    cout << left << setw(w) << setfill(' ') << "컷";
    cout << left << setw(w) << setfill(' ') << "10,000원";
    cout << left << setw(w) << setfill(' ') << "20,000원" << endl;

    cout << left << setw(w) << setfill(' ') << "펌";
    cout << left << setw(w) << setfill(' ') << "50,000원";
    cout << left << setw(w) << setfill(' ') << "100,000원" << endl << endl;
}

int SalonDesigner::calcAmount()
{
    string choice;
    showMenu();
    cout << "원하는 시술을 입력해주세요 >>";
    cin >> choice;

    if (choice == "컷")
        return (customerGender == 'M') ? 10000 : 20000;
    else
        return (customerGender == 'M') ? 50000 : 100000;
}

void SalonDesigner::setCustomerGender(char c){
    customerGender = c;
}