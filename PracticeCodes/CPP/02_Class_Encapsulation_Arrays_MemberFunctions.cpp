
/*
Concept Explained: Encapsulation + Class Design + Arrays of Data

This program models a shop inventory system using a class.

1. Class design
   - The class ShopInventory is created to manage a collection of items.
   - It keeps itemId[] and itemPrice[] inside the class as private data members.
   - The user cannot directly change the internal data without going through class methods.

2. Encapsulation
   - The private members are hidden from outside access.
   - The public methods setItem() and display() provide controlled access to the data.
   - The private validation function isValid() ensures that invalid prices are rejected.

3. Arrays within a class
   - The class uses arrays to store many product records.
   - The counter variable tracks how many items are currently stored.

4. Why this matters
   - A class can represent a real-world entity, such as an inventory, while protecting its internal state.
   - This prevents accidental corruption and keeps the object reliable.

5. Real-world use case
   - A retail system can store product details like product ID and price using a class-managed inventory.
*/

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