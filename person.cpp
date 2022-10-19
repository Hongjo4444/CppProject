#include <iostream>
#include <string>
using namespace std;
#include "person.h"

// bool Person::useTaxi(string name)
// {   
// }
// bool Person::useSalon(string name)
// {
// }
// bool Person::useBank(string name)
// {
// }

Person::Person (string name, int id, char gender, string job){
    this->name = name;
    this->id = id;
    this->gender = gender;
    this->job = job;
}




string Person::getName()
{
    return name;
}

int Person::getId()
{
    return id;
}

char Person::getGender()
{
    return gender;
}

string Person::getJob()
{
    return job;
}
