#pragma once
#include <string>
#include <vector>
using namespace std;
#include "person.h"

class EmployManage{
    vector<Person> employee_list;
public:
    bool checkList(string name);
    void addEmployee(Person p, bool fromDB=false);
    void delEmployee(Person p);
    void showList();
    //int calcAmount();  필요없는 듯
    vector<Person>::iterator getPerson(int id); // Person*로 바꿈
    vector<Person>::iterator getPerson(string name);
    int selectPerson(string type="");
};