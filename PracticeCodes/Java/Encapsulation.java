/*
 * OOP concept: Encapsulation and invariants.
 *
 * Encapsulation means that an object owns its state and controls how that state
 * can be observed or changed. BankAccount marks owner and balance private, so
 * code outside the class cannot assign an arbitrary balance such as -500.
 * Instead, callers use deposit(), withdraw(), and getter methods provided by
 * the class. These methods are the public contract of the object.
 *
 * The constructor validates the opening balance once, and deposit() validates
 * every later deposit. withdraw() checks both the amount and available funds.
 * These rules are called invariants: conditions that must remain true whenever
 * a public operation finishes. Keeping validation next to the data prevents
 * different callers from implementing inconsistent banking rules.
 *
 * Encapsulation is not merely making fields private. It also means exposing a
 * small, meaningful API and hiding implementation details so the internal
 * representation can change later without changing callers.
 *
 * Execution flow: the account is constructed with a valid balance, receives a
 * deposit, reports its balance, and attempts a withdrawal through its methods.
 */
public class Encapsulation {
    private static class BankAccount {
        private final String owner;
        private double balance;

        BankAccount(String owner, double openingBalance) {
            if (openingBalance < 0) {
                throw new IllegalArgumentException("Opening balance cannot be negative");
            }
            this.owner = owner;
            this.balance = openingBalance;
        }

        void deposit(double amount) {
            if (amount <= 0) throw new IllegalArgumentException("Deposit must be positive");
            balance += amount;
        }

        boolean withdraw(double amount) {
            if (amount <= 0 || amount > balance) return false;
            balance -= amount;
            return true;
        }

        double getBalance() { return balance; }
        String getOwner() { return owner; }
    }

    public static void main(String[] args) {
        BankAccount account = new BankAccount("Asha", 1000);
        account.deposit(250);
        System.out.println(account.getOwner() + " has balance " + account.getBalance());
        System.out.println("Withdrawal successful: " + account.withdraw(400));
    }
}