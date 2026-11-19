/*
 * ============================================================================
 * RUN-TIME POLYMORPHISM (Late Binding) - Using Virtual Functions
 * ============================================================================
 * 
 * DEEP DIVE: The Problem with Early Binding
 * ─────────────────────────────────────────
 * Imagine you have a base class called `Animal` and a derived class called `Dog`.
 * Both have a function called `speak()`.
 * 
 * If you create an `Animal` pointer but tell it to point to a `Dog` object,
 * what happens when you call `pointer->speak()`?
 * 
 * Because of EARLY BINDING (Compile-Time), the compiler only looks at the 
 * TYPE OF THE POINTER. It says, "This is an Animal pointer, so I will call 
 * the Animal's speak() function," completely ignoring the fact that it is 
 * actually pointing to a Dog!
 * 
 * THE SOLUTION: Late Binding and the `virtual` Keyword
 * ─────────────────────────────────────────────────────
 * To fix this, C++ introduces RUN-TIME POLYMORPHISM (Late Binding) using 
 * the `virtual` keyword.
 * 
 * If you put the word `virtual` in front of the base class function, you are
 * telling the compiler: "Do not make a decision right now. Wait until the 
 * program is actually running (run-time), look at the ACTUAL OBJECT the 
 * pointer is pointing to, and call THAT OBJECT'S version of the function."
 * 
 * HOW IT WORKS IN THIS EXAMPLE:
 * ─────────────────────────────
 * - Document class defines virtual print() method
 * - PDFDocument and WordDocument override the virtual function
 * - At compile-time: Compiler doesn't know which print() to call
 * - At run-time: Program checks the actual object type and calls the correct version
 * - Result: doc1->print() calls PDFDocument::print(), doc2->print() calls WordDocument::print()
 * 
 * KEY POINTS:
 * ──────────
 * - Virtual functions enable true polymorphism
 * - Decisions are made at runtime, not compile-time
 * - The `override` keyword (C++11) explicitly marks overridden virtual functions
 * - Provides flexibility and extensibility in object-oriented design
 * ============================================================================
 */

#include <bits/stdc++.h>
using namespace std;

class Document{
    public:
    virtual void print(){
        cout << "Printing document..." << endl;
    }
};

class PDFDocument : public Document{
    public:
    void print() override{
        cout << "Printing PDF document..." << endl;
    }
};

class WordDocument : public Document{
    public:
    void print() override{
        cout << "Printing Word document..." << endl;
    }
};

int main(){
    Document *doc1 = new PDFDocument();
    Document *doc2 = new WordDocument();    
    doc1->print(); // Calls PDFDocument's print()
    doc2->print(); // Calls WordDocument's print()
    return 0;
}

/*
Output:
Printing PDF document...
Printing Word document...

Output Without Virtual Function:
Printing document...    
Printing document...
*/