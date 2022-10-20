#include <iostream>
#include <algorithm>
using namespace std;
#include "employManage.h"

bool EmployManage::checkList(string name)
{
    for(auto person: employee_list){
        if (person.getName() == name)
            return true;
    }
    return false;
}

void EmployManage::addEmployee(Person p)
{
    if (checkList(p.getName())){
        cout << "CANNOT ADD - Duplicate name: " << p.getName() << endl;
        return;
    }
    employee_list.push_back(p);
}

void EmployManage::delEmployee(Person p)
{
    // Person it = getPerson(p.getId());

    // if (it == employee_list.end()){
    //     cout << "CANNOT DEL - No person : " << p.getName() << endl;
    // }else{
    //     employee_list.erase(it);
    //     cout << p.getName() << " DELETED" << endl;
    // }

}

void EmployManage::showList()
{
    for(auto p: employee_list){
        cout << p.getName() << '\t' << p.getGender() << '\t' << p.getJob() << endl;
    }
}

vector<Person>::iterator EmployManage::getPerson(int id)
{
    vector<Person>::iterator it;
    it = find_if(employee_list.begin(), employee_list.end(), 
                    [id] (Person p) { return (p.getId() == id); }
                    );
    return it;
}

vector<Person>::iterator EmployManage::getPerson(string name)
{
    vector<Person>::iterator it;
    it = find_if(employee_list.begin(), employee_list.end(), 
                    [name] (Person p) { return (p.getName() == name); }
                    );
    return it;
}

int EmployManage::selectPerson(string type)
{
    /// 택시운전사의 id 반환
    int n;
    vector<int> candidates; // 해당 type조건에 해당하는 후보 운전사들

    if (type == ""){
        for(Person p: employee_list){
            if (p.getJob() == "미용사")
                candidates.push_back(p.getId());
        }
    }else{
        for(Person p: employee_list){
            if (p.getJob() == "택시운전사"){
                if (p.getType() == type){
                    candidates.push_back(p.getId());
                }
            }
        }
    }
    

    n = rand() % candidates.size();
    return candidates[n];
}