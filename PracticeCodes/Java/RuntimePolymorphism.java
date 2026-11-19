/*
 * OOP concept: Runtime polymorphism and dynamic dispatch.
 *
 * Runtime polymorphism lets one common type represent many concrete types.
 * Shape declares the operation area(), while Circle and Rectangle provide their
 * own formulas. Shape is abstract because a generic shape has no single area
 * formula, but a Shape reference can still point to any concrete subclass.
 *
 * The array is declared as Shape[], not Circle[] or Rectangle[]. This allows a
 * single loop to process different shapes without checking their concrete
 * classes. For each element, Java examines the actual object created by new and
 * dispatches area() to that object's override. This decision happens while the
 * program runs, not when the variable is declared.
 *
 * Dynamic dispatch reduces conditional logic and follows the open/closed idea:
 * a new Shape subclass can be added with its own area() implementation without
 * rewriting the processing loop. The subclass must honor the Shape contract.
 *
 * Execution flow: main creates a circle and rectangle, stores both as Shape
 * references, and invokes area() polymorphically during iteration.
 */
public class RuntimePolymorphism {
    private abstract static class Shape {
        abstract double area();
    }

    private static class Circle extends Shape {
        private final double radius;
        Circle(double radius) { this.radius = radius; }
        @Override double area() { return Math.PI * radius * radius; }
    }

    private static class Rectangle extends Shape {
        private final double width;
        private final double height;
        Rectangle(double width, double height) {
            this.width = width;
            this.height = height;
        }
        @Override double area() { return width * height; }
    }

    public static void main(String[] args) {
        Shape[] shapes = {new Circle(2), new Rectangle(3, 4)};
        for (Shape shape : shapes) System.out.println("Area: " + shape.area());
    }
}