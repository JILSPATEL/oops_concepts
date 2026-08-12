
// This program demonstrates the following OOP concepts:
// 1. Class creation and object instantiation
// 2. Encapsulation using private data members and public member functions
// 3. Use of arrays inside a class to store multiple records
// 4. Member functions for initialization, validation, and display
// 5. Access control to protect internal data

#include <bits/stdc++.h>
using namespace std;

class ShopInventory{
  private:
  int itemId[100];
  double itemPrice[100];
  int counter;
  bool isValid(double price){
      if(price>=0){
          return true;
      }
      return false;
  }
  public:
  void initCounter(){
      counter=0;
  }
  void setItem(int id,double price){
      if(counter>=100){
          cout<<"Enventory Full"<<endl;
          return;
      }
      if(isValid(price)){
          itemId[counter]=id;
          itemPrice[counter]=price;
          counter++;
          cout<<"Success Item "<<id<<" added to inventory.\n";
      }else{
          cout<<"Please Enter Valid Price.\n";
      }
  }
  void display(){
      for(int i=0;i<counter;i++){
          cout<<"Item with Id "<<itemId[i]<<" has price "<<itemPrice[i]<<endl;
      }
  }
};

int main()
{
    ShopInventory myShop;
    
    myShop.initCounter();
    myShop.setItem(101,150.5);
    myShop.setItem(102,50.25);
    myShop.setItem(103,-10.5);
    myShop.setItem(104,225.56);
    myShop.display();

    return 0;
}