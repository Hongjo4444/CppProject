#include <iostream>
using namespace std;

class Account{
    int account;
    int balance;
public:
    Account(int account,int balance){
        this->account=account;
        this->balance=balance;
    }
    virtual int getAccout(){ return account; }
    virutal int getBalance(){ return balance; }
}

class KakaoAccount:public Account{
    int point;
public:
    KakaoMoney(int account,int balance):Account(account,balance){
        this->point=10000;
    }
    virtual int getAccout(){ return account; }
    virutal int getBalance(){ return balance; }
    virtual int getPoint(){ return point; }
}