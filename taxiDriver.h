#pragma once
#include <string>
using namespace std;
#include "person.h"

class TaxiDriver : public Person {
    string type;
    int feePerMin = 100;
    int initFee = 3800;
public:
    TaxiDriver(string name, int id, char gender, string job, string type);
    virtual ~TaxiDriver() { }
    virtual int calcAmount();
    string getType();
};