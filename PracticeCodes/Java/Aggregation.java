/*
 * OOP concept: Aggregation and weak ownership.
 *
 * Aggregation is a has-a relationship in which the contained object can exist
 * independently of the container. Department receives an Employee reference
 * from its caller instead of creating the employee itself. The employee can
 * therefore be used before the department is created, after it is discarded,
 * or by another object at the same time.
 *
 * In Java, aggregation is represented by ordinary object references; Java's
 * garbage collector determines memory reclamation based on reachability rather
 * than explicit delete calls. The design distinction is about ownership and
 * lifecycle responsibility, not about a special Java keyword.
 *
 * Aggregation is useful when objects collaborate but should not control one
 * another's lifetime. It also makes dependency injection possible: a caller
 * can provide a real employee, a test employee, or another compatible object.
 *
 * Execution flow: main creates an Employee first, injects it into Department,
 * and demonstrates that the employee remains independently meaningful.
 */
public class Aggregation {
    private static class Employee {
        private final String name;
        Employee(String name) { this.name = name; }
        String getName() { return name; }
    }

    private static class Department {
        private final Employee employee;
        Department(Employee employee) { this.employee = employee; }
        void showMember() { System.out.println("Department member: " + employee.getName()); }
    }

    public static void main(String[] args) {
        Employee employee = new Employee("Ishaan");
        Department department = new Department(employee);
        department.showMember();
        System.out.println("Employee can exist independently of the department");
    }
}