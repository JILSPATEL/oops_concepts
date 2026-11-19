/*
 * OOP concept: Method overriding and subtype-specific behavior.
 *
 * Overriding occurs when a subclass supplies a method with the same name,
 * parameters, and compatible return type as an inherited method. CardPayment
 * and CashPayment both override Payment.fee(double), because each payment type
 * follows a different fee rule.
 *
 * The @Override annotation is important documentation and compiler protection.
 * If the signature is accidentally misspelled or changed, the compiler reports
 * an error instead of silently creating an unrelated method. The subclass
 * methods have package visibility here, matching the parent method.
 *
 * A Payment reference may refer to a CardPayment or CashPayment object. Calling
 * fee() through that reference uses the implementation belonging to the actual
 * object at runtime. That is the bridge from overriding to runtime
 * polymorphism. The parent implementation remains available to a subclass via
 * super.fee(amount), when a subclass wants to extend rather than replace it.
 *
 * Execution flow: two parent-typed references hold different child objects and
 * produce different fees from the same method call.
 */
public class MethodOverriding {
    private static class Payment {
        double fee(double amount) { return amount * 0.02; }
    }

    private static class CardPayment extends Payment {
        @Override double fee(double amount) { return amount * 0.025; }
    }

    private static class CashPayment extends Payment {
        @Override double fee(double amount) { return 0; }
    }

    public static void main(String[] args) {
        Payment card = new CardPayment();
        Payment cash = new CashPayment();
        System.out.println("Card fee: " + card.fee(100));
        System.out.println("Cash fee: " + cash.fee(100));
    }
}