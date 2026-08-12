
#include <bits/stdc++.h>
using namespace std;

/*
Topic explained:
- Inheritance: savingAccount inherits the properties and behavior of BankAccount.
- Encapsulation: account data like balance is protected/kept private and accessed via methods.
- Method overriding is not used here; instead, the derived class reuses inherited methods.
- This example demonstrates single-level inheritance and the use of base-class methods in a child class.
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