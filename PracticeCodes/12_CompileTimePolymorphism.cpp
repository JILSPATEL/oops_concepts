/*
 * Compile-Time Polymorphism - Function Overloading
 * 
 * This program demonstrates compile-time polymorphism (also known as static polymorphism)
 * through function overloading. The DataProcessor class defines multiple methods with the
 * same name 'analyze()' but different parameter types (int, double, string).
 * 
 * Key Concepts:
 * - Function Overloading: Multiple functions with the same name but different parameter types
 * - Compile-Time Resolution: The compiler determines which function to call based on arguments
 * - Type Safety: Each overloaded method handles a specific data type appropriately
 * 
 * Advantages:
 * - Provides a unified interface for similar operations on different types
 * - Improves code readability and maintainability
 * - Type-safe: Compiler checks argument compatibility at compile time
 */

#include <bits/stdc++.h>
using namespace std;

class DataProcessor{
    public:
    void analyze(int data){
        cout << "Analyzing integer data: " << data << endl;
    }
    void analyze(double data){
        cout << "Analyzing double data: " << data << endl;
    }   
    void analyze(string data){
        cout << "Analyzing string data: " << data << endl;
    }
};

int main() {
    DataProcessor processor;
    processor.analyze(42);          // Calls analyze(int)
    processor.analyze(3.14);        // Calls analyze(double)
    processor.analyze("Hello");     // Calls analyze(string)
    return 0;
}