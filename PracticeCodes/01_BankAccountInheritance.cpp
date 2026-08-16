
#include <bits/stdc++.h>
using namespace std;

/*
Concept Explained: Inheritance + Encapsulation

This program demonstrates single-level inheritance using a banking example.

1. Base class: BankAccount
   - It stores the account number and balance.
   - The balance is kept private so that direct access from outside the class is not allowed.
   - The class provides public methods such as deposit(), withdraw(), and getBalance() to control how data is changed.

2. Derived class: savingAccount
   - It inherits the features of BankAccount using public inheritance.
   - The derived class adds its own member interest and method addInterest().
   - It reuses inherited methods like deposit() and getBalance() without rewriting them.

3. Why this is important
   - Inheritance promotes code reuse: we do not duplicate account logic in the savings account class.
   - Encapsulation protects sensitive data and ensures valid operations happen through methods.
   - This is a common design pattern in real-world systems where a specialized account type shares behavior from a general account type.

4. Real-world idea
   - A general bank account can be used for both checking and savings accounts.
   - The specific account type adds extra behavior such as interest calculation while inheriting common account functionality.
*/

class BankAccount{
  protected:
  string accountNumber;
  private:
  double balance;
  public:
  BankAccount(string accNo,double initBal):accountNumber(accNo),balance(initBal){}
  void deposit(double amount){
      if(amount>0){
          balance+=amount;
          cout<<"Deposited: "<<amount<<" New Balance is "<<balance<<endl;
      }
  }
  void withdraw(double amount){
      if(balance>amount){
          balance-=amount;
          cout<<"Withdraw: "<<amount<<" New Balance is "<<balance<<endl;
      }else{
          cout<<"Low balance"<<endl;
      }
  }
  
  double getBalance(){
      return balance;
  }
};


class savingAccount: public BankAccount{
    private:
    double interest;
    public:
    savingAccount(string accNo,double initBal,double rate): BankAccount(accNo, initBal), interest(rate) {}
    void addInterest(){
        double inte=getBalance()*(interest/100);
        cout<< "Applying " << interest << "% interest...\n";
        deposit(inte);
    }
};

int main()
{
    savingAccount myAcc("SAV0123",10000.0,6.5);
    myAcc.deposit(500.0);
    myAcc.withdraw(200.0);
    myAcc.addInterest();
    
    cout<<"Account Balance "<<myAcc.getBalance()<<endl;
    

    return 0;
}

/*
Output:
Deposited: 500 New Balance is 10500
Withdraw: 200 New Balance is 10300
Applying 6.5% interest...
Deposited: 669.5 New Balance is 10969.5
Account Balance 10969.5
*/