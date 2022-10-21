#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
using namespace std;
#include "person.h"
#include "salon.h"
#include "taxiDriver.h"
#include "employManage.h"
#include "bank.h"
#include "utils.h"



int main(){ 
    Bank banker;
    EmployManage mngr;
    Person p, p2;
    string name, job, type, accType;
    int id, amount, choice, balance, driverId, designerId;
    char gender;
    vector<Person>::iterator it;
    choice = -1;
    int i = 0;
    srand((unsigned)time(NULL));
    map<string,vector<Account>>::iterator itForDel;

    ifstream fin("data.txt");
    if (!fin){
        cout << "data.txt 열 수 없음" << endl;
    }else{
        fileRead(mngr, fin);
        mngr.showList();
    }
            
    while (true){
        while (!initPage(choice)) {}
        
        switch (choice)
        {
        case 1: // 계정생성 
            while (!createAccountPage(name, id, gender, job)){ }
            
            if (job == "택시운전사"){
                cout << "택시 종류 선택 [일반/우등] >>";
                cin >> type;
                mngr.addEmployee(TaxiDriver(name, id, gender, job, type));
            }
            else if (job == "미용사")
                mngr.addEmployee(SalonDesigner(name, id, gender, job));
            else
                mngr.addEmployee(Person(name, id, gender, job));
            break;
        case 2: // 로그인
            if (getPerson(mngr, p, "아이디 입력 >>", "ID는 숫자로만 기입 바랍니다")){
                cout << "login 성공: " << p.getName() << endl;
                switch(funcPage()){
                case 1: // 계좌 생성
                    banker.addAccount(p);
                    break;
                case 2: // 계좌 송금
                    if (getPerson(mngr, p2, "받는 사람 아이디 >>", "ID는 숫자로만 기입 바랍니다"))
                    balance = banker.getAccountSum(p);
                    cout << "이체 금액 (송금 가능 금액: " << balance << "[원]) >>";
                    while (true){
                        keyin(amount, "이체 금액은 숫자로 입력 바랍니다");
                        if (amount > balance)
                            cout << "잔액 (" << balance << "원) 이하로 입력 바랍니다 >>";
                        else if (amount < 0)
                            cout << "0보다 큰 금액 입력바랍니다 >>";
                        else
                            break;
                    }
                    if (banker.sendMoney(p, p2, amount)){
                        cout << ">> " << p.getName() <<"님 계좌에서 " << p2.getName() << "님 계좌로 " << amount << "원 이체가 완료되었습니다." << endl;
                        // cout << ">> 이체 후 " << p.getName() <<" 잔액: " << banker.getAccountSum(p) << "원" << endl;
                    }else
                        cout << ">> 이체를 실패했습니다." << endl;
                    break;
                case 3: // 택시 이용
                    cout << "이용할 택시 종류 선택 [우등/일반] >>";
                    cin >> type;
                    driverId = mngr.selectPerson(type);
                    p2 = *(mngr.getPerson(driverId));
                    amount = p2.calcAmount(); // 거리입력해서 요금 먼저 확인함
                    cout << ">> 요금은 " << amount << "[원] 입니다." << endl;
                    balance = banker.getAccountSum(p); // 현재 계좌잔액으로 비교해서
                    if (balance < amount){
                        cout << "잔액부족으로 승차가 거부되었습니다" << endl;
                        break;
                    }
                    cout << ">> " << p2.getName() << " 기사님이 선정되었습니다" << endl;
                    cout << ">> 이동 중";
                    i = 0;
                    while (1){
                        if(i%100000==0) {
                            putchar('.');
                            fflush(stdout);
                            //i=0;
                        }else if (i==400000)
                            break;
                        i++;
                    }
                    cout << "\n>> 결제가 진행됩니다" << endl;
                    if (banker.sendMoney(p, p2, amount))
                        cout << ">> 결제 후 " << p.getName() <<" 잔액: " << banker.getAccountSum(p) << "원" << endl;
                    else
                        cout << ">> 결제를 실패했습니다." << endl;
                    break;
                case 4: // 미용실 이용
                    designerId = mngr.selectPerson();
                    p2 = *(mngr.getPerson(designerId));
                    p2.setCustomerGender(p.getGender());
                    amount = p2.calcAmount();
                    cout << ">> 요금은 " << amount << "[원] 입니다." << endl;
                    balance = banker.getAccountSum(p); // 현재 계좌잔액으로 비교해서
                    if (balance < amount){
                        cout << "잔액부족으로 미용실 출입이 제한됩니다" << endl;
                        break;
                    }
                    cout << ">> " << p2.getName() << " 디자이너가 미용을 완료했습니다" << endl;
                    cout << "\n>> 결제가 진행됩니다" << endl;
                    if (banker.sendMoney(p, p2, amount))
                        cout << ">> 결제 후 " << p.getName() <<" 잔액: " << banker.getAccountSum(p) << "원" << endl;
                    else
                        cout << ">> 결제를 실패했습니다." << endl;
                    break;
                case 5: // 계좌 삭제
                    itForDel==banker.getIterbyName(p.getName());
                    banker.showAccount(itForDel);
                    break;
                case 6: // 로그아웃
                    cout << "종료합니다." << endl;
                    exit(1);
                    break;
                }
            }else{
                cout << "login 실패" << endl;
            }
            break;
        case 3: //종료 
            cout << "종료합니다." << endl;
            exit(1);
            break;
        case 4:
            banker.showAllAccount();
            break;            
        }
    }
    
}

