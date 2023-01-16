#pragma once
#include <iostream>
using namespace std;
#include <string>


// 职工抽象类：
// 子类有：员工，经理，老板
class Worker{
public:
    virtual void showInfo()=0;
    virtual string getDeptName()=0;
    virtual ~Worker() {

    };
    
    // Basics
    int id;
    string name;
    int deptID; 

    // Optional
    int age;
    int phoneNumber;
    string address;
}; 
//不打算实现任何这些函数，所以无需cpp文件