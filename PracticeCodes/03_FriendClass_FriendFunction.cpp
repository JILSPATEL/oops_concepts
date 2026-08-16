/*
Concept Explained: Friend Function + Friend Class

This file demonstrates how friend functions and friend classes can access private members of a class even though they are not members themselves.

1. Friend function
   - A friend function is declared inside a class using the friend keyword.
   - It is not a member function, but it has access to the private and protected members of that class.
   - This is useful when an external utility needs to work with hidden data.

2. Friend class
   - A friend class can access all private members of the class it is declared as a friend of.
   - This is useful when one class is designed to inspect or validate the internal state of another class.

3. Why this is useful
   - The friend mechanism is used when a function or class logically belongs to another class but should not be a member function.
   - It allows controlled access without exposing all data publicly.

4. Important note
   - Friend access is a special-case feature. It is powerful, but it should be used carefully because it breaks strict encapsulation in a controlled way.
*/

#include <bits/stdc++.h>
using namespace std;
//1. Friend Function
class Box{
    private:
    int width;

    public:

    Box(int w){
        width=w;
    }

    friend void printWidth(Box b);
};

void printWidth(Box b){
    cout<<"Width of box : "<<b.width<<endl;
};

int main()
{
    Box b(10);
    printWidth(b);

    return 0;
}

//2. Friend Class
class Bank{
    private:
    int balance;

    public:
    Bank(int b){
        balance=b;
    }
    friend class Auditor;
};

class Auditor{
    public:
    void audit(Bank b){
        cout<<"Auditing bank balance : "<<b.balance<<endl;
    }
};

int main(){
    Bank b(1000);
    Auditor a;
    a.audit(b);

    return 0;
}