/*
 * OOP concept: Immutability and the final keyword.
 *
 * An immutable object has state that cannot change after construction. The
 * AccountSnapshot class enforces this by being final, keeping fields private
 * and final, validating input in the constructor, and exposing only getters.
 * There are no setters or mutating methods. Once constructed, every reference
 * to the snapshot observes the same account ID and balance.
 *
 * final has different uses in Java. A final class cannot be extended. A final
 * field can be assigned once, normally in its declaration or constructor. A
 * final reference cannot point to another object, although the referenced
 * object itself might still be mutable unless that object is also designed to
 * be immutable.
 *
 * Immutable value objects are easier to cache, share between threads, and use
 * as map keys because callers cannot change them unexpectedly. Defensive
 * copies are additionally required when an immutable class stores mutable
 * objects such as arrays or dates.
 *
 * Execution flow: the constructor validates and stores the snapshot, then the
 * main method reads its fixed values through getters.
 */
public class FinalAndImmutableObjects {
    private static final class AccountSnapshot {
        private final String accountId;
        private final double balance;

        AccountSnapshot(String accountId, double balance) {
            if (balance < 0) throw new IllegalArgumentException("Balance cannot be negative");
            this.accountId = accountId;
            this.balance = balance;
        }

        String getAccountId() { return accountId; }
        double getBalance() { return balance; }
    }

    public static void main(String[] args) {
        AccountSnapshot snapshot = new AccountSnapshot("AC-101", 825.50);
        System.out.println(snapshot.getAccountId() + ": " + snapshot.getBalance());
    }
}