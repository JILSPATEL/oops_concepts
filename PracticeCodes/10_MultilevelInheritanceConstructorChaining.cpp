/*
Concept Explained: Multilevel Inheritance + Constructor Chaining

This program demonstrates constructor chaining in a multilevel inheritance hierarchy.

1. Base class: Employee
   - It stores the common employee ID.
   - The constructor initializes empId as soon as an Employee object is created.

2. Intermediate class: Manager
   - Manager inherits from Employee.
   - It adds teamSize and calls Employee(id) in its constructor initializer list.
   - This ensures the parent constructor runs before the derived constructor body executes.

3. Final class: Executive
   - Executive inherits from Manager and adds stockOptions.
   - It calls Manager(id, team) in its initialization list, which in turn triggers Employee(id).

4. Why constructor chaining matters
   - In C++, the base class constructor must be executed before the derived class is fully initialized.
   - This guarantees that inherited data members are already available when child class logic runs.

5. Real-world idea
   - A company hierarchy often follows this structure: Employee -> Manager -> Executive.
   - Each level adds more specific information while reusing common base-class data.
*/

#include <bits/stdc++.h>
using namespace std;

class Employee{
    protected: 
        int empId;
    public:
        Employee(int id):empId(id){
            cout<<"[Constructing Employee] Employee ID set to "<<empId<<endl;
        }
};

class Manager: public Employee{
    protected:
        int teamSize;
    public:
        Manager(int id,int team):Employee(id),teamSize(team){
            cout<<"[Constructing Manager] Team Size set to "<<teamSize<<endl;
        }   
};

class Executive:public Manager{
    private:
        int stockOptions;
    public:
        Executive(int id,int team,int stock):Manager(id,team),stockOptions(stock){
            cout<<"[Constructing Executive] Stock Options set to "<<stockOptions<<endl;
        }
        void displayInfo(){
            cout<<"Executive ID: "<<empId<<", Team Size: "<<teamSize<<", Stock Options: "<<stockOptions<<endl;
        }
};

int main(){
    Executive exec(100,5,200);
    exec.displayInfo();
    return 0;
}