/*
 * OOP concept: Interface default and static methods.
 *
 * Since Java 8, an interface may contain a default method with an implementation.
 * This allows a new method to be added to an interface while giving existing
 * implementers reusable behavior. Loggable supplies a default log() method,
 * although SecureService overrides it to add a security-specific prefix.
 *
 * An interface static method belongs to the interface itself and is called with
 * the interface name. It is not inherited as an instance method by implementing
 * classes. category() therefore provides a utility associated with Loggable.
 *
 * Default methods should represent behavior that is genuinely reasonable for
 * most implementers. When two interfaces provide conflicting defaults, the
 * implementing class must resolve the conflict explicitly. This feature lets
 * interfaces evolve while preserving clear contracts.
 *
 * Execution flow: SecureService uses its override, and main invokes the static
 * utility through Loggable.category().
 */
public class DefaultMethods {
    private interface Loggable {
        default void log(String message) { System.out.println("LOG: " + message); }
        static String category() { return "APPLICATION"; }
    }

    private static class SecureService implements Loggable {
        @Override public void log(String message) {
            System.out.println("SECURE LOG: " + message);
        }
    }

    public static void main(String[] args) {
        SecureService service = new SecureService();
        service.log("Login accepted");
        System.out.println("Category: " + Loggable.category());
    }
}