#include "manager.h"

Manager::Manager(int id, string name, int deptID){
    this->deptID=deptID;
    this->id=id;
    this->name=name; 
}; 
void Manager::showInfo(){
    cout << "Worker ID: "<< this->id
            << "\t\tWorker Name: "<< this->name
            << "\t\tTitle: "<< this->getDeptName()
            << "\t\t\t\tTasks: Serve the boss', order employees"
            << endl;
};
string Manager::getDeptName(){
    return "Manager";
};