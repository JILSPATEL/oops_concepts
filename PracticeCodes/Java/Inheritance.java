/*
 * OOP concept: Class inheritance and specialization.
 *
 * Inheritance models an is-a relationship. A Manager is an Employee, so the
 * Manager class extends Employee and receives its accessible members and
 * methods. Employee contains the common state and behavior that every employee
 * needs, while Manager adds the more specific teamSize and manageTeam().
 *
 * The protected name field is visible to Employee and subclasses, but not to
 * unrelated classes. The Manager constructor calls super(name), which invokes
 * the Employee constructor before Manager initializes its own field. This
 * ensures the parent portion of the object is ready first.
 *
 * Inheritance supports reuse and substitution, but it should represent a real
 * subtype relationship. It is not simply a way to copy code. Java supports
 * single class inheritance: a class directly extends one class, while it may
 * implement multiple interfaces for additional capabilities.
 *
 * Execution flow: main creates a Manager, calls inherited work(), then calls
 * Manager's own manageTeam() behavior.
 */
public class Inheritance {
    private static class Employee {
        protected final String name;
        Employee(String name) { this.name = name; }
        void work() { System.out.println(name + " is working"); }
    }

    private static class Manager extends Employee {
        private final int teamSize;
        Manager(String name, int teamSize) {
            super(name);
            this.teamSize = teamSize;
        }
        void manageTeam() { System.out.println(name + " manages " + teamSize + " people"); }
    }

    public static void main(String[] args) {
        Manager manager = new Manager("Leena", 5);
        manager.work();
        manager.manageTeam();
    }
}