#include "System.h"
#include "useful.h"

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"


#include <sys/stat.h>
#include <errno.h>

#define DEBUG false // true if you want to see memory freeing
void create_directory(const char *path) {
    struct stat st;
    if (stat(path, &st) != 0) {
        // Does not exists
        if (errno == ENOENT) {
            // Definetly DNE
            mkdir(path, 0777);
        } else {
            // handle other errors
            MessageRed("other errors: please check create_directory");
            exit(0);
        }
    } else {
        //exists since stat==0
        if (!S_ISDIR(st.st_mode)) {
            // file exists but is not a directory
            MessageRed("file exists but is not a directory: please check create_directory");
            exit(0);
        }
    }
}
int System::getWorkerNumber(){
    ifstream file(FILENAME);
    string line;
    int size = 0;
    while(getline(file,line)){
        size++;
    }
    file.close();
    return size;
}
void System::LoadData(){
    // 构造函数在证实文件有效后调用
    ifstream file(FILENAME);
    string line;
    this->emp_arr = new Worker * [this->getWorkerNumber()];
    
    while(file.good()&&getline(file,line)){
        // Once the end of the file is reached, the getline function will return false, causing the loop to exit.

        int id;
        string name;
        int deptID;

        int prevSep; // location of the previous seperator

        // line.substr(start position,length of substring)
        // line.find(str, start pos OPTIONAL)
        id = stoi(line.substr(0,line.find(SEPERATOR)));
        prevSep=line.find(SEPERATOR);

        name = line.substr(prevSep+1,line.find(SEPERATOR,prevSep+1)-prevSep-1);
        prevSep=line.find(SEPERATOR,prevSep+1);

        deptID = stoi(line.substr(prevSep+1,line.find(SEPERATOR,prevSep+1)-prevSep-1));

        
        
        if(deptID==3){
            this->emp_arr[this->emp_num++] =new Boss(id,name,deptID);
        }else if(deptID==2){
            this->emp_arr[this->emp_num++] =new Manager(id,name,deptID);
        }else{
            this->emp_arr[this->emp_num++] =new Employee(id,name,deptID);
        }
        

        if(file.eof())break;// this is acceptable too. true if attempted to read before this line + actually  is eof

        // reason for -1 is b/c: say "1000\Zheng Zihao\1". First sep at 4, second at 16. Given that line.substr(start,len), to get name, we need to start at 5 (prevSep+1),and since the "line.find()"" would return 16, 16 - 5 (prevSep+1) = 11 (length of name), so length would be line.find()-prevSep-1

    }
    
    if(this->getWorkerNumber()!=this->emp_num){
        MessageRed("File Decode Error!"+to_string(this->getWorkerNumber())+" "+to_string(this->emp_num));
        exit(0);
    }
    file.close();
}
System::System(){
    this->emp_arr=NULL;
    this->emp_num=0; 

    ifstream file(FILENAME);
    // 1. 文件不存在 File does not exists
    if(!file.is_open()){
        file.close();
        return;
    }
    
    file.close();
    // 2. 文件空或有数据 Normal File
    this->LoadData();
}
System::~System(){
    // 释放堆区数据
    // Free Heap Data
    if(this->emp_arr!=NULL){
        for(int i=0;i<this->emp_num;i++){
            if(DEBUG==true){
                EnterLine("Freeing ");MessageGreen(this->emp_arr[i]->name);
            }
            delete this->emp_arr[i];
            this->emp_arr[i]=NULL;
        }
        if(DEBUG==true){
            EnterLine("Freeing ");MessageGreen("Whole System");
        }
        delete [] this->emp_arr;
        this->emp_arr=NULL;
        this->emp_num=0;
    }
} 
void System::SaveData(){
    // ofstream file;
	// file.open(FILENAME, ios::out);
    create_directory("local");
    ofstream file(FILENAME);

    if(file.is_open()){
        //The default mode for ofstream is to truncate the file when it is opened, which means that any existing data in the file will be deleted
        for(int i=0;i<this->emp_num;i++){
            file<< this->emp_arr[i]->id << SEPERATOR
                << this->emp_arr[i]->name   << SEPERATOR
                << this->emp_arr[i]->deptID << endl;
        }
        file.close();
    }else{
        MessageRed("Error");
        promptAnyKey();
    }
}
void System::add(){
    int n;
    Message("Enter the # of Workers to add: ");
    cin >> n;
    if(cin.fail()){
        clearInput();
        clearTerminal();
        System::add();
    }else if(n>10){
        clearInput();
        clearTerminal();
        MessageRed("Please enter a number less than 10");
        promptAnyKey();
        return;
    }else if(n<=0){
        clearInput();
        clearTerminal();
        MessageRed("Please enter a number greater than 0");
        promptAnyKey();
        // System::add();
        return;
    }

    int newSize = this->emp_num+n; // 新大小=原来+新增
    Worker ** newArr = new Worker* [newSize];// A pointer to an array, of array of pointers
    // * -> [*][*][*][*][*][*][*][*]

    //拷贝原来的数据
    if(this->emp_arr!=NULL){
        for(int i=0;i<this->emp_num;i++){
            // The heap memory of old is now 继承ed by new ptr
            newArr[i] = this->emp_arr[i]; 
        }
    }
    //添加新的数据
    for(int i=0;i<n;i++){
        // Want: enter $ then we quit adding. say accidentally enter n=3 but only had 1 in mind. No memory problems: even if we have extras spaces (NULL) in the 1D array due to quitting early, we wont have access to it due to emp_num (make sure emp_num=实际add人数), if we add a new person, we will free original array(one with extra spaces) and create a correct one (assuming no quitting)
        int id;
        int deptID;
        string name;

        // Getting ID
        while(true){
            clearTerminal();
            Message("Please enter the "+getOrdinal(i+1)+" Worker's ID");
            cin >> id;
            if(cin.fail()||id<0||searchByID(id)!=-1){
                clearInput();
                clearTerminal();
                if(searchByID(id)!=-1){
                    MessageRed("ID in use");
                }else{
                    MessageRed("Invalid ID");
                }
                promptAnyKey();
                continue;
            }
            clearInput();
            break;
        }
    
        // Getting Name
        clearTerminal();
        Message("Please enter the "+getOrdinal(i+1)+" Worker's name");
        getline(cin,name);
        name.erase(name.find_last_not_of(' ') + 1);

        // Getting Department ID
        while(true){
            clearTerminal();
            Message("Please enter the "+getOrdinal(i+1)+" Worker's Position");
            Message("1: Employee");
            Message("2: Manager");  
            Message("3: Boss");
            cin >> deptID;
            if(cin.fail()||deptID<1||deptID>3){
                clearInput();
                clearTerminal();
                MessageRed("Invalid Position");
                promptAnyKey();
                continue;
            }
            clearInput();
            break;
        }

        // Create the worker
        Worker * worker = NULL;
        switch(deptID){
            case 1:
                worker = new Employee(id,name,deptID);
            break;
            case 2:
                worker = new Manager(id,name,deptID);
            break;
            case 3:
                worker = new Boss(id,name,deptID);
            break;
        }
    
        newArr[this->emp_num+i]= worker;
    }

    //释放原有的数组 
    delete [] this->emp_arr;

    //更改新空间的指向
    this->emp_arr=newArr; 

    //更新人数
    this->emp_num=newSize;

    //提示信息
    clearTerminal();
    this->SaveData();
    Message("Sucessfully Added "+to_string(n)+" Worker(s)");
    promptAnyKey();
}
void System::showMenu(){
    cout << "********************************************" << endl;
    cout << "*******  \033[1;34mEmployee Management System\033[0m ********" << endl;
    cout << "*******        0.Exit System        ********" << endl;
    cout << "*******        1.Add Employee       ********" << endl;
    cout << "*******        2.Show All           ********" << endl;
    cout << "*******        3.Delete Employee    ********" << endl;
    cout << "*******        4.Modify Employee    ********" << endl;
    cout << "*******        5.Search Employee    ********" << endl;
    cout << "*******        6.Order List         ********" << endl;
    cout << "*******        7.Empty System       ********" << endl;
    cout << "********************************************" << endl;
}
void System::Exit(){
    clearTerminal();
    MessageGreen("Thanks for using Employee Management System");
    //this->~System();
    //exit(0);
}
void System::show(){
    if(this->emp_num<=0){
        clearTerminal();
        Message("No record availiable. Why not hire someone?");
        promptAnyKey();
        clearTerminal();
    }else{
        emptyTerminal();
        for(int i=0;i<this->emp_num;i++){
            this->emp_arr[i]->showInfo(); 
        }
        promptAnyKey();
        clearTerminal();
    }
}
void System::fireWorker(){ 
    if(this->emp_num<=0){
        clearTerminal();
        Message("No worker to be deleted. Why not hire someone?");
        promptAnyKey();
        return;
    }
    clearTerminal();
    Message("Enter the ID of the worker to remove from the system: ");
    int id;
    cin >> id;
    if(cin.fail()||id<0||searchByID(id)==-1){
        clearInput();
        clearTerminal();
        MessageRed("Invalid ID ");
        promptAnyKey();
        clearTerminal();
    }else{
        clearInput();
        clearTerminal();
        MessageRed("Are you sure you want to remove "+this->emp_arr[searchByID(id)]->name+" from the system?");
        MessageRed("This action CANNOT be undone! Enter YES to confirm and any other key to cancel action.");

        string key;
        getline(cin,key);

        if(key.substr(0,1)=="Y" || key.substr(0,1)=="y"){
            int index = searchByID(id);
            Worker * squid = this->emp_arr[index];
            for(int i=index;i<this->emp_num-1;i++){
                //数据迁移:前一个继承后一个的堆数据 别释放 否则出错
                this->emp_arr[i]=this->emp_arr[i+1];
            }
            delete squid;
            this->emp_num--;
            this->SaveData();
            Message("Sucessfully Deleted");
            promptAnyKey();
        }else{
            Message("Action Canceled");
            promptAnyKey();
        }
    }
}
int System::searchByID(int id){
    // Given the ID of the worker and returns the position in the array
    for(int i=0;i<this->emp_num;i++){
        if(this->emp_arr[i]->id == id){
            return i;
        }
    }
    return -1;
}
int System::searchByName(string name){
    // Given name, find the position in the array
    for(int i=0;i<this->emp_num;i++){
        if(this->emp_arr[i]->name == name){
            return i;
        }
    }
    return -1;
}

