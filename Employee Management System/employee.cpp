#include "employee.h"

Employee::Employee(int id, string name, int deptID){
    this->deptID=deptID;
    this->id=id;
    this->name=name; 
}; 
void Employee::showInfo(){
    if(this->name.length()<=10){
        cout << "Worker ID: "<< this->id
            << "\t\tWorker Name: "<< this->name
            << "\t\t\tTitle: "<< this->getDeptName()
            << "\t\t\tTasks: Follow the managers' orders"
            << endl;
        return;
    }
    cout << "Worker ID: "<< this->id
            << "\t\tWorker Name: "<< this->name
            << "\t\tTitle: "<< this->getDeptName()
            << "\t\t\tTasks: Follow the managers' orders"
            << endl;
};
string Employee::getDeptName(){
    return "Regular Employee";
};