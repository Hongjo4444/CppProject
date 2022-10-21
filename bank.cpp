#include "bank.h"



Bank::Bank(){ }

Bank::~Bank(){ }

bool Bank::makeAccount(Person p, Account& newA){
    int choose;
    int account,balance;
    if(accountList.size()==0){
        cout << "일반 계좌, 카카오 계좌 모두 가입 가능합니다.(1:일반 계좌 가입,2:카카오 계좌 가입)" << endl;
        cin >> choose;
        cout << "계좌 번호와 초기 입금액 입력 >> " << endl;
        while(1){
            cin >> account >> balance;
            if(choose==1){                
                newA = Account(account,balance);
                return true;
            }
            else if(choose==2){
                newA = KakaoAccount(account,balance);
                return true;
            }
            else{
                cout << "1,2 중에 선택하세요." << endl;
            }
        }
    }
    for(auto it=accountList.begin();it!=accountList.end(); it++){ //계좌 체크하고 만들 수 있으면 만들어서 받아온 newA에 넣기
        if((p.getName()==it->first) && (it->second).size()==2){
            cout << "이미 일반 계좌,카카오 계좌가 모두 있습니다." << endl;
            return false;
        }
        else if(p.getName()==it->first && (it->second).size()==1 && (it->second)[0].isAccount()=="일반 계좌"){
            cout << "이미 일반 계좌가 있습니다. 카카오 계좌만 가입 가능합니다.(1:카카오 계좌 가입,2:종료)" << endl;
            while(1){
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
                else{
                    cout << "1,2 중에 선택하세요." << endl;
                }
            }
        }
        else if(p.getName()==it->first && (it->second).size()==1 && (it->second)[0].isAccount()=="카카오 계좌"){
            cout << "이미 카카오 계좌가 있습니다. 일반 계좌만 가입 가능합니다.(1:일반 계좌 가입,2:종료)" << endl;
            while(1){
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
                else{
                    cout << "1,2 중에 선택하세요." << endl;
                }
            }    
        }
        else{
            cout << "일반 계좌, 카카오 계좌 모두 가입 가능합니다.(1:일반 계좌 가입,2:카카오 계좌 가입)" << endl;
            cin >> choose;
            cout << "계좌 번호와 초기 입금액 입력 >> " << endl;
            while(1){
                cin >> account >> balance;
                if(choose==1){                
                    newA = Account(account,balance);
                    return true;
                }
                else if(choose==2){
                    newA = KakaoAccount(account,balance);
                    return true;
                }
                else{
                    cout << "1,2 중에 선택하세요." << endl;
                }
            }
        }
    }

    return false;
}

void Bank::addAccount(Person p){
    Account newA;
    // cout << newA.getAccount() << ", " << newA.getBalance() << endl; -------------------------------------------------------삭제
    auto it=accountList.find(p.getName());
    if(accountList.size()==0){
        makeAccount(p,newA); //처음 켰을때(리스트 빈 경우)
        vector<Account> vA;
        vA.push_back(newA);
        accountList.insert(pair<string,vector<Account>>(p.getName(), vA));
        cout << "계좌 만들기 성공" << endl;
        return;
    }
    else{
        bool check=makeAccount(p,newA);
        if(check==true && it!=accountList.end()){ //원래 계좌가 있던경우 -> 있던 벡터에 추가or있던벡터 리뉴얼
            if((it->second)[0].isAccount()=="일반 계좌") (it->second).push_back(newA);
            else if((it->second)[0].isAccount()=="카카오 계좌") (it->second).insert((it->second).begin(),newA); //////완료문구
            return;
        }
        else if(check==true && it==accountList.end()){ //원래 계좌가 없던경우 -> 벡터 만들어서 맵에 추가
            vector<Account> vA;
            vA.push_back(newA);
            accountList.insert(pair<string,vector<Account>>(p.getName(), vA));
            cout << "계좌 만들기 성공" << endl;
            return;
        }
        else{ //makeAccount 실패한 경우
            cout << "계좌 만들기 실패" << endl;
            return;
        }
    }
}

