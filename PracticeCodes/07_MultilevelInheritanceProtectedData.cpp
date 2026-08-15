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
