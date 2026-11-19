/*
 * OOP concept: Generic classes and compile-time type safety.
 *
 * Generics let a class define an algorithm independently of the element type.
 * Box<T> has one type parameter T; when a caller writes Box<String>, T becomes
 * String, and when it writes Box<Integer>, T becomes Integer. The same class
 * implementation is reused for both types.
 *
 * The compiler checks put() and get() using the selected type. A String cannot
 * accidentally be inserted into Box<Integer>, and get() returns the correct
 * type without an explicit cast. This removes many ClassCastException risks
 * that older raw collection code could introduce at runtime.
 *
 * Java implements most generics through type erasure, so T is primarily a
 * compile-time feature and cannot normally be used directly as a constructor
 * type or primitive type. Use wrapper types such as Integer for generic values.
 *
 * Execution flow: main creates two parameterized Box objects, stores values of
 * their declared types, retrieves them safely, and uses the integer result.
 */
public class GenericsAndTypeSafety {
    private static class Box<T> {
        private T value;
        void put(T value) { this.value = value; }
        T get() { return value; }
    }

    public static void main(String[] args) {
        Box<String> message = new Box<>();
        message.put("Generic Java object");
        Box<Integer> number = new Box<>();
        number.put(42);
        System.out.println(message.get());
        System.out.println(number.get() + 1);
    }
}