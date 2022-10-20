#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Bank{
    map<string,vector<Account>> accountList;
public:
    Bank();
    ~Bank();
    bool makeAccount(Person p,Account& newA);
    void addAccount(Person p,Account a);
    void delAccount(Person p,Account a);
    void showAllAccount();
    bool sendMoney(Person pf,Person pt,int m);
    bool recvMoney(Person pt,int m);
};