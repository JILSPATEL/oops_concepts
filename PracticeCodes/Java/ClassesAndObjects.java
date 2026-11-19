/*
 * OOP concept: Classes and objects.
 *
 * A class is a user-defined type that combines state (data) and behavior
 * (methods). It acts as a blueprint; declaring a class does not create a book
 * object or allocate storage for a particular book's title and author.
 *
 * An object is an instance of a class. The new operator constructs an object
 * and returns a reference to it. Every Book object has its own copies of the
 * instance fields, so changing one book would not change the other book.
 * Both objects share the class definition and can call describe(), but the
 * method reads the state belonging to the object used for that call.
 *
 * The constructor establishes the initial state immediately. Private fields
 * prevent outside code from changing the representation directly. This small
 * example is the foundation for larger OOP designs: classes model entities,
 * objects hold individual data, and methods define supported operations.
 *
 * Execution flow: main creates two Book objects, stores their references, and
 * calls describe() on each. Dynamic dispatch is not needed here because both
 * references have the same concrete class, but each call uses different data.
 */
public class ClassesAndObjects {
    private static class Book {
        private String title;
        private String author;

        Book(String title, String author) {
            this.title = title;
            this.author = author;
        }

        void describe() {
            System.out.println(title + " by " + author);
        }
    }

    public static void main(String[] args) {
        Book firstBook = new Book("Clean Code", "Robert C. Martin");
        Book secondBook = new Book("Effective Java", "Joshua Bloch");
        firstBook.describe();
        secondBook.describe();
    }
}