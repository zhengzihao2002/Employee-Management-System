# Simple Employee Management System 
Author: Zihao Zheng </br>
Date: 1/15/23

## 0. How to compile and run
**<span style="color:lightgreen;background-color:black">Compile + Run: make all</span>**</br>
A make file is provided. Do not edit the make file. simply type "make all" to compile,run, and delete the unnecessary files all at the same time.

## 1. Introdction

Employee Management System is a system that management system that could allow you to keep track of all your employees.

This is a C++ program that mocks the simple actions of Employee Management Systems.

It has the following feature:



* <span style="color:red">Add Employee</span>：adds a employee to the system
* <span style="color:red">Show all</span>：shows all the employee and their ID, position, and names in a orderly manner
* <span style="color:red">Delete</span>：deletes a employee based on given employee ID
* <span style="color:red">Modify</span>：changing their employee ID, name, or promote/demote an employee
* <span style="color:red">Search</span>：searches for a employee by their employee ID or their name
* <span style="color:red">Empty</span>：Empties out the employee system
* <span style="color:red">Order</span>：orders the list of employees by ascending or descending order, based on their employee ID
* <span style="color:red">Exit</span>：exits the contact book





## 2. Warm Tips
* The program saves information after it exits into a local text file. Although deletion of data files (local or safe files) will not cause any harm to the program nor will it act abnormally, do not attempt to delete it to prevent the loss your data.
* This program has not been only tested on MacOS. May not perform as usual on any other systems other than MacOS.
* Do not enter the backslash (\\) into the information of the Employee you are adding. This may lead to abnormal behavior.
* When programs prompts you to hit on any key, you should hit on any character key and follow by a enter key. This is to mock system("pause") on windows.
* Do not modify the data files by hand as you may mess up the system, cauing it to behave abnormally. This is strictly prohibited as it will cause the program to crash if not modified correctly, especially without experienced programmers.


## 3. Menu Options
```
********************************************
*******  Employee Management System ********
*******        0.Exit System        ********
*******        1.Add Employee       ********
*******        2.Show All           ********
*******        3.Delete Employee    ********
*******        4.Modify Employee    ********
*******        5.Search Employee    ********
*******        6.Order List         ********
*******        7.Empty System       ********
********************************************
```






## 4. Exiting the program
When user enters 0, the program exits:
```
********************************************
*******  Employee Management System ********
*******        0.Exit System        ********
*******        1.Add Employee       ********
*******        2.Show All           ********
*******        3.Delete Employee    ********
*******        4.Modify Employee    ********
*******        5.Search Employee    ********
*******        6.Order List         ********
*******        7.Empty System       ********
********************************************
Enter a option
0
```
Above is when "**<span style="color:skyblue">0</span>**" is entered.
Then, the program clears the terminal and displays the last message:
```
Thanks for using Employee Management System
```




## 5. Add a Employee
The required information to add a employee includes：name, employeeID, and position in the company





### 5.1 Testing adding a contact

1. Start Program
```
********************************************
*******  Employee Management System ********
*******        0.Exit System        ********
*******        1.Add Employee       ********
*******        2.Show All           ********
*******        3.Delete Employee    ********
*******        4.Modify Employee    ********
*******        5.Search Employee    ********
*******        6.Order List         ********
*******        7.Empty System       ********
********************************************
```
2. After Hitting 1 (Add Employee), it displays instructions
```
Enter the # of Workers to add: 
```
3. After completing all the required informations (below displays the adding of two workers)
```
Sucessfully Added 2 Worker(s)
Press any key to continue...
```
4. Hit any key to return back to normal display
```
********************************************
*******  Employee Management System ********
*******        0.Exit System        ********
*******        1.Add Employee       ********
*******        2.Show All           ********
*******        3.Delete Employee    ********
*******        4.Modify Employee    ********
*******        5.Search Employee    ********
*******        6.Order List         ********
*******        7.Empty System       ********
********************************************
```







## 6. Show all Employees

To show all contacts, the user must type "**<span style="color:skyblue">2</span>**" into the terminal
```
********************************************
*******  Employee Management System ********
*******        0.Exit System        ********
*******        1.Add Employee       ********
*******        2.Show All           ********
*******        3.Delete Employee    ********
*******        4.Modify Employee    ********
*******        5.Search Employee    ********
*******        6.Order List         ********
*******        7.Empty System       ********
********************************************
Enter a option
2
```
```
Worker ID: 1000         Worker Name: Zheng Zihao                Title: Boss                             Tasks: Give Managers Orders
Worker ID: 1001         Worker Name: Zhang Zifeng               Title: Boss                             Tasks: Give Managers Orders
Worker ID: 1002         Worker Name: Zhao Jinmai                Title: Manager                          Tasks: Serve the boss', order employees
Worker ID: 1003         Worker Name: Lin Zhaoxi                 Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1004         Worker Name: Lin Zaosheng               Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1005         Worker Name: Bao Xiaomeng               Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1006         Worker Name: Pei Zhi                    Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1007         Worker Name: Pei Donglai                Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1008         Worker Name: Qiu Yue                    Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1009         Worker Name: Ji Jiang                   Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1010         Worker Name: Bai Jingting               Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1011         Worker Name: Wang Youjun                Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1012         Worker Name: Fu Bohan                   Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1013         Worker Name: Wang Shengdi               Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1014         Worker Name: Hu Xianxu                  Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1015         Worker Name: Wang Ziwen                 Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1016         Worker Name: Zhao Liying                Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1017         Worker Name: Xiang Hanzhi               Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1018         Worker Name: Eva Li                     Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1019         Worker Name: Pei Qinghua                Title: Regular Employee                 Tasks: Follow the managers' orders
Press any key to continue...
```
By hitting on any key (Specifically the Enter key), it takes you back to main menu



