/*
Concept Explained: Hierarchical Inheritance + Destructor Order

This file demonstrates hierarchical inheritance, where one base class is shared by multiple derived classes.

1. Base class: Vehicle
   - It stores the common property maxSpeed.
   - The destructor is virtual, which is important for safe resource cleanup in inheritance-based systems.

2. Derived class: FourWheeler
   - It inherits from Vehicle and adds numDoors.
   - A FourWheeler is a more specific vehicle type.

3. Derived class: ElectricCar
   - It inherits from FourWheeler and adds batteryCapacity.
   - ElectricCar reuses the properties of the vehicle hierarchy while extending functionality.

4. Destructor order
   - When an object of ElectricCar is destroyed, the destructors are called in reverse order of construction.
   - First ElectricCar destructor runs, then FourWheeler destructor, and finally Vehicle destructor.

5. Why this matters
   - Hierarchical inheritance helps model a family of related classes with shared behavior and unique specialized data.
   - Virtual destructors prevent undefined behavior when base-class pointers are used with derived objects.

Example:
                 ┌───────────────┐
                 │   Base Class  │
                 │    Animal     │
                 └───────┬───────┘
                         │
              ┌──────────┴──────────┐
              │                     │
              ▼                     ▼
       ┌─────────────┐       ┌─────────────┐
       │    Dog      │       │     Cat     │
       │ Derived     │       │   Derived   │
       └─────────────┘       └─────────────┘
*/

#include <bits/stdc++.h>
using namespace std;

class Server{
    Protected:
        string serverName;
    Public:
        Server(string name){
            serverName=name;
            cout<<"[Constructing Server] Server Name set to "<<serverName<<endl;
        }
        ~Server(){
            cout<<"Destruct Server"<<endl;
        }
        void ping(){
            cout<<"Pinging Server: "<<serverName<<endl;
        }
};

class WebServer: public Server{
    protected:
        int maxTraffic;
    public:
        WebServer(string name,int traffic): Server(name){
            maxTraffic=traffic;
            cout<<"[Constructing WebServer] Max Traffic set to "<<maxTraffic<<" requests/sec."<<endl;
        }
        ~WebServer(){
            cout<<"Destruct WebServer"<<endl;
        } 
        void serveHTML(){
            cout<<"Serving HTML content from "<<serverName<<endl;
        } 
};

class DatabaseServer: public Server{
    protected:
        string dbType;
    public:
        DatabaseServer(string name,string type): Server(name){
            dbType=type;
            cout<<"[Constructing DatabaseServer] Database Type set to "<<dbType<<endl;
        }     
        ~DatabaseServer(){
            cout<<"Destruct DatabaseServer"<<endl;
        }
        void queryData(){
            cout<<"Querying "<<dbType<<" database on "<<serverName<<endl;
        }
};

int main(){
    WebServer apache("Apache",1000);
    apache.ping();
    apache.serveHTML(); 
    DatabaseServer mysql("MySQL", "Relational");
    mysql.ping();
    mysql.queryData();
    return 0;
}
