#pragma once

#include <string>
using namespace std;
#include "person.h"

class SalonDesigner : public Person {
public:
    SalonDesigner(string name, int id, char gender, string job);
    virtual ~SalonDesigner() { }
    void showMenu();
    virtual int calcAmount(); // virtual로 변경, int로 반환
};