void Bank::delAccount(Person p){
    string delName = p.getName();
    auto it=accountList.find(delName);
    if(it!=accountList.end()){
        cout << "삭제할 계좌 선택(1:일반 계좌,2:카카오 계좌,3:전체 삭제)" << endl;
        int choose;
        while(1){
            cin >> choose;
            switch(choose){
                case 1:
                    if((it->second).size()==0){
                        cout << "삭제할 계좌가 없습니다." << endl;
                        break;
                    }
                    else if((it->second).size()==1 && (it->second)[0].isAccount()=="카카오 계좌"){
                        cout << "일반 계좌가 없습니다.(카카오 계좌만 보유 중)" << endl;
                        break;
                    }
                    else{
                        (it->second).erase((it->second).begin());
                        break;
                    }
                case 2:
                    if((it->second).size()==0){
                        cout << "삭제할 계좌가 없습니다." << endl;
                        break;
                    }
                    else if((it->second).size()==1 && (it->second)[0].isAccount()=="일반 계좌"){
                        cout << "카카오 계좌가 없습니다.(일반 계좌만 보유 중)" << endl;
                        break;
                    }
                    else{
                        (it->second).erase((it->second).end());
                        break;
                    }
                case 3:
                    if((it->second).size()==0){
                        cout << "계좌가 없습니다." << endl;
                        break;
                    }
                    else if((it->second).size()==1 && (it->second)[0].isAccount()=="일반 계좌"){
                        cout << "계좌가 2개가 아닙니다.(일반 계좌만 보유 중)" << endl;
                        break;
                    }
                    else if((it->second).size()==1 && (it->second)[0].isAccount()=="카카오 계좌"){
                        cout << "계좌가 2개가 아닙니다.(카카오 계좌만 보유 중)" << endl;
                        break;
                    }
                    else{
                        accountList.erase(delName);
                        cout << "계좌 2개 삭제 완료" << endl;
                    }
                    break;
                default:
                    cout << "1,2,3 중에 선택하세요" << endl;
                    break;
            }   
        }
    }
    else cout << "계좌가 없습니다" << endl;
    return;
}

void Bank::showAllAccount(){
    for(auto it=accountList.begin();it!=accountList.end();it++){
        showAccount(it);
    }
}

void Bank::showAccount(map<string,vector<Account>>::iterator it){
    if((it->second).size()==2){
        cout << "이름: " << it->first << ", " 
        << "일반 계좌,잔액: " << (it->second)[0].getAccount() << ", " << (it->second)[0].getBalance()
        << "카카오 계좌,잔액: " << (it->second)[1].getAccount() << ", " << (it->second)[1].getBalance() << endl;
    }
    else{
        if((it->second)[0].isAccount()=="일반 계좌"){
            cout << "이름: " << it->first << ", " << "일반 계좌,잔액: " << (it->second)[0].getAccount() << ", " << (it->second)[0].getBalance() << endl;
        }
        else{
            cout << "이름: " << it->first << ", " << "카카오 계좌,잔액: " << (it->second)[0].getAccount() << ", " << (it->second)[0].getBalance() << endl;
        }
    }
}

int Bank::getAccountSum(Person p){
    int sum=0;
    auto it=accountList.find(p.getName());
    
    if((it->second).size()==2){
        sum=(it->second)[0].getBalance()+(it->second)[1].getBalance()+(it->second)[1].getPoint();
    }
    else if((it->second).size()==1 && (it->second)[0].isAccount()=="일반 계좌"){
        sum=(it->second)[0].getBalance();
    }
    else{
        sum=(it->second)[0].getBalance()+(it->second)[0].getPoint();
    }
    return sum;
}

int Bank::getBalanceSum(Person p){
    int sum=0;
    auto it=accountList.find(p.getName());
    if((it->second).size()==2){
        sum=(it->second)[0].getBalance()+(it->second)[1].getBalance();
    }
    else{
        sum=(it->second)[0].getBalance();
    }
    return sum;
}

