#include <string>
using namespace std;
#include "person.h"

class TaxiDriver : public Person {
    string type;
    int feePerMin = 100;
    int initFee = 3800;
public:
    TaxiDriver(string name, int id, char gender, string job, string type) : Person(name, id, gender, job) {
        this->type = type;
    }
    virtual ~TaxiDriver() { }
    virtual int calcAmount();
    // int time인자 없애고 함수안에서 받자
    // --> float dist로 받자
    // virtual로 변경
    string getType();
}