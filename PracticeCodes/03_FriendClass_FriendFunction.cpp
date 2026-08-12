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