/*
 * OOP concept: Type-safe enumerations with state and behavior.
 *
 * An enum represents a fixed set of named values. Unlike integer constants,
 * each Java enum value is an object of the enum type, so code cannot pass an
 * arbitrary number where Status is required. The compiler and the type system
 * prevent many invalid-state mistakes.
 *
 * Java enums can have fields, constructors, and methods. Every Status constant
 * stores its own description, and printDescription() uses that state. Enum
 * constructors are private implicitly because callers may use only the declared
 * constants. values() returns all constants in declaration order, while name()
 * returns the constant identifier.
 *
 * Enums are appropriate for finite domains such as states, directions, roles,
 * and modes. They can also implement interfaces and contain behavior, making
 * each constant a richer domain value rather than a plain label.
 *
 * Execution flow: main selects RUNNING, prints it, and then iterates through all
 * possible statuses using the generated values() method.
 */
public class EnumsAndBehavior {
    private enum Status {
        NEW("Waiting to start"),
        RUNNING("Work is in progress"),
        DONE("Work is complete");

        private final String description;
        Status(String description) { this.description = description; }
        void printDescription() { System.out.println(name() + ": " + description); }
    }

    public static void main(String[] args) {
        Status current = Status.RUNNING;
        current.printDescription();
        for (Status status : Status.values()) status.printDescription();
    }
}