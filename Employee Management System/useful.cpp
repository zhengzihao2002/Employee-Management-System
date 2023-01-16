#include "useful.h"
using namespace std;
void clearTerminal(){
    system("clear"); // clear only the visual portion
}
void emptyTerminal(){
    Message("\033c"); // completely clear the terminal screen
}
void clearInput(){
    // ONLY call this function when cin is used! not getline getchar whatever
    // try to use getline or getchar so you dont have to clearInput()

    // if there is a error in cin and cin stopped working
    if(cin.fail()){
        //clear the error state of the input stream
        cin.clear();
        //ignore any additional characters that may be in the input stream
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    // if there is still leftovers in cin buffer
    else if(cin.eof()==false){
        // or cin.peek()!=EOF
        // If the ignore function is called repeatedly and it is not encountering the delimiter character, it will get stuck in an infinite loop, causing the program to hang.
        //input not empty
        //ignore any additional characters that may be in the input stream
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
void Message(string message){
    cout<<message<<endl;
    // consider puts(".....");
}
void MessageRed(string message){
    string newMessage ="\033[1;31m" + message + "\033[0m";
    cout<< newMessage << endl;
}
void MessageGreen(string message){
    string newMessage ="\033[1;32m" + message + "\033[0m";
    cout<< newMessage << endl;
}
void MessageBlue(string message){
  string newMessage ="\033[1;34m" + message + "\033[0m";
  cout<< newMessage << endl;
}
void EnterLine(string message){
    cout<< message;
}
void promptAnyKey(){
    MessageGreen("Press any key to continue...");
    getchar();
}

bool isInteger(const string &s){
    for (char c : s) {
        if (!isdigit(c)) {
            if(c==' '){
                continue;
            }
            return false;
        }
    }
    return true;
}
std::string getOrdinal(int num) {
    std::string ordinal;
    std::stringstream ss;
    ss << num;
    ordinal = ss.str();

    if (num % 100 == 11 || num % 100 == 12 || num % 100 == 13) {
        ordinal += "th";
    } else if (num % 10 == 1) {
        ordinal += "st";
    } else if (num % 10 == 2) {
        ordinal += "nd";
    } else if (num % 10 == 3) {
        ordinal += "rd";
    } else {
        ordinal += "th";
    }
    return ordinal;
}
