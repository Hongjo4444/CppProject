#include <string>
using namespace std;
#include "person.h"


string TaxiDriver::getType()
{
    return type;
}

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