void System::find(){
    // determine if there is something in the system book
    if(this->emp_num<=0){
        clearTerminal();
        Message("Nothing in the book. Why not hire someone?");
        promptAnyKey();
        return;
    }
    clearTerminal();
    Message("Enter the WorkerID or Worker Name to show information of the Worker: ");
    string line;
    getline(cin,line);
    if(isInteger(line)){
        // Search By Worker ID

        /*
        Remove all spaces: given "1 2 "remove() removes all spaces from the range [ str.begin(), str.end() ), will modify to "122 " and return the position of second "2". The erase() function will remove everything from that to end -> "12"
        */
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
        
        if(searchByID(stoi(line))!=-1){
            //found
            clearTerminal();
            this->emp_arr[searchByID(stoi(line))]->showInfo();
        }else{
            //not found
            clearTerminal();
            MessageRed("Person Not Found: Invalid ID");
        }

    }else{
        // Search By Worker Name
        
        // removes all spaces at the end if availiable
        line.erase(line.find_last_not_of(' ') + 1);
        
        if(searchByName(line)!=-1){
            //found
            clearTerminal();
            for(int i=0;i<this->emp_num;i++){
                if(this->emp_arr[i]->name==line){
                    this->emp_arr[i]->showInfo();
                }
            }
        }else{
            //not found
            clearTerminal();
            MessageRed("Person Not Found: Invalid Name");
        }
    }   
    promptAnyKey();
    clearTerminal();
}
void System::modify(){
    // determine if there is something to modify
    if(this->emp_num<=0){
        clearTerminal();
        Message("Nothing to modify. Why not hire someone?");
        promptAnyKey();
        return;
    }
    clearTerminal();
    Message("Enter the ID of the worker to modify: ");
    int id;
    cin >> id;
    if(cin.fail()||id<0||searchByID(id)==-1){
        // User enters some string or invalid ID
        clearInput();
        clearTerminal();
        MessageRed("Invalid ID ");
        promptAnyKey();
        clearTerminal();
    }else{
        // User found 
        clearTerminal();
        int index = searchByID(id);
        int decision;
        bool modified =false;
        

        while(true){
            clearTerminal();
            string position;
            if(this->emp_arr[index]->deptID==3){
                position="BOSS";
            }else if(this->emp_arr[index]->deptID==2){
                position="MANAGER";
            }else{
                position="EMPLOYEE";
            }
            Message("Modifing "+this->emp_arr[index]->name+": Enter the specific digit to modify each listed field");
            MessageBlue(this->emp_arr[index]->name+":\tID->"+to_string(this->emp_arr[index]->id)+"\t Position->"+position);
            MessageGreen("1: Worker ID");
            MessageGreen("2: Worker Name");
            MessageGreen("3: Worker Rank (Promote/Demote)");
            MessageBlue("Any other key: Exit Modification");
            cin >> decision;

            if(cin.fail()||(decision!=1&&decision!=2&&decision!=3)){
                // User enters random string/char or non provided digits
                clearInput();
                clearTerminal();
                modified==false?Message("Action Cancelled"):Message("Sucessfully Saved");
                promptAnyKey();
                break;
            }
            clearInput();

            if(decision==1){
                // Getting ID
                int ID;
                while(true){
                    clearTerminal();
                    Message("Please enter the new ID");
                    cin >> ID;
                    if(cin.fail()||ID<0){
                        clearInput();
                        clearTerminal();
                        MessageRed("Invalid ID");
                        promptAnyKey();
                        continue;
                    }
                    clearInput();
                    modified=true;
                    break;
                }
                this->emp_arr[index]->id = ID;
            }else if(decision==2){
                // Getting Name
                string name;
                clearTerminal();
                Message("Please enter the new name");
                getline(cin,name);
                this->emp_arr[index]->name = name;
                modified=true;
            }else if(decision==3){
                // Getting Department ID
                int deptID;
                while(true){
                    clearTerminal();
                    Message("Please enter the new Worker's Position");
                    Message("1: Employee");
                    Message("2: Manager");  
                    Message("3: Boss");
                    cin >> deptID;
                    if(cin.fail()||deptID<1||deptID>3){
                        clearInput();
                        clearTerminal();
                        MessageRed("Invalid Position");
                        promptAnyKey();
                        continue;
                    }
                    clearInput();
                    // If position actually got modified
                    if(this->emp_arr[index]->deptID!=deptID){
                        modified=true;
                        //Get original data (other than position)
                        int ID= this->emp_arr[index]->id;
                        string name = this->emp_arr[index]->name;
                        //delete original object
                        delete this->emp_arr[index];
                        //create new object
                        if(deptID==3){
                            this->emp_arr[index] = new Boss(ID,name,deptID);
                        }else if(deptID==2){
                            this->emp_arr[index] = new Manager(ID,name,deptID);
                        }else{
                            this->emp_arr[index] = new Employee(ID,name,deptID);
                        }
                    }                    
                    break;
                }
            }
        
        }
        

        clearTerminal();
        if(modified==true){
            this->SaveData();
        }
        //BUG: save success but not immediate recognition by show(2)
        // FOUND: need to create new Manager or else no immediate show, after changing from boss -> manager
    }
}
void System::empty(){
    if(this->emp_num <= 0){
        clearTerminal();
        Message("Nothing in System. Why not hire someone?");
        promptAnyKey();
        return;
    }
    clearTerminal();
    MessageRed("CAUTION! This action cannot be undone. To confirm, enter the password");
    string line;
    string answer="666";
    getline(cin,line);

    if(line == answer){
        // Empty the system
        this->~System();
        this->SaveData();
        clearTerminal();
        MessageGreen("Emptied Sucessfully");
        promptAnyKey();

    }else{
        clearTerminal();
        MessageGreen("Action Canceled");
        promptAnyKey();
    }
    clearTerminal();
}
void System::sort(){
    if(this->emp_num<=0){
        clearTerminal();
        Message("Nothing to sort. Why not hire someone?");
        promptAnyKey();
        return;
    }
    clearTerminal();
    Message("How would you want to sort the workers?");
    Message("1: Ascending");
    Message("2: Descending");
    Message("other key: quit");

    string decision;
    getline(cin,decision);
    decision= decision.substr(0,1);
    if(decision == "1"){
        // BTW we could use binary sort or 冒泡
        clearTerminal();
        this->sortWorkersAscending();
        this->SaveData();
        Message("Sucessfully sorted in ascending order");

    }else if(decision =="2"){
        clearTerminal();
        this->sortWorkersDescending();
        this->SaveData();
        Message("Sucessfully sorted in descending order");

    }else{
        clearTerminal();
        Message("Action Canceled");
    }
    promptAnyKey();
}

void System::sortWorkersAscending() {
    std::sort(this->emp_arr, this->emp_arr + this->emp_num, [](Worker* a, Worker* b) {
        if (a->id == b->id) {
            return a < b;
        }
        return a->id < b->id;
    });
}
void System::sortWorkersDescending() {
    std::sort(this->emp_arr, this->emp_arr + this->emp_num, [](Worker* a, Worker* b) {
        if (a->id == b->id) {
            return a > b;
        }
        return a->id > b->id;
    });
}