#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Bank{
    map<Person,vector<Money>> accountList;
public:
    Bank();
    ~Bank();
    bool addAccount(Person p,Money m);
    bool delAccount(Person p,Money m);
    void showAllAccount();
    bool sendMoney(Person pf,Person pt,int m);
    bool recvMoney(Person pt,int m)
};