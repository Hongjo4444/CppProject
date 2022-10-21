#include <iostream>
using namespace std;
#include "person.h"


Person::Person(){ }

Person::Person(string name, int id, char gender, string job){
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

string Person::getType(){
    return "";
}

int Person::calcAmount(){
    return -1;
}