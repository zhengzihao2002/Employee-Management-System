#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
#include "useful.h"

class Boss : public Worker{
public:
    Boss(int id, string name, int deptID); 
    void showInfo();
    string getDeptName();
};