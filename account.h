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
        this->account=account; //계좌번호
        this->balance=balance; //잔액
    };
    virtual ~Account(){}
    int getAccount(){ return account; }
    int getBalance(){ return balance; }
    virtual int getPoint(){ return 0; }
    virtual string isAccount(){ return "일반 계좌"; }
    void setAccount(int account){ this->account=account; }
    void setBalance(int balance){ this->balance=balance; }
    virtual void setPoint(int point){ }
};

class KakaoAccount:public Account{
    int point;
public:
    KakaoAccount(int account,int balance):Account(account,balance){
        this->point=10000;
    };
    virtual ~KakaoAccount(){}
    virtual int getPoint(){ return point; }
    virtual string isAccount(){ return "카카오 계좌"; }
    virtual void setPoint(int point){ this->point=point; }
};