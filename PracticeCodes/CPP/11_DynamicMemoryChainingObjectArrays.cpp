/*
Concept Explained: Dynamic Memory Allocation + Object Arrays + Method Chaining

This program demonstrates how to create an array of objects dynamically using new[] and then initialize each object through setter methods.

1. Dynamic memory allocation
   - The statement `ServerNode* cluster = new ServerNode[size];` creates an array of `size` objects in memory.
   - Unlike a normal stack array, this memory is allocated at runtime and remains available until we manually free it.
   - The array is deleted later using `delete[] cluster;` to avoid memory leaks.

2. Object array initialization
   - A default constructor is required because `new ServerNode[size]` calls the default constructor for every element.
   - This allows each node to start with safe default values such as `nodeId = 0`, `nodeName = "Unassigned"`, and `isActive = false`.

3. Setter methods and method chaining
   - Each setter changes a field and then returns the current object as a reference.
   - Example:
     cluster[i].setId(i + 1).setName("Node" + to_string(i + 1)).setActive(true);
   - This is called method chaining. The second call acts on the same object returned by the first setter.

4. Why use `&` in setters?
   - The return type `ServerNode&` means "return a reference to the current object".
   - Returning by reference avoids copying the whole object, which is more efficient.
   - It also lets us keep working with the same actual object instead of a temporary copy.
   - If we wrote `ServerNode setId(int id)` instead, the call would return a copy, and chaining would not work as expected.
   - Example:
     ServerNode x; x.setId(10).setName("A");
     This works only if setters return a reference to `x`.

5. Why reference parameter `string name` is also useful
   - Passing `string name` by value copies the string.
   - Passing `const string& name` would avoid unnecessary copying and make the function safer because it cannot modify the caller's string.
   - In this example, a simple value parameter is sufficient and easier to understand.

6. Real-world use case
   - This pattern is commonly used in game engines, networking code, UI systems, and server management tools where many objects must be created dynamically and configured in sequence.
*/

#include <bits/stdc++.h>
using namespace std;

class ServerNode {
private:
    int nodeId;
    string nodeName;
    bool isActive;

public:
    // Default constructor required for new ServerNode[size]
    ServerNode()
        : nodeId(0), nodeName("Unassigned"), isActive(false) {
    }

    // Parameterized constructor
    ServerNode(int id, string name, bool active)
        : nodeId(id), nodeName(name), isActive(active) {
    }

    ServerNode& setId(int id) {
        this->nodeId = id;//(*this).nodeId = id;
        return *this;
    }

    ServerNode& setName(string name) {
        this->nodeName = name;//(*this).nodeName = name;
        return *this;
    }

    ServerNode& setActive(bool active) {
        this->isActive = active;//(*this).isActive = active;
        return *this;
    }

    void displayNodeInfo() {
        cout << "Node ID: " << nodeId << endl;
        cout << "Node Name: " << nodeName << endl;
        cout << "Active Status: "
             << (isActive ? "Active" : "Inactive") << endl;
    }
};

int main() {
    int size = 3;

    // Calls the default constructor for each object
    ServerNode* cluster = new ServerNode[size];

    for (int i = 0; i < size; i++) {
        cluster[i]
            .setId(i + 1)
            .setName("Node" + to_string(i + 1))
            .setActive(true);
    }

    cout << "--- Cluster Node Information ---\n";

    for (int i = 0; i < size; i++) {
        cluster[i].displayNodeInfo();
        cout << "-------------------------------\n";
    }

    delete[] cluster;

    return 0;
}