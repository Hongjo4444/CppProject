#include <iostream>
using namespace std;
#include "taxiDriver.h"


TaxiDriver::TaxiDriver(string name, int id, char gender, string job, string type) 
 : Person(name, id, gender, job) { this->type = type; }

int TaxiDriver::calcAmount()
{
    float dist;
    cout << "이동 거리 입력 (km) >>";
    cin >> dist;

    if (dist < 2)
        return initFee;
    else{
        return initFee + (dist - 2) * feePerMin;
    }
}

string TaxiDriver::getType()
{
    return type;
}