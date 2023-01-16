#pragma once //防止头文件重复包含
#include <iostream>
#include <string>
using namespace std;

#include "useful.h"

#include "worker.h"

#include <fstream>
#include <algorithm>
#define  FILENAME "local/data.txt"
#define SEPERATOR '\\'

// The System
class System{
public:
    System();
    ~System();
    //显示菜单
    void showMenu();
    //退出系统
    void Exit();
    //记录职工人数
    int emp_num;
    //职工数组指针
    Worker ** emp_arr;
    //添加职工
    void add();
    void SaveData();
    void LoadData();
    int getWorkerNumber();
    void show();
    void fireWorker();
    void modify();
    void find();
    int searchByID(int id);
    int searchByName(string name);
    void empty();
    void sort();
    void sortWorkersAscending();
    void sortWorkersDescending();

}; 






