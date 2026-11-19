/*
 * OOP concept: Composition and strong ownership.
 *
 * Composition models a has-a relationship: a Car has an Engine. Car creates and
 * stores its Engine as an implementation detail, then delegates start() to it.
 * The outer object's behavior is assembled from a smaller collaborating object
 * instead of being built through inheritance.
 *
 * Composition promotes encapsulation because callers do not need to know how a
 * Car starts its engine. It also follows the principle of favoring composition
 * over inheritance when the relationship is not an is-a relationship. The Car
 * can later replace the engine implementation without changing the public
 * start() operation.
 *
 * In this example the engine reference is final, so a Car always has the same
 * engine component. The component is created as part of Car construction and is
 * normally treated as owned by that Car; this is stronger ownership than
 * aggregation, where the component is supplied from outside.
 *
 * Execution flow: main creates a Car, Car delegates to its Engine, and then
 * reports that the complete car is ready.
 */
public class Composition {
    private static class Engine {
        void start() { System.out.println("Engine started"); }
    }

    private static class Car {
        private final Engine engine = new Engine();
        void start() {
            engine.start();
            System.out.println("Car is ready to drive");
        }
    }

    public static void main(String[] args) {
        new Car().start();
    }
}