/*
 * ============================================================================
 * VIRTUAL FUNCTIONS - Function Overriding and Late Binding
 * ============================================================================
 * 
 * OVERVIEW:
 * ─────────
 * This program demonstrates the difference between virtual and non-virtual 
 * function overriding in C++. It showcases how virtual functions enable 
 * runtime polymorphism while non-virtual functions use early binding.
 * 
 * KEY CONCEPTS:
 * ─────────────
 * 
 * 1. VIRTUAL FUNCTIONS (Late Binding - Runtime Polymorphism)
 *    - specialAttack() is declared as virtual in the base class
 *    - When called through a base class pointer, the ACTUAL object type
 *      determines which version is executed at RUNTIME
 *    - Example: character->specialAttack() calls Ninja's version
 * 
 * 2. NON-VIRTUAL FUNCTIONS (Early Binding - Compile-Time)
 *    - basicAttack() is NOT virtual in the base class
 *    - When called through a base class pointer, the POINTER TYPE
 *      determines which version is executed at COMPILE-TIME
 *    - Example: character->basicAttack() calls Character's version
 * 
 * 3. VIRTUAL DESTRUCTORS
 *    - When using inheritance with pointers, destructors should be virtual
 *    - Ensures the correct destructor chain is called when deleting derived objects
 *    - Prevents memory leaks and undefined behavior
 * 
 * 4. static_cast FOR TYPE CONVERSION
 *    - Used to explicitly convert base class pointer to derived class pointer
 *    - Allows calling derived class methods that aren't virtual
 *    - Example: static_cast<Ninja*>(character)->basicAttack() calls Ninja's version
 * 
 * VISUAL COMPARISON:
 * ──────────────────
 * Character *character = new Ninja();
 * 
 * character->basicAttack()  → Character::basicAttack() [Non-virtual: pointer type matters]
 * character->specialAttack() → Ninja::specialAttack() [Virtual: object type matters]
 * 
 * WHEN TO USE VIRTUAL:
 * ────────────────────
 * - Use virtual when you want derived classes to override behavior
 * - Use virtual when calling through base class pointers/references
 * - Always make destructors virtual in base classes used for inheritance
 * ============================================================================
 */

#include <bits/stdc++.h>
using namespace std;

class Character{
    public:
    void basicAttack() const{
        cout << "Character performs a basic attack!" << endl;
    }
    virtual void specialAttack() const{
        cout << "Character performs a special attack!" << endl;
    }
    virtual ~Character(){}
};

class Ninja:public Character{
    public:
    void basicAttack() const{
        cout << "Ninja performs a swift basic attack!" << endl;
    }
    void specialAttack() const override{
        cout << "Ninja performs a shadow strike!" << endl;
    }
};

int main(){
    Character *character=new Ninja();
    character->basicAttack(); // Calls Character's basicAttack()
    static_cast<Ninja*>(character)->basicAttack(); // Calls Ninja's basicAttack() explicitly
    character->specialAttack(); // Calls Ninja's specialAttack() due to virtual function
    delete character;
    return 0;
}