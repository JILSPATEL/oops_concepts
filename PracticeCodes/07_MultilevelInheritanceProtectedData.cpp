/*
Concept Explained: Multilevel Inheritance + Protected Members

This code demonstrates multilevel inheritance, where one class inherits from another and then another class inherits from that derived class.

1. Base class: Server
   - The class stores a serverName and defines a method ping().
   - The member serverName is declared in the protected section so that derived classes can access it.

2. Intermediate class: WebServer
   - WebServer inherits from Server.
   - It adds a new property, maxTraffic, and a custom method serveHTML().
   - Because serverName is protected in Server, WebServer can use it directly.

3. Another derived class: DatabaseServer
   - DatabaseServer also inherits from Server.
   - It adds database-specific behavior while reusing the common serverName and ping() functionality.

4. Why this is important
   - Multilevel inheritance helps design a hierarchy where common features are stored in a base class and specialized features are added in child classes.
   - Protected members allow derived classes to access parent data while keeping it inaccessible to unrelated classes.

5. Real-world example
   - A general Server class can be shared by web servers, database servers, and mail servers, each adding its own specialized features.
Example:

Animal
  ↑
 Dog
  ↑
Puppy
*/

#include <bits/stdc++.h>
using namespace std;

class Vehicle{
    protected:
        int maxSpeed;
    public:
        Vehicle(int speed){
            maxSpeed = speed;
            cout << "[Constructing Vehicle] Max Speed set to " << maxSpeed << " km/h.\n";
        }
        virtual ~Vehicle(){
            cout << "Destruct Vehicle" << endl;
        }
};

class FourWheeler: public Vehicle{
    protected:
        int numDoors;
    public:
        FourWheeler(int speed,int doors): Vehicle(speed){
            numDoors = doors;
            cout << "[Constructing FourWheeler] Number of doors set to " << numDoors << ".\n";
        }
        ~FourWheeler() override{
            cout << "Destruct FourWheeler" << endl;
        }       
};

class ElectricCar: public FourWheeler{
    protected:
        int batteryCapacity;
    public:
        ElectricCar(int speed,int doors,int capacity): FourWheeler(speed,doors){
            batteryCapacity = capacity;
            cout << "[Constructing ElectricCar] Battery capacity set to " << batteryCapacity << " kWh.\n";
        }
        void displayInfo(){
            cout << "Electric Car Info:\n";
            cout << "Max Speed: " << maxSpeed << " km/h\n";
            cout << "Number of Doors: " << numDoors << "\n";
            cout << "Battery Capacity: " << batteryCapacity << " kWh\n";
        }
        ~ElectricCar() override{
            cout << "Destruct Electric Car" << endl;
        }
};

int main(){
    int speed,doors,batCap;
    cout<<"Please Enter The Speed, No.of Doors and Battery Capacity : ";
    cin>>speed>>doors>>batCap;
    ElectricCar nexon(speed,doors,batCap);
    nexon.displayInfo();
    return 0;
}