## 7. Deleting a employee

To delete a contacts, the user must type "**<span style="color:skyblue">3</span>**" into the terminal

```
********************************************
*******  Employee Management System ********
*******        0.Exit System        ********
*******        1.Add Employee       ********
*******        2.Show All           ********
*******        3.Delete Employee    ********
*******        4.Modify Employee    ********
*******        5.Search Employee    ********
*******        6.Order List         ********
*******        7.Empty System       ********
********************************************
Enter a option
3
```
It will prompt you to enter the ID of the employee to delete. Press enter key to submit. If the person does not exist, this will show:
```
Invalid ID 
Press any key to continue...
```
If a person does exists, say deleting a employee that has ID 1000 this would show:
```
Are you sure you want to remove Zheng Zihao from the system?
This action CANNOT be undone! Enter YES to confirm and any other key to cancel action.
```
Enter YES to confirm the delete, and this would show:
```
Sucessfully Deleted
Press any key to continue...
```

## 8. Modifiying a Employee

To modify the information of an employee, user must enter "**<span style="color:skyblue">4</span>**" into the terminal

```
********************************************
*******  Employee Management System ********
*******        0.Exit System        ********
*******        1.Add Employee       ********
*******        2.Show All           ********
*******        3.Delete Employee    ********
*******        4.Modify Employee    ********
*******        5.Search Employee    ********
*******        6.Order List         ********
*******        7.Empty System       ********
********************************************
Enter a option
4
```
Then, enter the name of the desired contact followed by enter key. If the user does not exists:
```
Invalid ID 
Press any key to continue...
```
If it does exists:
```
Modifing Zheng Zihao: Enter the specific digit to modify each listed field
Zheng Zihao:    ID->1000         Position->BOSS
1: Worker ID
2: Worker Name
3: Worker Rank (Promote/Demote)
Any other key: Exit Modification
```
Enter any character and follow by enter key to exit


## 9. Searching for a employee

To delete a contacts, the user must type "**<span style="color:skyblue">5</span>**" into the terminal

Then, enter the name of the employee or its ID. If the employee does not exists:
```
Person Not Found: Invalid Name
Press any key to continue...
```
or, if entered all numbers [0-9]
```
Person Not Found: Invalid ID
Press any key to continue...
```
If it does exists:
```
Worker ID: 1000         Worker Name: Zheng Zihao                Title: Boss                             Tasks: Give Managers Orders
Press any key to continue...
```
Hit enter key to get back to the main menu


## 10. Ordering the employee list

To order the list, the user must type "**<span style="color:skyblue">6</span>**" into the terminal

Then it will prompt you to enter the way of sorting the workers
```
How would you want to sort the workers?
1: Ascending
2: Descending
other key: quit
```
Note that this is only sorting by their worker ID.
Suppose you Enter "2":
```
Sucessfully sorted in descending order
Press any key to continue...
```
Now looking using the Show all employees options we can verify this has suceeded:
```
Worker ID: 1019         Worker Name: Pei Qinghua                Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1018         Worker Name: Eva Li                     Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1017         Worker Name: Xiang Hanzhi               Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1016         Worker Name: Zhao Liying                Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1015         Worker Name: Wang Ziwen                 Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1014         Worker Name: Hu Xianxu                  Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1013         Worker Name: Wang Shengdi               Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1012         Worker Name: Fu Bohan                   Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1011         Worker Name: Wang Youjun                Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1010         Worker Name: Bai Jingting               Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1009         Worker Name: Ji Jiang                   Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1008         Worker Name: Qiu Yue                    Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1007         Worker Name: Pei Donglai                Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1006         Worker Name: Pei Zhi                    Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1005         Worker Name: Bao Xiaomeng               Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1004         Worker Name: Lin Zaosheng               Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1003         Worker Name: Lin Zhaoxi                 Title: Regular Employee                 Tasks: Follow the managers' orders
Worker ID: 1002         Worker Name: Zhao Jinmai                Title: Manager                          Tasks: Serve the boss', order employees
Worker ID: 1001         Worker Name: Zhang Zifeng               Title: Boss                             Tasks: Give Managers Orders
Worker ID: 1000         Worker Name: Zheng Zihao                Title: Boss                             Tasks: Give Managers Orders
```






## 11. Empty out the System
To delete a contacts, the user must type "**<span style="color:skyblue">7</span>**" into the terminal

```
CAUTION! This action cannot be undone. To confirm, enter the password
```
After entering **<span style="color:red">666</span>**, the BOSS password, it will display:
```
Emptied Sucessfully
Press any key to continue...
```
Now using the show all option to verify:
```
No record availiable. Why not hire someone?
Press any key to continue...
```


# <span style="color:lightgreen; background-color:black" >This concludes everything for the Employee Management System!</span>


