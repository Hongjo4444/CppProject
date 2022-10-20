#include <iostream>
#include <string>
using namespace std;

class Account{
    int account,balance;
public:
    Account(int account,int balance){
        this->account=account;
        this->balance=balance;
    };
    virtual int getAccout(){ return account; };
    virutal int getBalance(){ return balance; };
    string isAccount(){ return "일반 계좌"; };
    virtual void setAccount(int account){ this->account=account; };
    virtual void setBalance(int balance){ this->balance=balance; };
};

class KakaoAccount:public Account{
    int point;
public:
    KakaoMoney(int account,int balance):Account(account,balance){
        this->point=10000;
    };
    virtual int getAccout(){ return account; };
    virutal int getBalance(){ return balance; };
    virtual int getPoint(){ return point; };
    string isAccount(){ return "카카오 계좌"; };
    virtual void setAccount(int account){ this->account=account; };
    virtual void setBalance(int balance){ this->balance=balance; };
};