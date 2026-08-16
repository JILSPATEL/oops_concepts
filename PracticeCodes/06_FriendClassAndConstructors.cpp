/*
Concept Explained: Friend Class + Constructors

This file combines two important OOP ideas: constructor-based initialization and friend-class access.

1. Constructors
   - UserAccount has a default constructor and a parameterized constructor.
   - The default constructor creates a guest account with a default balance and pincode.
   - The parameterized constructor initializes the object using provided values.

2. Friend class
   - SystemAuditor is declared as a friend of UserAccount.
   - This allows the auditor to access the private data members username, balance, and pincode.
   - The auditor can inspect or validate account information without exposing the data publicly.

3. Why this matters
   - Constructors ensure that every object starts in a valid state.
   - Friend classes provide controlled access when an external class needs to work with internal data.

4. Real-world use case
   - A banking or security system may have an auditing class that checks account details without changing the account’s public interface.
*/

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