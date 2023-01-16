#include "boss.h"

Boss::Boss(int id, string name, int deptID){
    this->deptID=deptID;
    this->id=id;
    this->name=name; 
}; 
void Boss::showInfo(){
    cout << "Worker ID: "<< this->id
            << "\t\tWorker Name: "<< this->name
            << "\t\tTitle: "<< this->getDeptName()
            << "\t\t\t\tTasks: Give Managers Orders"
            << endl;
};
string Boss::getDeptName(){
    return "Boss";
};