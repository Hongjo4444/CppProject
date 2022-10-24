#pragma once 

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include "account.h"
#include "person.h"
using namespace std;

int subtract(Account** a, int &m, bool isPoint=false);

class Bank{
    map<string,vector<Account*>> accountList;
public:
    Bank();
    ~Bank();
    bool checkAccDup(int a);
    bool makeAccount(string name, Account** newA);
    bool addAccount(string name);
    bool delAccount(string delName);
    void showAllAccount();
    void showAccount(map<string,vector<Account*>>::iterator it);
    map<string,vector<Account*>>::iterator getIterbyName(string name);////////////person 받아서 하는걸로
    int getAccountSum(string name);
    int getBalanceSum(Person p);
    bool sendMoney(Person* pf,Person* pt,int m);
    bool recvMoney(string name,int ptAcc);
};