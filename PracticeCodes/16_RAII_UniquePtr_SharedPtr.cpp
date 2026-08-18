/*
    RAII (Resource Acquisition Is Initialization)
    -------------------------------------------

    Despite the confusing name, RAII is one of the most important ideas in modern C++.

    Real-world analogy:
    - Constructor = checking in and receiving a room key.
    - Destructor = checking out and returning the key.

    In older languages like C, if you forgot to free memory, the resource stayed occupied forever.
    This is called a memory leak. RAII solves this by tying the lifetime of a resource to the lifetime
    of a local object. When that object goes out of scope, its destructor runs automatically and releases
    the resource safely.

    Even if an exception occurs or a function exits early, the cleanup still happens.

    Smart pointers are the most common example of RAII in C++.

    1) std::unique_ptr
       - Exclusive ownership of a resource.
       - Only one unique_ptr can own the object.
       - When the unique_ptr goes out of scope, the object is deleted automatically.
       - Use this by default for single ownership.

    2) std::shared_ptr
       - Shared ownership of a resource.
       - Multiple shared_ptr objects can point to the same object.
       - It keeps a reference count, and the object is deleted when the last owner goes out of scope.
       - Use this when multiple owners need to share the same resource.

    Raw pointers (int* p = new int(5);) require manual delete, which is error-prone and easy to forget.
    Smart pointers remove this risk by handling cleanup automatically.
*/

#include <bits/stdc++.h>
using namespace std;

class Gadget{
    string name;
    double price;
public:
    Gadget(string name, double price):name(name), price(price){
        cout << "Gadget " << name << " created with price $" << price << endl;
    }
    ~Gadget(){
        cout << "Gadget " << name << " destroyed" << endl;
    }
    void use(){
        cout << "Using gadget " << name << endl;
    }
};

void demonstrateUniquePtr(){
    cout<< "Demonstrating Unique Pointer" << endl;
    unique_ptr<Gadget> myPhone=make_unique<Gadget>("iPhone", 999.99); 
    myPhone->use();
    cout<< "Transferring ownership of myPhone to myTablet" << endl;
    unique_ptr<Gadget> myTablet=move(myPhone); // Transfer ownership to myTablet
    if(!myPhone){
        cout << "myPhone is now nullptr after move" << endl;
    }   
    myTablet->use();    
    cout << "End of demonstrateUniquePtr function" << endl;
}

void demonstrateSharedPtr(){
    cout<< "Demonstrating Shared Pointer" << endl;
    shared_ptr<Gadget> myLaptop=make_shared<Gadget>("MacBook", 1299.99);
    myLaptop->use();
    cout << "Creating another shared pointer myLaptopCopy pointing to the same Gadget" << endl;
    shared_ptr<Gadget> myLaptopCopy=myLaptop; // Both pointers now share ownership
    cout << "Reference count of myLaptop: " << myLaptop.use_count() << endl;
    myLaptopCopy->use();
    cout << "End of demonstrateSharedPtr function" << endl;
}

int main(){
    demonstrateUniquePtr();
    demonstrateSharedPtr();
    cout << "End of main function" << endl;
    return 0;
}

/*
Output:
Using gadget iPhone
Transferring ownership of myPhone to myTablet
myPhone is now nullptr after move
Using gadget iPhone
End of demonstrateUniquePtr function
Gadget iPhone destroyed
Demonstrating Shared Pointer
Gadget MacBook created with price $1299.99
Using gadget MacBook
Creating another shared pointer myLaptopCopy pointingto the same Gadget
Reference count of myLaptop: 2
Using gadget MacBook
End of demonstrateSharedPtr function
Gadget MacBook destroyed
End of main function
*/