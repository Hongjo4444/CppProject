#include "bank.h"


Bank::Bank(){ }

Bank::~Bank(){ }

bool Bank::makeAccount(Person p, Account& newA){
    int choose;
    int account,balance;

    for(auto it=accountList.begin();it!=accountList.end(); it++){ //계좌 체크하고 만들 수 있으면 만들어서 받아온 newA에 넣기
        if((p.getName()==it->first) && (it->second).size()==2){
            cout << "이미 일반 계좌,카카오 계좌가 모두 있습니다." << endl;
            return false;
        }
        else if(p.getName()==it->first && (it->second).size()==1 && (it->second)[0].isAccount()=="일반 계좌"){
            cout << "이미 일반 계좌가 있습니다. 카카오 계좌만 가입 가능합니다.(1:카카오 계좌 가입,2:종료)" << endl;
            cin >> choose;
            if(choose==1){
                cout << "계좌 번호와 초기 입금액 입력 >> " << endl;
                cin >> account >> balance;
                newA = KakaoAccount(account,balance);
                return true;
            }
            else if(choose==2){
                return false;
            }       
        }
        else if(p.getName()==it->first && (it->second).size()==1 && (it->second)[0].isAccount()=="카카오 계좌"){
            cout << "이미 카카오 계좌가 있습니다. 일반 계좌만 가입 가능합니다.(1:일반 계좌 가입,2:종료)" << endl;
            cin >> choose;
            if(choose==1){
                cout << "계좌 번호와 초기 입금액 입력 >> " << endl;
                cin >> account >> balance;
                newA = Account(account,balance);
                return true;
            }
            else if(choose==2){
                return false;
            }    
        }
        else{
            cout << "일반 계좌, 카카오 계좌 모두 가입 가능합니다.(1:일반 계좌 가입,2:카카오 계좌 가입)" << endl;
            cin >> choose;
            cout << "계좌 번호와 초기 입금액 입력 >> " << endl;
            cin >> account >> balance;
            if(choose==1){                
                newA = KakaoAccount(account,balance);
                return true;
            }
            else if(choose==2){
                newA = Account(account,balance);
                return true;
            }
            // else추가!!!
        }
    }
    
}

void Bank::addAccount(Person p, string accType){
    Account newA;
    cout << newA.getAccount() << ", " << newA.getBalance() << endl;
    auto it=accountList.find(p.getName());
    if(makeAccount(p,newA) && it!=accountList.end()){ //원래 계좌가 있던경우 -> 있던 벡터에 추가or있던벡터 리뉴얼
        if((it->second)[0].isAccount()=="일반 계좌") (it->second).push_back(newA);
        else if((it->second)[0].isAccount()=="카카오 계좌") (it->second).insert((it->second).begin(),newA);
        return;
    }
    // else if(makeAccount(p,newA) && it==accountList.end()){ //원래 계좌가 없던경우 -> 벡터 만들어서 맵에 추가
    //     vector<Account> vA;
    //     vA.push_back(newA);
    //     accountList.insert(p.getName(), vA);
    //     cout << "계좌 만들기 성공" << endl;
    //     return;
    // }
    else{ //makeAccount 실패한 경우
        cout << "계좌 만들기 실패" << endl;
        return;
    }
}

void Bank::delAccount(Person p, string accType){
    string delName = p.getName();
    auto it=accountList.find(delName);
    if(it!=accountList.end()){
        cout << "삭제할 계좌 선택(1:일반 계좌,2:카카오 계좌,3:전체 삭제)" << endl;
        int choose;
        switch(choose){
            case 1:
                (it->second).erase((it->second).begin());
                break;
            case 2:
                (it->second).erase((it->second).end());
                break;
            case 3:
                accountList.erase(delName);
                break;
        }
    }
    else cout << "계좌가 없습니다" << endl;
    return;
}

void Bank::showAllAccount(){
    for(auto it=accountList.begin();it!=accountList.end();it++){
        if((it->second).size()==2){
            cout << "이름: " << it->first
            << "일반 계좌,잔액: " << (it->second)[0].getAccount() << (it->second)[0].getBalance()
            << "카카오 계좌,잔액: " << (it->second)[1].getAccount() << (it->second)[1].getBalance() << endl;
        }
        else{
            if((it->second)[0].isAccount()=="일반 계좌"){
                cout << "이름: " << it->first << "일반 계좌,잔액: " << (it->second)[0].getAccount() << (it->second)[0].getBalance() << endl;
            }
            else{
                cout << "이름: " << it->first << "카카오 계좌,잔액: " << (it->second)[0].getAccount() << (it->second)[0].getBalance() << endl;
            }
        }
    }
}

bool Bank::sendMoney(Person pf,Person pt,int m){
    auto itf=accountList.find(pf.getName()); //pf 돈 m만큼 감소, 감소 성공하면 pt 돈 m만큼 증가
    auto itt=accountList.find(pt.getName());
    if(itf==accountList.end()){
        cout << "보내는 사람이 없는 사람입니다" << endl;
        return false;
    }
    if(itt==accountList.end()){
        cout << "받는 사람이 없는 사람입니다" << endl;
        return false;
    }
    if((itf->second)[0].getBalance()<m){ // 합치는 걸로 수정하기! (포인트까지 고려!)
        cout << "잔액 부족" << endl;
        return false;
    }
    else{
        (itf->second)[0].setBalance((itf->second)[0].getBalance()-m);
        (itt->second)[1].setBalance((itt->second)[1].getBalance()+m);
        cout << "송금 성공" << endl;
        return true;
    }
}

bool Bank::recvMoney(Person pt,int m){
    auto itt=accountList.find(pt.getName());
    if(itt==accountList.end()){
        cout << "받는 사람이 없는 사람입니다" << endl;
        return false;
    }
    (itt->second)[0].setBalance((itt->second)[0].getBalance()+m);
    cout << "지급 성공" << endl;
    return true;
}