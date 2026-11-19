/*
Concept Explained: Constructors in C++

This program demonstrates the different kinds of constructors used to initialize objects.

1. Default constructor
   - Student() is called when no values are passed.
   - It initializes the object with default values, such as name = "Unknown" and age = 0.

2. Parameterized constructor
   - Student(string n, int a) accepts values and initializes the object with those values.
   - This is useful when object creation needs custom data from the start.

3. Default argument constructor
   - Student(string n, int a = 18) gives a default value for age if the caller does not provide it.
   - This reduces the need to overload construction logic unnecessarily.

4. Copy constructor
   - Student(Student &s) creates a new object as a copy of an existing one.
   - It copies each field from the source object.

5. Why constructors matter
   - Constructors automatically initialize objects when they are created.
   - They help create valid objects and reduce bugs caused by uninitialized data.
*/

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