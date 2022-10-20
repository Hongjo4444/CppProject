#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cctype>
#include <exception>
using namespace std;
#include "person.h"
#include "salon.h"
#include "taxiDriver.h"
#include "employManage.h"
#include "bank.h"
constexpr int w = 20;

bool initPage(int& choice);
bool createAccountPage(string& name, int& id, char& gender, string& job);
bool keyin(T& n, string errMsg);
bool getPerson(EmployManage& mngr, Person &p, string cmdMsg, string errMsg);
int funcPage();


int main(){ 
    Bank banker;
    EmployManage mngr;
    Person p, p2;
    string name, job, type;
    int id, amount, choice, balance, driverId, fee;
    char gender;
    vector<Person>::iterator it;
    choice = -1;
    srand((unsigned)time(NULL));
            
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
            cout << ">> 추가 되었습니다." << endl;
            break;
        case 2: // 로그인
            if (getPerson(mngr, p, "아이디 입력 >>", "ID는 숫자로만 기입 바랍니다")){
                cout << "login 성공: " << p.getName() << endl;
                switch(funcPage()){
                case 1: // 계좌 생성
                case 2: // 계좌 송금
                    if (getPerson(mngr, p2, "받는 사람 아이디 >>", "ID는 숫자로만 기입 바랍니다"))
                    balance = banker.showAccount(p);
                    cout << "이체 금액 (송금 가능 금액: " << balance << "[원]) >>";
                    while (true){
                        keyin(amount, "이체 금액은 숫자로 입력 바랍니다");
                        if (amount > balance)
                            cout << "잔액보다 큰 금액이 입력되었습니다. " << balance << "원 이하로 입력바랍니다" << endl;
                        else if (amount < 0)
                            cout << "0보다 큰 금액 입력바랍니다." << endl;
                        else
                            break;
                    }
                    banker.sendMoney(p, p2, amount);
                    cout << ">> " << p.getName() <<"님 계좌에서 " << p2.getName() << "님 계좌로 " << amount << "원 이체가 완료되었습니다." << endl;
                    cout << ">> 이체 후 " << p.getName() <<" 잔액: " << banker.showAccount(p) << "원" << endl;
                    break;
                case 3: // 택시 이용
                    // cout << "이용할 택시 종류 선택 [우등/일반] >>";
                    // cin >> type;
                    // fee = calcAmount(); // 거리입력해서 요금 먼저 확인함
                    // balance = banker.showAccount(p); // 현재 계좌잔액으로 비교해서
                    // if (balance < fee){
                    //     cout << "잔액부족으로 승차가 거부되었습니다" << endl;
                    //     break;
                    // }
                        


                    // driverId = mngr.selectDriver(type);
                    // p2 = *(mngr.getPerson(driverId));
                    
                    // calcAmount()
                    break;
                case 4: // 미용실 이용
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
        }
    }
    
}


bool initPage(int& choice){
    string c;
    
    cout << setw(w) << setfill('-') << '-' << endl;
    cout << setw(w) << left << setfill(' ') << "1. 회원가입" << endl;
    cout << setw(w) << left << setfill(' ') << "2. 로그인" << endl;
    cout << setw(w) << left << setfill(' ') << "3. 종료" << endl;
    cout << setw(w) << setfill('-') << '-'  << endl;

    cout << "원하는 기능을 선택해주세요 >>";
    cin >> c;

    if (c == "1" || c == "2" || c == "3"){
        choice = stoi(c);
        return true;
    }else{
        cout << "[1,2,3] 중 선택하세요." << endl;
        return false;
    }
}

bool createAccountPage(string& name, int& id, char& gender, string& job){
    try
    {
        string tmp;
        cout << setw(w) << setfill('-') << '-' << endl;
        ///////
        cout << "1) 이름 >>";
        cin >> name;
        ///////
        cout << "2) 아이디 [숫자만 입력] >>";
        keyin(id, "ID는 숫자로만 기입 바랍니다.");
        ///////
        cout << "3) 성별 [M/F] >>";
        cin >> tmp;
        if (tmp == "M" || tmp == "F")
            gender = tmp[0];
        else
            throw "[M/F] 중 선택해주세요";
        ///////
        cout << "4) 직업 [택시운전사/미용사/기타] >>";
        cin >> job;
        if (job != "택시운전사" & job != "미용사" & job != "기타")
            throw "[택시운전사/미용사/기타] 중 선택해주세요";
        return true;
    }catch (char const* s) {
        cout << s << endl;
        cin.ignore(100, '\n');
        return false;
    }
}


template <class T>
bool keyin(T& n, string errMsg){ // 입력타입 오류 여부 확인 함수
    try{
        cin >> n;
        if (cin.fail()){  throw 1;  }
        return true;
    }catch(int i) {
        cin.clear();
        cout << errMsg << endl;
        cin.ignore(100, '\n');
        return false;
    }
}

bool getPerson(EmployManage& mngr, Person &p, string cmdMsg, string errMsg){ 
    int id;
    cout << setw(w) << setfill('-') << '-' << endl;
    while (true){
        cout << cmdMsg;
        if (keyin(id, errMsg)) break;
    }

    vector<Person>::iterator it = mngr.getPerson(id);
    if (it->getName() == "")
        return false;
    p = *it;
    return true;
}



int funcPage(){
    int choice;
    while (true){
        cout << setw(w) << setfill('-') << '-' << endl;
        cout << "1. 계좌 생성" << endl;
        cout << "2. 계좌 이체" << endl;
        cout << "3. 택시 부르기" << endl;
        cout << "4. 미용실 가기" << endl;
        cout << setw(w) << setfill('-') << '-' << endl;
        if (keyin(choice, "ID는 숫자로만 기입 바랍니다."))
            if (1 <= choice && choice <= 4)
                break;
    }
    return choice;
}