/*
 * OOP concept: Abstract classes and template-like shared behavior.
 *
 * An abstract class is an incomplete base type. It may hold fields,
 * constructors, and fully implemented methods, but it cannot be instantiated.
 * Report owns the common title and printHeader() behavior. It also declares
 * abstract printBody(), which expresses a requirement every concrete report
 * must satisfy.
 *
 * SalesReport extends Report and implements printBody() using sales data. The
 * Report.print() method defines a fixed sequence: print the shared header, then
 * call the subclass-specific body. This is a simple template-method design and
 * keeps common workflow in one place.
 *
 * Abstract classes are useful when related classes share implementation as well
 * as a contract. Interfaces are often better when only a capability contract is
 * needed. Java prevents direct construction of Report, ensuring callers use a
 * complete concrete report.
 *
 * Execution flow: main stores a SalesReport in a Report reference and calls the
 * inherited print() workflow, which dynamically invokes printBody().
 */
public class AbstractClasses {
    private abstract static class Report {
        private final String title;
        Report(String title) { this.title = title; }

        void printHeader() { System.out.println("=== " + title + " ==="); }
        abstract void printBody();
        void print() { printHeader(); printBody(); }
    }

    private static class SalesReport extends Report {
        private final double total;
        SalesReport(String title, double total) {
            super(title);
            this.total = total;
        }
        @Override void printBody() { System.out.println("Sales total: $" + total); }
    }

    public static void main(String[] args) {
        Report report = new SalesReport("Monthly Sales", 12500);
        report.print();
    }
}