/*
 * OOP concept: Constructors, overloads, and constructor delegation.
 *
 * A constructor is a special method called automatically by new. It has the
 * same name as its class and no return type. Its responsibility is to create a
 * valid initial object. Product uses final fields, so both name and price must
 * be assigned during construction and cannot be reassigned afterward.
 *
 * Java allows multiple constructors with different parameter lists. This is
 * constructor overloading: callers can create a default product or provide a
 * name and price. The no-argument constructor calls this("Unnamed product", 0)
 * so initialization logic is kept in one place instead of duplicated.
 *
 * The parameterized constructor validates the price before storing it. Throwing
 * IllegalArgumentException rejects invalid input at the boundary, which means
 * a Product object cannot be created in an invalid state. Constructors are not
 * inherited, although a subclass can invoke a superclass constructor with
 * super(...).
 *
 * Execution flow: main invokes both overloads, each constructor initializes a
 * Product, and display() reads the completed immutable fields.
 */
public class ConstructorsAndInitialization {
    private static class Product {
        private final String name;
        private final double price;

        Product() {
            this("Unnamed product", 0.0);
        }

        Product(String name, double price) {
            if (price < 0) throw new IllegalArgumentException("Price cannot be negative");
            this.name = name;
            this.price = price;
        }

        void display() {
            System.out.println(name + " costs $" + price);
        }
    }

    public static void main(String[] args) {
        new Product().display();
        new Product("Keyboard", 49.99).display();
    }
}