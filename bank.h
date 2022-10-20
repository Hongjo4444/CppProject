#pragma once 

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "account.h"
#include "person.h"
using namespace std;

class Bank{
    map<string,vector<Account>> accountList;
public:
    Bank();
    ~Bank();
    bool makeAccount(Person p, Account& newA);
    void addAccount(Person p, string accType); // 수정 요
    void delAccount(Person p, string accType);// 수정 요
    void showAllAccount();
    int showAccount(Person p) { return 1000000000; }
    bool sendMoney(Person pf,Person pt,int m);
    bool recvMoney(Person pt,int m);
};