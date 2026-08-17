/*
 * ============================================================================
 * PURE VIRTUAL FUNCTIONS AND ABSTRACT BASE CLASSES
 * ============================================================================
 * 
 * OVERVIEW:
 * ─────────
 * This program demonstrates abstract base classes and pure virtual functions,
 * which are fundamental concepts for enforcing a contract in object-oriented
 * design. They ensure that derived classes implement required methods.
 * 
 * KEY CONCEPTS:
 * ─────────────
 * 
 * 1. PURE VIRTUAL FUNCTION
 *    - A virtual function that has NO definition in the base class
 *    - Created by appending `= 0` to the function declaration
 *    - Serves as a STRICT CONTRACT: Any derived class MUST implement it
 *    - If a derived class doesn't implement it, the derived class also becomes abstract
 *    - Example in code: `virtual void display() = 0;` in Tutorial class
 * 
 * 2. ABSTRACT BASE CLASS
 *    - A class is "abstract" if it contains at least one pure virtual function
 *    - Exists purely as a blueprint for other classes
 *    - Cannot be instantiated directly
 *    - Tutorial is an abstract class because it has display() = 0
 * 
 * 3. THE GOLDEN RULE
 *    - You CANNOT instantiate an Abstract Base Class
 *    - The compiler will block any attempt to create an object of an abstract class
 *    - This is INTENTIONAL: abstract classes are meant to be inherited from
 *    - Example of what NOT to do: Tutorial obj; ❌ COMPILE ERROR!
 *    - What you CAN do: Tutorial* ptr = new videoTutorial(...); ✓ ALLOWED
 * 
 * 4. DERIVED CLASSES MUST OVERRIDE
 *    - videoTutorial and textTutorial both override display()
 *    - They provide concrete implementations of the pure virtual function
 *    - Now these derived classes are NOT abstract and CAN be instantiated
 * 
 * 5. BENEFITS OF ABSTRACT CLASSES
 *    - Enforce consistency across derived classes
 *    - Create a common interface that all subclasses must follow
 *    - Prevent accidental misuse of base classes
 *    - Enable polymorphic behavior through pointers/references
 * 
 * PRACTICAL EXAMPLE IN THIS CODE:
 * ───────────────────────────────
 * Tutorial (Abstract)
 *   ├─ videoTutorial (Concrete - implements display())
 *   └─ textTutorial (Concrete - implements display())
 * 
 * Main creates an array of Tutorial pointers (allowed, since we're using pointers)
 * and assigns videoTutorial and textTutorial objects to them. When display() is
 * called, polymorphism ensures the correct overridden method is executed.
 * 
 * WHEN TO USE ABSTRACT CLASSES:
 * ──────────────────────────────
 * - When you want to define a common interface for related classes
 * - When you want to enforce that derived classes implement specific methods
 * - When you want to prevent someone from creating objects of the base class
 * - When building plugin systems, frameworks, or extensible architectures
 * ============================================================================
 */

#include <bits/stdc++.h>
using namespace std;

class Tutorial {
protected:
    string title;

public:
    Tutorial(string title) : title(title) {}

    virtual void display() = 0; // Pure virtual function

    virtual ~Tutorial() {} // Virtual destructor
};

class videoTutorial : public Tutorial {
protected:
    int duration; // Duration in minutes

public:
    videoTutorial(string tittle, int duration)
        : Tutorial(tittle), duration(duration) {}

    void display() override {
        cout << "Video Tutorial: " << title
             << ", Duration: " << duration << " minutes" << endl;
    }

    ~videoTutorial() override {}
};

class textTutorial : public Tutorial {
protected:
    int wordCount;

public:
    textTutorial(string tittle, int wordCount)
        : Tutorial(tittle), wordCount(wordCount) {}

    void display() override {
        cout << "Text Tutorial: " << title
             << ", Word Count: " << wordCount << endl;
    }

    ~textTutorial() override {}
};

int main() {
    Tutorial* list[2];

    list[0] = new videoTutorial("C++ Basics", 30);
    list[1] = new textTutorial("C++ Basics", 1500);

    for (int i = 0; i < 2; i++) {
        list[i]->display();
    }

    // Free allocated memory
    for (int i = 0; i < 2; i++) {
        delete list[i];
    }

    return 0;
}
/*
Output:
Video Tutorial: C++ Basics, Duration: 30 minutes
Text Tutorial: C++ Basics, Word Count: 1500
*/
