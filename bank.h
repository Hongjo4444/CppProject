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
    void addAccount(Person p);
    void delAccount(Person p);
    void showAllAccount();
    void showAccount(map<string,vector<Account>>::iterator it);
    //map<string,vector<Account>>::iterator getIterbyName(string name){ }////////////person 받아서 하는걸로
    int getAccountSum(Person p);
    int getBalanceSum(Person p);
    bool sendMoney(Person pf,Person pt,int m);
    bool recvMoney(Person pt,int m);
};