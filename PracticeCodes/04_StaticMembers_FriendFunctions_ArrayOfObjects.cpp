// This program demonstrates the following OOP concepts:
// 1. Static members: a shared variable across all objects of the class
// 2. Friend function: a non-member function that can access private data members
// 3. Array of objects: storing multiple employee objects in one array
// 4. Encapsulation: data members are private and accessed through member functions
// 5. Object-oriented behavior: initialize, display, and compare employee data
//
// Where these concepts are used:
// - totalEmployee is a static member used to count all employees.
// - compareSalary is a friend function used to access private employee data.
// - team[3] is an array of Employee objects created in main().

#include <bits/stdc++.h>
using namespace std;

// Employee class with static member, private data, friend function, and member functions
class Employee{
  private:
  string name;
  double salary;
  static int totalEmployee; // shared by all Employee objects
  
  public:
  void onboard(string empName,double sal){
      name=empName;
      salary=sal;
      totalEmployee++; // increment total employee count when a new employee is added
  }
  void display(){
      cout << "Name: " << name << " | Salary: $" << salary << "\n";
  }
  
  static void showHeadCount(){
      cout << "Total active employees across company: " << totalEmployee << "\n";
  }
  friend void compareSalary(Employee e1,Employee e2); // friend function can access private members
};

int Employee::totalEmployee=0; // define static member outside the class

void compareSalary(Employee e1,Employee e2){
    cout<<"\n[HR System] Comparing salaries of " << e1.name << " and " << e2.name << "...\n";

    if (e1.salary > e2.salary) {
        cout << "Result: " << e1.name << " earns more.\n";
    } else if (e2.salary > e1.salary) {
        cout << "Result: " << e2.name << " earns more.\n";
    } else {
        cout << "Result: Both employees earn the same.\n";
    }
};

int main(){
    Employee team[3]; // array of objects: 3 employees in one array
    
    // Assign data to each employee object
    team[0].onboard("Alice", 95000.0);
    team[1].onboard("Bob", 110000.0);
    team[2].onboard("Charlie", 85000.0);
    
    cout << "--- Current Team Roster ---\n";
    for(int i = 0; i < 3; i++) {
        team[i].display(); // access each object using array index
    }
    cout << "---------------------------\n\n";

    Employee::showHeadCount(); // static member function accessed with class name
    compareSalary(team[0],team[1]); // friend function compares first two employees
    compareSalary(team[0],team[2]); // friend function compares first and third employees
    return 0;
}