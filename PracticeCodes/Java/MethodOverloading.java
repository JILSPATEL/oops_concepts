/*
 * OOP concept: Compile-time polymorphism through method overloading.
 *
 * Overloading means declaring multiple methods with the same name in one class
 * but different parameter lists. NotificationService has three send() methods:
 * one accepts only a message, one accepts a recipient and message, and one
 * also accepts a priority. The return type alone cannot distinguish overloads;
 * the number, order, and types of parameters must differ.
 *
 * The compiler resolves an overload from the arguments at the call site. This
 * is why overloading is called compile-time or static polymorphism: the chosen
 * signature is known before execution. It provides a convenient, consistent
 * API while still allowing different input forms.
 *
 * Overloading is different from overriding. Overloading is usually within one
 * class and changes parameters; overriding occurs across an inheritance
 * relationship and keeps the same method signature for runtime dispatch.
 *
 * Execution flow: each call supplies a different argument list, so the
 * compiler binds it to the corresponding send() implementation.
 */
public class MethodOverloading {
    private static class NotificationService {
        void send(String message) {
            System.out.println("General notification: " + message);
        }

        void send(String recipient, String message) {
            System.out.println("To " + recipient + ": " + message);
        }

        void send(String recipient, String message, int priority) {
            System.out.println("Priority " + priority + " to " + recipient + ": " + message);
        }
    }

    public static void main(String[] args) {
        NotificationService service = new NotificationService();
        service.send("System maintenance tonight");
        service.send("Nora", "Your report is ready");
        service.send("Nora", "Server alert", 1);
    }
}