#pragma once 
#include <string>
#include <fstream>
#include <iomanip>
#include <exception>
#include <iostream>
using namespace std;
#include "salon.h"
#include "taxiDriver.h"
#include "person.h"
#include "employManage.h"
constexpr int w = 20;

bool initPage(int& choice);
bool createAccountPage(string& name, int& id, char& gender, string& job);
template<class T> bool keyin(T& n, string errMsg);
bool getPerson(EmployManage& mngr, Person &p, string cmdMsg, string errMsg);
int funcPage();
void fileRead(EmployManage& mngr, ifstream& fin);
vector<string> parseLine(string line);