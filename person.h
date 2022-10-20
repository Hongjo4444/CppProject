#pragma once
#include <string>
using namespace std;

class Person{
protected:
    string name;
    int id;
    char gender;
    string job;
public:
    Person();
    Person (string name, int id, char gender, string job="");
    virtual ~Person() { }
    // taxi랑 salon이 person으로 오면서 필요없어진것같음
    // bool useTaxi(string name);
    // bool useSalon(string name);
    // bool useBank(string name);
    virtual int calcAmount(); // 추가, int로 반환
    string getName();
    int getId();    
    char getGender();
    string getJob();
    // bool del(); 이것도 필요없어보임
    string getType();
    virtual void setCustomerGender(char c) {};
};