#pragma once 

#include <iostream>
#include <string>
using namespace std;

class Account{
protected:
    int account,balance;
public:
    Account(){}
    Account(int account,int balance){
        this->account=account;
        this->balance=balance;
    };
    virtual int getAccount(){ return account; }
    virtual int getBalance(){ return balance; }
    virtual int getPoint(){ return 0; }
    string isAccount(){ return "일반 계좌"; }
    virtual void setAccount(int account){ this->account=account; }
    virtual void setBalance(int balance){ this->balance=balance; }
};

class KakaoAccount:public Account{
    int point;
public:
    KakaoAccount(int account,int balance):Account(account,balance){
        this->point=10000;
    };
    virtual int getAccount(){ return account; }
    virtual int getBalance(){ return balance; }
    virtual int getPoint(){ return point; }
    string isAccount(){ return "카카오 계좌"; }
    virtual void setAccount(int account){ this->account=account; }
    virtual void setBalance(int balance){ this->balance=balance; }
    virtual void setPoint(int point){ this->point=point; }
};