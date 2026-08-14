#include <bits/stdc++.h>
using namespace std;

class SystemAuditor;

class UserAccount{
    string username;
    double balance;
    int pincode;
    friend class SystemAuditor; // Friend Class Declaration
    public:
    UserAccount():username("guest"), balance(0.0), pincode(1234) {
        cout<<"Default User Account Created for "<<username<<endl;
    }
    UserAccount(string u, double b, int p):username(u), balance(b), pincode(p) {
        cout<<"User Account Created for "<<username<<endl;
    }
};

class SystemAuditor{
    public:
    void runAudit(const UserAccount &user){
        cout<<"\n[System Auditor] Running audit for user: "<<user.username<<endl;
        cout<<"Balance: $"<<user.balance<<endl;
        cout<<"Pincode: "<<user.pincode<<endl;
    }
};

int main(){
    UserAccount u1; // Default Constructor
    UserAccount u2("Alice", 1500.75, 4321); // Parameterized Constructor
    SystemAuditor auditor;
    auditor.runAudit(u2); // Accessing private members of UserAccount through friend class
    return 0;

}

/*
Output:
Default User Account Created for guest
User Account Created for Alice
[System Auditor] Running audit for user: Alice
Balance: $1500.75
Pincode: 4321
*/