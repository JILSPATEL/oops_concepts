#include<bits/stdc++.h>
using namespace std;

class Student{
    string name;
    int age;
    public:
    Student():name("Unknown"), age(0){} // Default Constructor
    Student(string n,int a):name(n),age(a){} // Parameterized Constructor
    Student(string n,int a=18):name(n),age(a){} // Default Argument Constructor
    Student(Student &s):name(s.name),age(s.age){} // Copy Constructor
    void Display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};

int main(){
    Student s1; // Default Constructor
    s1.Display();
    Student s2("John",20); // Parameterized Constructor
    s2.Display();
    Student s3("Alice"); // Default Argument
    s3.Display();
    Student s4(s2); // Copy Constructor
    s4.Display();
    return 0;
}

/*
Output:
Name: Unknown
Age: 0
Name: John
Age: 20
Name: Alice
Age: 18
Name: John
Age: 20
*/