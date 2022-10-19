#include <string>
#include <vector>
using namespace std;
#include "person.h"

class EmployManage{
    vector<Person> employee_list;
public:
    bool checkList(string name);
    void addEmployee(Person p);
    void delEmployee(Person p);
    void showList();
    //int calcAmount();  필요없는 듯
    Person* getPerson(int id); // Person*로 바꿈
    int selectDriver(string type);
}