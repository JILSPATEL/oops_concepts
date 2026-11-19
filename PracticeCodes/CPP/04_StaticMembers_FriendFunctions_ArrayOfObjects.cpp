/*
Concept Explained: Static Members + Friend Function + Array of Objects

This example models an employee system that keeps track of staff and compares salaries.

1. Static member
   - totalEmployee is declared as static inside the Employee class.
   - It is shared among all objects of the class instead of being recreated for each object.
   - This allows the system to track the total number of employees globally.

2. Friend function
   - compareSalary() is a standalone function but is declared as a friend of Employee.
   - It can access the private data members name and salary.
   - This is useful for operations that compare or analyze multiple objects.

3. Array of objects
   - The program creates an array named team[3] to hold three Employee objects.
   - This is a common pattern when several objects of the same class are managed together.

4. Encapsulation and organization
   - Employee data is hidden using private members.
   - Public methods like onboard() and display() control how data is entered and shown.

5. Real-world use
   - HR systems often keep employee records and analyze salary levels, headcount, and employee information.
*/

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