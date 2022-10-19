#include <string>
using namespace std;
#include "person.h"

class SalonDesigner : public Person {
public:
    virtual ~SalonDesigner() { }
    void showMenu();
    virtual int calcAmount(); // virtual로 변경, int로 반환
}