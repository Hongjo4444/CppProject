#include "utils.h"


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
        if (keyin(choice, "ID는 숫자로만 기입 바랍니다.")){
            if (1 <= choice && choice <= 4)
                break;
        }
    }
    return choice;
}

void fileRead(EmployManage& mngr, ifstream& fin){
    string line;
	vector<string> v;
    
	while(getline(fin, line)){		
        v = parseLine(line);
        if (v.size() == 3){ // 일반
            mngr.addEmployee(Person(v[0], stoi(v[1]), v[2][0]), true);
        }else if (v.size() == 4){ // 미용사 
            mngr.addEmployee(SalonDesigner(v[0], stoi(v[1]), v[2][0], v[3]), true);
        }else{ // 택시
            mngr.addEmployee(TaxiDriver(v[0], stoi(v[1]), v[2][0], v[3], v[4]), true);
        }
	}
}

vector<string> parseLine(string line){
	int idx = -1;
	int start = 0;
	int n;
	vector<string> v;
	while(true){
		idx = line.find(",", start);
		if (idx == -1){
			// 없음
			v.push_back(line.substr(start));
			break;
		}else{
			// 있음
			n = idx - start;
			v.push_back(line.substr(start, n));
			start = idx+1;
		}
	}
	return v;
}