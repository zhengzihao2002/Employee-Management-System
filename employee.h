 #pragma once
 #include <iostream>
 using namespace std;
 #include "worker.h"
 #include "useful.h"

 class Employee : public Worker{
    public:
    Employee(int id, string name, int deptID); 
    void showInfo();
    string getDeptName();
 };