bool Bank::sendMoney(Person pf,Person pt,int m){
    /// @brief 송금 및 결제 용 함수
    ///         main()에서 송신인 전체 잔액이 내야할 금액보다 크거나 같은거 확인 후 들어와서 해당 사항 체크 안해줌
    /// @param pf : 보내는 사람 Person
    /// @param pt : 받는 사람 Person
    /// @param m : 송금(결제) 금액
    /// @return : 송신/수신인 계좌가 없는 경우 false 반환 // 송금 성공 시 true 반환
    string toAcc;
    int reductionAmount, accIdx;

    auto itf=accountList.find(pf.getName()); //pf 돈 m만큼 감소, 감소 성공하면 pt 돈 m만큼 증가
    auto itt=accountList.find(pt.getName());

    if(itf==accountList.end()){
        cout << ">> 송신인 " << pf.getName() << "님은 현재 계좌가 없습니다." << endl;
        return false;
    }
    if(itt==accountList.end()){
        cout << ">> 수신인 " << pt.getName() << "님은 현재 계좌가 없습니다." << endl;
        return false;
    }

    //// 1. 수신인 계좌 일단 채워주기
    if((itt->second).size() == 1)
        accIdx = 0;
    else{
        cout << "받는 이의 은행을 선택 바랍니다 [일반/카카오] >>";
        cin >> toAcc;
        accIdx = toAcc == "카카오" ? 0 : 1; // vector<Account> [0]카카오, [1]일반
    }
    (itt->second)[accIdx].setBalance((itt->second)[accIdx].getBalance() + m);
    
    
    //// 2. 송신인(나) 계좌에서 차감
    while (m > 0){
        // 1) 포인트 있는 경우
        if ((itf->second)[0].getPoint() > 0){
            reductionAmount = subtract((itf->second)[0], m, true);
            cout << "*** 포인트가 존재해서 " << reductionAmount << "[원]만큼 차감됩니다." << endl;
        }
        // 2) 포인트 없는 경우
        else{
            if((itf->second).size()==1)
            {   // (1) 계좌 1개만 있는경우
                subtract((itf->second)[0], m);
                cout << "*** " << (itf->second)[0].isAccount() << "에서 " << reductionAmount << "[원]만큼 차감됩니다." << endl;
            }
            else 
            {   // (2) 계좌 2개 있는경우
                cout << "송금을 진행할 계좌를 선택 바랍니다 [일반/카카오] >>";
                cin >> toAcc;
                accIdx = toAcc == "카카오" ? 0 : 1; // vector<Account> [0]카카오, [1]일반
                subtract((itf->second)[accIdx], m);
                cout << "*** " << (itf->second)[accIdx].isAccount() << "에서 " << reductionAmount << "[원]만큼 차감됩니다." << endl;
                if (m > 0){
                    accIdx = accIdx == 1 ? 0 : 1;
                    subtract((itf->second)[accIdx], m);
                    cout << "*** " << (itf->second)[accIdx].isAccount() << "에서 " << reductionAmount << "[원]만큼 차감됩니다." << endl;
                }
            }
        }
    }
    cout << endl;
    cout << ">>> 송금 완료 후 나의 계좌 상황" << endl;
    showAccount(itf);
    cout << endl;
    cout << "*** 수신인 " << pt.getName() << "님의 " << (itf->second)[0].isAccount() << "로 송금 되었습니다." << endl;
    cout << ">>> 송금 완료 후 수신인의 계좌 상황" << endl;
    showAccount(itt);
    cout << endl;
    return true;
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



int subtract(Account& a, int &m, bool isPoint){
    /// @brief 내야 할 돈이 m원일 때 a 계좌에서 빠지는경우
    /// @param a a계좌에서 빠져나감
    /// @param m  m만큼 빠져나감
    /// @param isPoint 포인트인지 현금인지 여부
    /// @return a계좌에서 차감되는 금액 반환

    int diff, reductionAmount;
    
    if (isPoint){
        diff = m - a.getPoint(); //diff >= 0 : 내야할 돈이 더 많은 경우 / 잔액이 충분한 경우
        reductionAmount = diff >= 0 ? a.getPoint() : m; //내잔액에서 차감되는 금액은 모두전체
        m = diff >= 0 ? diff : 0; //내야할돈은 해결안됐어 / 내야할돈 해결됨
        a.setPoint(diff >= 0 ? 0 : -diff); //내잔액은 모두 소진
    }else{
        diff = m - a.getBalance();
        reductionAmount = diff >= 0 ? a.getBalance() : m;
        m = diff >= 0 ? diff : 0;
        a.setBalance(diff >= 0 ? 0 : -diff);
    }
    
    return reductionAmount; 
}