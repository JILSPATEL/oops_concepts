/*
 * OOP concept: Class-level state and behavior with static members.
 *
 * An ordinary field belongs to one object. A static field belongs to the class
 * itself and has one shared storage location for all instances. visitorCount
 * therefore represents a count for the whole Visitor class, not a count owned
 * by first or second. The constructor increments that shared field whenever a
 * new Visitor is created.
 *
 * A static method is also associated with the class. It can be called using the
 * class name and can directly access static fields, but it cannot directly use
 * instance fields because no particular object is selected. getVisitorCount()
 * is static for exactly this reason; greet() is non-static because it needs the
 * individual visitor's name.
 *
 * Static state is useful for constants, counters, factories, and utility
 * operations. It should be used carefully because shared mutable state creates
 * global coupling and can make concurrent programs harder to reason about.
 *
 * Execution flow: two objects increment the same counter, each object greets
 * using its own name, and the class-level method prints the shared count.
 */
public class StaticMembersAndMethods {
    private static class Visitor {
        private static int visitorCount;
        private final String name;

        Visitor(String name) {
            this.name = name;
            visitorCount++;
        }

        static int getVisitorCount() { return visitorCount; }
        void greet() { System.out.println("Welcome, " + name); }
    }

    public static void main(String[] args) {
        Visitor first = new Visitor("Mina");
        Visitor second = new Visitor("Ravi");
        first.greet();
        second.greet();
        System.out.println("Visitors created: " + Visitor.getVisitorCount());
    }
}