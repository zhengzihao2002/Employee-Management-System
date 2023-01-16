#include <iostream>
#include <string>

#include "System.h"
#include "useful.h"

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
//                       runner
//                   /          ｜
//              system           Worker   
//                            employee,mana,boss

using namespace std;



int main(){  
    System system;
    int choice;
    while(true){
        system.showMenu();
        Message("Enter a option");
        cin >> choice;
        if(cin.fail() || choice>7 || choice<0){
            // if user enters any other number not provided, or any unknown string/character, clear out cin and clear out terminal, continue looping
            clearInput();
            clearTerminal();
            continue;
        }
        clearInput();

        switch(choice){
            case 0: // exit
                system.Exit();
                return 0;
                break;
            case 1: // adds a employee
                system.add();
                break;
            case 2: // show all employee
                system.show();
                break;
            case 3: // deletes an employee
                system.fireWorker();
                break;
            case 4:  // modify employee
                system.modify();
                break;
            case 5: // searchs for a employee
                system.find();
                break;
            case 6: //orders the list of employee
                system.sort();
                break;
            case 7: //empties out the system 
                system.empty();
                break;
            case 666: 
                //Boss mode: under construction
                break;
            case 888: 
                //Computer mode: under construction (hooks up with another program such as a Javascript request )
                break;
            default:
                break;
        }
        clearTerminal();
    }


    promptAnyKey();
    return 0;
} 