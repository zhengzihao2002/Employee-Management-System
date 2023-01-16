#pragma once //防止头文件重复包含
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <fstream>
#include <limits>
#include <typeinfo>
#include <sstream>
using namespace std;


void clearTerminal();
void emptyTerminal();
void clearInput();
void Message(string message);
void MessageRed(string message);
void MessageGreen(string message);
void promptAnyKey();
void MessageBlue(string message);
void EnterLine(string message);
bool isInteger(const string &s);
std::string getOrdinal(int num);