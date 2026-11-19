const topics = [
  {
    id: "classes-objects", group: "foundations", chapter: "Foundations", icon: "◈",
    title: "Classes & objects", summary: "The basic unit of object-oriented design",
    explanation: [
      "A class is a type definition that groups state (fields) and behavior (methods). It describes what an object knows and what it can do, but the class declaration itself is not a particular customer, car, or account.",
      "An object is a runtime instance of a class. Each object has its own instance state, while all objects use the same method definitions. In both languages, clients interact with objects through expressions such as account.deposit(100), which keeps behavior close to the data it operates on."
    ],
    points: ["Class = blueprint; object = instance.", "Instance fields belong to each object; static fields belong to the type.", "Objects collaborate by calling public methods.", "Good classes have one clear responsibility."],
    cpp: String.raw`class User {
public:
    string name;
    void greet() { cout << "Hello " << name; }
};

int main() {
    User user;
    user.name = "Mina";
    user.greet();
}`,
    java: String.raw`class User {
    String name;
    void greet() { System.out.println("Hello " + name); }
}

class Main {
    public static void main(String[] args) {
        User user = new User();
        user.name = "Mina";
        user.greet();
    }
}`,
    comparison: "Both languages define classes and create objects with new, but C++ may also create automatic (stack) objects. Java variables hold references to objects managed by the JVM."
  },
  {
    id: "constructors", group: "foundations", chapter: "Foundations", icon: "✦",
    title: "Constructors & initialization", summary: "Create objects in a valid starting state",
    explanation: [
      "A constructor runs when an object is created and establishes the object's initial invariants. It has no return type, can be overloaded, and should reject invalid input early rather than creating a partially valid object.",
      "C++ initializes members through initializer lists and has copy/move constructors. Java supports overloaded constructors and constructor delegation with this(), but does not have a language-provided copy constructor; a copy constructor is simply a programmer-defined convention."
    ],
    points: ["Constructors run automatically during object creation.", "C++ base/member initialization happens before the constructor body.", "Java requires an explicit super(...) or implicitly calls super().", "If you declare a constructor, a default constructor is not automatically added."],
    cpp: String.raw`class Account {
    double balance;
public:
    Account(double opening) : balance(opening) {
        if (opening < 0) throw invalid_argument("negative");
    }
};`,
    java: String.raw`class Account {
    private final double balance;

    Account(double opening) {
        if (opening < 0) throw new IllegalArgumentException("negative");
        balance = opening;
    }
}`,
    comparison: "C++ has deterministic construction and destruction as language features. Java constructors initialize objects, but cleanup is handled separately by garbage collection or explicit resource APIs."
  },
  {
    id: "object-lifecycle", group: "foundations", chapter: "Foundations", icon: "◌",
    title: "Object lifecycle & cleanup", summary: "Understand creation, reachability, and resource release",
    explanation: [
      "An object lifecycle includes allocation, construction, use, and cleanup. In C++, an automatic object's destructor runs when its scope ends, while a dynamically allocated object must be released with delete or an owning RAII wrapper.",
      "Java objects become eligible for garbage collection when no reachable reference points to them. Garbage collection reclaims memory at an unspecified time; it is not a replacement for closing files, sockets, or database connections. Use try-with-resources and AutoCloseable for deterministic external-resource cleanup."
    ],
    points: ["Memory lifetime and resource lifetime are different problems.", "Never rely on Java finalization for cleanup.", "C++ destructors should release owned resources.", "Prefer RAII and Java try-with-resources over manual cleanup paths."],
    cpp: String.raw`{
    unique_ptr<File> file = make_unique<File>("data.txt");
    file->write("hello");
} // unique_ptr destroys File here`,
    java: String.raw`try (BufferedReader reader =
         Files.newBufferedReader(Path.of("data.txt"))) {
    System.out.println(reader.readLine());
} // close() runs automatically`,
    comparison: "C++ commonly ties resource lifetime to scope. Java uses garbage collection for memory, but deterministic resources still need close(), usually through try-with-resources."
  },
  {
    id: "access-modifiers", group: "foundations", chapter: "Foundations", icon: "▣",
    title: "Access modifiers", summary: "Control who can see and use a member",
    explanation: [
      "Access control is the first boundary of a class. C++ class members default to private, while struct members default to public. Java members default to package-private when no modifier is written.",
      "Use public for a deliberate external API, private for implementation details, and protected only when subclasses genuinely need direct access. Java additionally has package-private access and packages provide a useful module boundary. C++ uses public, protected, and private sections rather than one modifier per declaration."
    ],
    points: ["private: only the declaring class (and C++ friends).", "protected: the class and permitted subclasses.", "public: available through the public API.", "Prefer private state plus behavior over exposed mutable fields."],
    cpp: String.raw`class Account {
private:
    double balance;
protected:
    string owner;
public:
    double getBalance() const { return balance; }
};`,
    java: String.raw`class Account {
    private double balance;
    protected String owner;
    public double getBalance() { return balance; }
    // no modifier = package-private
}`,
    comparison: "Java has package-private access; C++ has no direct package equivalent. C++ also supports friend declarations that can bypass private access in a controlled way."
  },
  {
    id: "encapsulation", group: "pillars", chapter: "Four pillars", icon: "⛉",
    title: "Encapsulation", summary: "Protect state and enforce valid operations",
    explanation: [
      "Encapsulation combines data with the operations that are allowed to change it, then hides representation details. A BankAccount should not expose balance for arbitrary assignment because that would allow negative or unauthorized values.",
      "A well-encapsulated class protects invariants through methods such as deposit and withdraw. Encapsulation is more than adding getters and setters: a setter that accepts every value is only public mutation with extra syntax. Expose meaningful operations and validate at the boundary."
    ],
    points: ["Hide representation; expose intent.", "Keep validation next to the state it protects.", "Return read-only views or copies when appropriate.", "Encapsulation makes later internal refactoring safer."],
    cpp: String.raw`class BankAccount {
    double balance = 0;
public:
    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }
    double getBalance() const { return balance; }
};`,
    java: String.raw`class BankAccount {
    private double balance;
    public void deposit(double amount) {
        if (amount > 0) balance += amount;
    }
    public double getBalance() { return balance; }
}`,
    comparison: "The design principle is the same. Java's references and garbage collection remove pointer ownership concerns, while C++ also needs to consider copying and lifetime when exposing data."
  },
  {
    id: "abstraction", group: "pillars", chapter: "Four pillars", icon: "◎",
    title: "Abstraction", summary: "Expose what matters and hide how it works",
    explanation: [
      "Abstraction presents a simpler model to a caller while hiding implementation complexity. A payment service can expose pay(amount) without asking the caller to understand network retries, encryption, or provider-specific protocols.",
      "Abstract classes and interfaces are common mechanisms. The abstraction is the stable contract; concrete implementations can change behind it. Good abstraction is selective: hiding irrelevant detail reduces cognitive load, but hiding important behavior makes systems difficult to debug."
    ],
    points: ["Model essential behavior, not every implementation detail.", "A contract defines what clients may rely on.", "Concrete implementations can vary behind the contract.", "Abstraction and encapsulation work together but are not synonyms."],
    cpp: String.raw`class Payment {
public:
    virtual void pay(double amount) = 0;
    virtual ~Payment() = default;
};`,
    java: String.raw`interface Payment {
    void pay(double amount);
}

abstract class Receipt {
    abstract String format();
    void print() { System.out.println(format()); }
}`,
    comparison: "C++ uses pure virtual functions and abstract base classes. Java uses abstract classes and interfaces, with interfaces also supporting default and static methods."
  },
  {
    id: "inheritance", group: "pillars", chapter: "Four pillars", icon: "⌘",
    title: "Inheritance", summary: "Reuse and specialize an is-a relationship",
    explanation: [
      "Inheritance creates a subtype relationship: a SavingsAccount is an Account, and a Circle is a Shape. The child receives accessible behavior from its parent and can add or override behavior.",
      "Use inheritance when substituting a child anywhere the parent is expected makes semantic sense. Avoid inheriting only to reuse a few lines of code; composition often gives a smaller and more flexible design. In both languages, the base part is initialized before the derived part."
    ],
    points: ["Base class contains common contract or implementation.", "Derived class specializes without breaking the base contract.", "Prefer protected behavior or protected helper methods over exposed state.", "Inheritance increases coupling between parent and child."],
    cpp: String.raw`class SavingsAccount : public Account {
public:
    void addInterest() { deposit(getBalance() * .05); }
};`,
    java: String.raw`class SavingsAccount extends Account {
    void addInterest() {
        deposit(getBalance() * 0.05);
    }
}`,
    comparison: "C++ inheritance has public/protected/private inheritance modes and supports multiple class bases. Java extends exactly one class and uses interfaces for multiple capabilities."
  },
  {
    id: "inheritance-forms", group: "pillars", chapter: "Four pillars", icon: "⤢",
    title: "Forms of inheritance", summary: "Single, multilevel, hierarchical, and multiple capability models",
    explanation: [
      "Single inheritance has one parent and one child. Multilevel inheritance forms a chain such as Employee → Manager → Director. Hierarchical inheritance gives multiple children a shared base. These patterns can model shared domain behavior, but deep trees become difficult to change.",
      "C++ also supports multiple inheritance of classes, which can create the diamond problem when two parents share a base. Virtual inheritance can share the common base. Java avoids multiple class inheritance and uses interfaces to combine capabilities, requiring explicit default-method conflict resolution."
    ],
    points: ["Keep hierarchies shallow and meaningful.", "Use interfaces for orthogonal capabilities.", "Diamond inheritance duplicates or ambiguously exposes shared base state.", "Composition is often clearer than a deep inheritance tree."],
    cpp: String.raw`class Printer : virtual public Device {};
class Scanner : virtual public Device {};
class Copier : public Printer, public Scanner {
    // One shared Device subobject
};`,
    java: String.raw`interface Printer { default void process() { } }
interface Scanner { default void process() { } }

class Copier implements Printer, Scanner {
    public void process() {
        Printer.super.process(); // resolve conflict
    }
}`,
    comparison: "C++ can inherit implementation from multiple classes, while Java's interface model avoids multiple class state and makes conflicting default behavior explicit."
  },
  {
    id: "polymorphism-overloading", group: "pillars", chapter: "Four pillars", icon: "≋",
    title: "Polymorphism: overloading", summary: "One operation name, different parameter shapes",
    explanation: [
      "Method or function overloading defines several operations with the same name but different parameter lists. It is compile-time polymorphism because the compiler selects a signature from the argument types, count, and order.",
      "Overloads should represent the same conceptual operation. They are useful for optional information and convenient APIs, but too many overloads can make calls ambiguous, especially when implicit numeric conversions are involved."
    ],
    points: ["Return type alone cannot distinguish overloads.", "The compiler resolves overloads before execution.", "Overloading does not require inheritance.", "Varargs and implicit conversions can affect overload selection."],
    cpp: String.raw`class Printer {
public:
    void print(int value) { cout << value; }
    void print(double value) { cout << value; }
    void print(string value) { cout << value; }
};`,
    java: String.raw`class Printer {
    void print(int value) { System.out.println(value); }
    void print(double value) { System.out.println(value); }
    void print(String value) { System.out.println(value); }
}`,
    comparison: "Both languages support overload resolution at compile time. Java has no user-defined operator overloading, while C++ also overloads operators."
  },
  {
    id: "polymorphism-overriding", group: "pillars", chapter: "Four pillars", icon: "↗",
    title: "Polymorphism: overriding", summary: "One contract, different runtime behavior",
    explanation: [
      "Overriding happens when a derived class provides a replacement for an inherited method with the same signature. A parent reference can point to a child object, and the child implementation is selected through dynamic dispatch.",
      "This enables code to depend on an abstraction such as Shape or Payment instead of concrete classes. The child must preserve the parent contract: callers should not be surprised when a subtype is substituted. This is the behavioral part of the Liskov substitution principle."
    ],
    points: ["Same method signature across parent and child.", "Use override annotations/specifiers to catch mistakes.", "Runtime dispatch selects behavior from the actual object.", "Static, private, and final methods cannot be overridden."],
    cpp: String.raw`class Shape {
public:
    virtual double area() const = 0;
};
class Circle : public Shape {
public:
    double area() const override { return 3.14 * 4 * 4; }
};`,
    java: String.raw`abstract class Shape {
    abstract double area();
}
class Circle extends Shape {
    @Override double area() { return Math.PI * 4 * 4; }
}`,
    comparison: "C++ requires virtual for dynamic dispatch through a base pointer/reference. Java instance methods are virtual by default unless they are static, private, or final."
  },
  {
    id: "virtual-functions", group: "pillars", chapter: "Four pillars", icon: "◉",
    title: "Virtual functions & dispatch", summary: "How languages choose an overridden method",
    explanation: [
      "A virtual call is resolved using the runtime object's type instead of only the static type of the variable. In C++, the virtual keyword opts a method into this mechanism and implementations commonly use a vtable behind the scenes.",
      "A C++ base class used polymorphically should normally have a virtual destructor. Otherwise, deleting a derived object through a base pointer can fail to run the derived destructor. Java does not expose a virtual keyword because ordinary instance dispatch is already dynamic."
    ],
    points: ["Static type controls what members are visible at compile time.", "Dynamic type controls an overridden virtual/instance method at runtime.", "C++ virtual calls have a small dispatch cost and design trade-off.", "Java method calls are dynamically dispatched; fields are not polymorphic."],
    cpp: String.raw`struct Animal {
    virtual void speak() { cout << "sound"; }
    virtual ~Animal() = default;
};
Animal* a = new Dog();
a->speak(); // Dog::speak()
delete a;`,
    java: String.raw`Animal animal = new Dog();
animal.speak(); // Dog.speak()

// Fields use the reference type, methods use
// the runtime object type.`,
    comparison: "The user-facing rule is similar, but C++ makes virtual participation explicit and exposes raw pointer deletion. Java manages object lifetime and defaults instance methods to dynamic dispatch."
  },
  {
    id: "abstract-classes", group: "pillars", chapter: "Four pillars", icon: "△",
    title: "Abstract classes", summary: "A partial implementation plus a required contract",
    explanation: [
      "An abstract class cannot be instantiated because it represents an incomplete concept. It may contain fields, constructors, concrete methods, and abstract methods. A concrete subclass must implement every abstract method before it can be instantiated.",
      "Abstract classes are useful when related types share real implementation and state as well as a required API. They are different from interfaces: an abstract class is a single inheritance slot with shared implementation, while a type can implement several interfaces."
    ],
    points: ["Abstract classes can have constructors.", "Abstract methods have no implementation in the abstract base.", "A subclass may remain abstract if it does not implement every requirement.", "Use an abstract class when shared state or workflow is meaningful."],
    cpp: String.raw`class Report {
public:
    virtual void printBody() = 0;
    void print() { printBody(); }
    virtual ~Report() = default;
};
class SalesReport : public Report {
    void printBody() override { cout << "sales"; }
};`,
    java: String.raw`abstract class Report {
    abstract void printBody();
    void print() { printBody(); }
}
class SalesReport extends Report {
    @Override void printBody() { System.out.println("sales"); }
}`,
    comparison: "C++ creates abstraction with pure virtual methods (= 0). Java uses the abstract keyword and can combine an abstract class with multiple interfaces."
  },
  {
    id: "interfaces", group: "design", chapter: "Design & language", icon: "⊕",
    title: "Interfaces", summary: "Contracts for capabilities and loose coupling",
    explanation: [
      "An interface describes a capability without forcing an implementation to share a class hierarchy. A class can implement several interfaces, so a SmartPhone can be both Camera and GPS without inheriting state from two parent classes.",
      "Interfaces are valuable at boundaries: a service can depend on PaymentGateway rather than StripeGateway. That makes replacement, testing, and independent evolution easier. Modern Java interfaces may also contain default and static methods, while abstract methods remain a contract."
    ],
    points: ["Program to an interface, not a concrete implementation.", "A class can implement multiple Java interfaces.", "Interfaces are excellent dependency-injection boundaries.", "C++ often models interfaces with abstract classes and pure virtual methods."],
    cpp: String.raw`class Drawable {
public:
    virtual void draw() const = 0;
    virtual ~Drawable() = default;
};`,
    java: String.raw`interface Drawable {
    void draw();
}
class Circle implements Drawable {
    public void draw() { System.out.println("circle"); }
}`,
    comparison: "Java has a dedicated interface keyword and multiple interface inheritance. C++ commonly uses an abstract class with only pure virtual methods."
  },
  {
    id: "static-this-const-final", group: "foundations", chapter: "Foundations", icon: "⌬",
    title: "this, static, const & final", summary: "Object identity, shared state, and restrictions",
    explanation: [
      "this refers to the current object. It disambiguates a field from a parameter with the same name and can return the current object for fluent method chaining. A static member belongs to the class, so it can be accessed without an instance and cannot directly use instance state.",
      "C++ const communicates that a method or object should not mutate state. Java final prevents reassignment of a variable, overriding of a method, or extension of a class. These keywords are related to safety but are not interchangeable: a final reference may still refer to a mutable object."
    ],
    points: ["this is an object reference; it is not available in static context.", "C++ const methods promise not to mutate the object.", "Java final fields should be initialized once.", "Static mutable state is shared global state; use it deliberately."],
    cpp: String.raw`class Counter {
    int value;
public:
    Counter& increment() {
        ++value;
        return *this;
    }
    int get() const { return value; }
};`,
    java: String.raw`final class Counter {
    private int value;
    Counter increment() {
        value++;
        return this;
    }
    int get() { return value; }
}`,
    comparison: "C++ separates const object/method guarantees from static. Java uses final for assignment and inheritance restrictions, and has no const method qualifier."
  },
  {
    id: "composition", group: "design", chapter: "Design & language", icon: "◫",
    title: "Composition", summary: "Build behavior from owned components",
    explanation: [
      "Composition is a strong has-a relationship. A Car contains an Engine and delegates engine-specific work to it. The car's behavior is assembled from collaborators rather than inherited from a parent.",
      "Composition reduces hierarchy coupling and makes components replaceable. The exact ownership can vary: a component may be created inside its owner, injected through a constructor, or shared. The important design question is who owns the relationship and who controls its lifecycle."
    ],
    points: ["Use composition when the relationship is has-a, not is-a.", "Delegate focused work to focused components.", "Constructor injection makes dependencies explicit and testable.", "Composition often changes at runtime more easily than inheritance."],
    cpp: String.raw`class Car {
    Engine engine;
public:
    void start() { engine.start(); }
};`,
    java: String.raw`class Car {
    private final Engine engine;
    Car(Engine engine) { this.engine = engine; }
    void start() { engine.start(); }
}`,
    comparison: "Both languages support composition through member fields/references. C++ must decide value versus pointer ownership; Java references are garbage-collected but ownership remains a design responsibility."
  },
  {
    id: "aggregation-association", group: "design", chapter: "Design & language", icon: "⛓",
    title: "Association, aggregation & ownership", summary: "Describe how objects relate and who controls lifetime",
    explanation: [
      "Association is a general relationship: two independent objects know about or use one another. Aggregation is a weaker whole-part relationship where the part can live independently, such as a Department referring to an Employee.",
      "Composition is stronger ownership: a component is conceptually part of the owner's lifecycle. UML uses these distinctions to communicate domain structure. Java has no aggregation keyword and C++ has no automatic semantic marker; fields, references, smart pointers, and constructors express the intended ownership."
    ],
    points: ["Association: uses or knows about.", "Aggregation: contains, but does not own the lifetime.", "Composition: contains and owns the part.", "Document ownership explicitly through APIs and types."],
    cpp: String.raw`class Department {
    Employee& employee; // supplied from outside
public:
    Department(Employee& e) : employee(e) {}
};`,
    java: String.raw`class Department {
    private final Employee employee; // independent object
    Department(Employee employee) {
        this.employee = employee;
    }
}`,
    comparison: "The concepts are design vocabulary in both languages. C++ smart pointers can communicate ownership more strongly; Java relies on API design and documentation because all references are managed by the JVM."
  },
  {
    id: "friend-functions", group: "design", chapter: "Design & language", icon: "♢",
    languages: ["cpp"],
    title: "Friend functions & friend classes", summary: "Controlled private access in C++",
    explanation: [
      "A C++ friend function is not a member, but a class grants it access to private and protected members. A friend class receives the same special access. This is useful for symmetric operations, stream operators, serializers, and tightly coupled helper objects.",
      "Friendship is granted by the class being accessed, is not automatically inherited, and is not reciprocal. It intentionally weakens encapsulation, so use it when a non-member API is the clearest design. Java has no friend keyword; use public methods, package boundaries, nested classes, or explicit interfaces instead."
    ],
    points: ["Friend is a permission, not inheritance.", "Friendship is explicit and one-way.", "A friend function can access private data without being called with dot syntax.", "Prefer a narrow friend over making sensitive fields public."],
    cpp: String.raw`class Box {
    double width;
    friend double getWidth(const Box&);
public:
    explicit Box(double w) : width(w) {}
};
double getWidth(const Box& box) { return box.width; }`,
    java: String.raw`// Java has no friend keyword.
// Prefer a deliberate API:
final class Box {
    private final double width;
    double widthForMeasurement() { return width; }
}`,
    comparison: "Friend access is a C++ feature. Java preserves stronger class boundaries and solves collaboration through methods, nested access, package-private APIs, or interfaces."
  },
  {
    id: "operator-overloading", group: "design", chapter: "Design & language", icon: "⊗",
    languages: ["cpp"],
    title: "Operator overloading", summary: "Give domain types natural C++ operators",
    explanation: [
      "C++ lets a class define what operators such as +, ==, or << mean for its objects. A Money or Vector type can then read naturally, but an overload should preserve the operator's expected meaning and should not surprise users with hidden expensive work.",
      "Java deliberately does not support user-defined operator overloading. The language reserves operators for built-in types and uses named methods such as add(), equals(), compareTo(), and toString(). Java's + does concatenate strings, but that is built-in language behavior, not a user-defined overload."
    ],
    points: ["Overload only when the operation is intuitive and value-like.", "Keep operators consistent with equality and ordering rules.", "C++ stream insertion is commonly implemented as a friend.", "Java uses named methods and standard contracts instead."],
    cpp: String.raw`struct Point {
    int x, y;
    Point operator+(const Point& other) const {
        return {x + other.x, y + other.y};
    }
};`,
    java: String.raw`final class Point {
    final int x, y;
    Point add(Point other) {
        return new Point(x + other.x, y + other.y);
    }
    // Java uses add(), not a custom + operator.
}`,
    comparison: "Operator overloading is a major C++ feature with no Java equivalent. Java relies on clearly named methods and contracts such as equals/hashCode."
  },
  {
    id: "copy-move-semantics", group: "design", chapter: "Design & language", icon: "⇄",
    languages: ["cpp"],
    title: "Copy, move & value semantics", summary: "How C++ objects are transferred and duplicated",
    explanation: [
      "C++ objects can have value semantics: copying creates an independent value. A copy constructor and copy assignment operator define copying, while move operations transfer resources from a temporary or expiring object without an expensive deep copy.",
      "The rule of zero says prefer members such as std::string and smart pointers that manage themselves, so the compiler-generated special members are correct. If a class manually owns a resource, study the rule of three/five and define or delete copy/move operations deliberately."
    ],
    points: ["Copying a raw pointer copies an address, not the pointed resource.", "A deep copy owns an independent resource.", "Moving transfers ownership and leaves the source valid but unspecified.", "Java variables hold references; assignment copies a reference, not the object."],
    cpp: String.raw`class Buffer {
    vector<int> data;
public:
    Buffer(const Buffer&) = default;       // copy
    Buffer(Buffer&&) noexcept = default;   // move
};`,
    java: String.raw`Buffer first = new Buffer();
Buffer second = first; // both references point to one object

// Java needs an explicit copy constructor or
// factory when an independent copy is required.`,
    comparison: "C++ exposes value/copy/move semantics and deterministic ownership. Java assignment copies references; object copying must be implemented explicitly."
  },
  {
    id: "templates-generics", group: "design", chapter: "Design & language", icon: "◇",
    title: "Templates & generics", summary: "Reusable types without giving up type safety",
    explanation: [
      "C++ templates generate code for types at compile time. A function or class can work with any type that supports the operations used by the template; modern concepts can state those requirements explicitly.",
      "Java generics parameterize classes and methods with reference types, giving compile-time checking and eliminating most casts. Java implements generics mainly through type erasure, while C++ usually creates specialized compiled code for each type. Both mechanisms improve reuse, but their constraints and runtime behavior differ."
    ],
    points: ["Generic code expresses an algorithm once.", "C++ templates support specialization and compile-time computation.", "Java generics cannot use primitive type arguments directly; use Integer, Double, etc.", "A generic API should state the operations it requires."],
    cpp: String.raw`template <typename T>
T maxValue(T first, T second) {
    return first > second ? first : second;
}`,
    java: String.raw`static <T extends Comparable<T>>
T maxValue(T first, T second) {
    return first.compareTo(second) > 0 ? first : second;
}`,
    comparison: "C++ templates are compile-time code generation with powerful specialization. Java generics provide type checking through erasure and use bounds for required capabilities."
  },
  {
    id: "raii-smart-pointers", group: "design", chapter: "Design & language", icon: "⟲",
    languages: ["cpp"],
    title: "RAII & smart pointers", summary: "Make C++ resource ownership automatic",
    explanation: [
      "RAII means Resource Acquisition Is Initialization: an object's constructor acquires a resource and its destructor releases it. Scope-based cleanup runs on normal returns and during stack unwinding, making exception-safe code possible.",
      "std::unique_ptr expresses one owner and transfers ownership with move. std::shared_ptr uses reference counting for shared ownership, while weak_ptr observes without creating a reference cycle. Smart pointers are ownership tools, not replacements for every raw pointer."
    ],
    points: ["Prefer unique_ptr for single ownership.", "Use shared_ptr only when ownership is genuinely shared.", "Use weak_ptr to break shared_ptr cycles.", "Never mix ownership responsibilities or double-delete the same resource."],
    cpp: String.raw`auto file = make_unique<File>("data.txt");
shared_ptr<Logger> first = make_shared<Logger>();
shared_ptr<Logger> second = first;
cout << first.use_count(); // 2`,
    java: String.raw`// Java memory is garbage-collected.
try (Resource resource = new Resource()) {
    resource.use();
} // AutoCloseable.close() is deterministic`,
    comparison: "C++ smart pointers encode ownership in types. Java references do not encode unique/shared ownership, so use try-with-resources for external resources and clear APIs for lifecycle rules."
  },
  {
    id: "exceptions", group: "design", chapter: "Design & language", icon: "!",
    title: "Exceptions & error-safe objects", summary: "Report failures without corrupting object state",
    explanation: [
      "Exceptions separate normal control flow from failure handling. A constructor or method should either establish its promised state or report failure; it should not leave a half-valid object for callers to guess about.",
      "C++ uses try/catch and standard exception types, with destructors cleaning local resources during stack unwinding. Java has checked exceptions for some declared recoverable failures and unchecked RuntimeExceptions for programming or state errors. Catch the most specific type you can handle and preserve the original cause."
    ],
    points: ["Validate at boundaries and fail with useful context.", "Do not swallow exceptions silently.", "C++ destructors should not throw during unwinding.", "Java checked exceptions are part of a method's declared API."],
    cpp: String.raw`try {
    account.withdraw(500);
} catch (const insufficient_funds& error) {
    cerr << error.what();
}`,
    java: String.raw`try {
    account.withdraw(500);
} catch (InsufficientFundsException error) {
    System.err.println(error.getMessage());
}`,
    comparison: "Both languages use stack unwinding and catch handlers. Java has checked exceptions; C++ has no checked-exception system and relies on documented behavior."
  }
];

const state = {
  filter: "all",
  search: "",
  explored: new Set(JSON.parse(localStorage.getItem("oop-explored") || "[]")),
  theme: localStorage.getItem("oop-theme") || "dark",
  language: localStorage.getItem("oop-language") || "cpp"
};

const $ = selector => document.querySelector(selector);
const $$ = selector => document.querySelectorAll(selector);

function escapeHtml(value) {
  return value.replace(/[&<>"']/g, character => ({
    "&": "&amp;", "<": "&lt;", ">": "&gt;", '"': "&quot;", "'": "&#039;"
  }[character]));
}

function filteredTopics() {
  const query = state.search.trim().toLowerCase();
  return topics.filter(topic => {
    const supportedLanguages = topic.languages || ["cpp", "java"];
    const matchesLanguage = supportedLanguages.includes(state.language);
    const matchesFilter = state.filter === "all" || topic.group === state.filter;
    const searchable = [topic.title, topic.summary, topic.chapter, topic.comparison, ...topic.points, ...topic.explanation].join(" ").toLowerCase();
    return matchesLanguage && matchesFilter && (!query || searchable.includes(query));
  });
}

function renderChapters() {
  const chapters = [...new Set(topics.map(topic => topic.chapter))];
  $("#chapterNav").innerHTML = chapters.map((chapter, index) => `
    <button class="chapter-link ${index === 0 ? "active" : ""}" type="button" data-chapter="${chapter}">
      <span class="chapter-number">${String(index + 1).padStart(2, "0")}</span>
      <span>${chapter}</span>
    </button>
  `).join("");
}

function renderTopic(topic) {
  const isExplored = state.explored.has(topic.id);
  const supportedLanguages = topic.languages || ["cpp", "java"];
  const activeLanguage = supportedLanguages.includes(state.language) ? state.language : supportedLanguages[0];
  return `
    <article class="topic-card ${isExplored ? "explored" : ""}" data-topic-id="${topic.id}">
      <div class="topic-summary" role="button" tabindex="0" aria-expanded="false">
        <span class="topic-icon">${topic.icon}</span>
        <div class="topic-heading">
          <h2>${topic.title}</h2>
          <p>${topic.summary}</p>
        </div>
        <div class="topic-meta">
          <span class="topic-tag">${topic.group}</span>
        <label class="completion-control" title="Mark topic complete">
          <input class="topic-complete" type="checkbox" ${isExplored ? "checked" : ""} aria-label="Mark ${topic.title} as complete">
          <span class="custom-check"></span>
        </label>
          <span class="chevron">⌄</span>
        </div>
      </div>
      <div class="topic-details">
        <div class="detail-grid">
          <div>
            <h3 class="detail-label">The idea</h3>
            <div class="explanation">${topic.explanation.map(paragraph => `<p>${paragraph}</p>`).join("")}</div>
            <h3 class="detail-label">Remember</h3>
            <ul class="point-list">${topic.points.map(point => `<li>${point}</li>`).join("")}</ul>
          </div>
          <div>
            <h3 class="detail-label">See it in code</h3>
            <div class="language-tabs">
              ${supportedLanguages.includes("cpp") ? `<button class="language-tab ${activeLanguage === "cpp" ? "active " : ""}cpp" type="button" data-language="cpp">C++</button>` : ""}
              ${supportedLanguages.includes("java") ? `<button class="language-tab ${activeLanguage === "java" ? "active " : ""}java" type="button" data-language="java">Java</button>` : ""}
            </div>
            ${supportedLanguages.includes("cpp") ? `<div class="code-panel ${activeLanguage === "cpp" ? "active" : ""}" data-code-language="cpp">
              <pre class="code-block"><span class="code-badge">C++</span>${escapeHtml(topic.cpp)}</pre>
            </div>` : ""}
            ${supportedLanguages.includes("java") ? `<div class="code-panel ${activeLanguage === "java" ? "active" : ""}" data-code-language="java">
              <pre class="code-block"><span class="code-badge">Java</span>${escapeHtml(topic.java)}</pre>
            </div>` : ""}
          </div>
        </div>
        <div class="comparison"><strong>Language note:</strong> ${topic.comparison}</div>
      </div>
    </article>
  `;
}

function renderTopics() {
  const visibleTopics = filteredTopics();
  $("#topicList").innerHTML = visibleTopics.map(renderTopic).join("");
  $("#emptyState").hidden = visibleTopics.length !== 0;
  bindTopicEvents();
}

function updateProgress() {
  const visibleTopics = topics.filter(topic => (topic.languages || ["cpp", "java"]).includes(state.language));
  const complete = visibleTopics.filter(topic => state.explored.has(topic.id)).length;
  const percent = Math.round((complete / visibleTopics.length) * 100);
  $("#completedCount").textContent = complete;
  $("#progressTotal").textContent = visibleTopics.length;
  $("#progressPercent").textContent = `${percent}%`;
  $("#progressFill").style.width = `${percent}%`;
  $("#topicCount").textContent = `${visibleTopics.length} topics`;
}

function toggleTopic(card) {
  const open = card.classList.toggle("open");
  card.querySelector(".topic-summary").setAttribute("aria-expanded", String(open));
}

function bindTopicEvents() {
  $$(".topic-summary").forEach(summary => {
    summary.addEventListener("click", event => {
      if (event.target.closest(".topic-complete")) return;
      toggleTopic(summary.closest(".topic-card"));
    });
    summary.addEventListener("keydown", event => {
      if (event.key === "Enter" || event.key === " ") {
        event.preventDefault();
        toggleTopic(summary.closest(".topic-card"));
      }
    });
  });
  $$(".topic-complete").forEach(checkbox => {
    checkbox.addEventListener("click", event => event.stopPropagation());
    checkbox.addEventListener("change", () => {
      const card = checkbox.closest(".topic-card");
      const id = card.dataset.topicId;
      if (checkbox.checked) {
        state.explored.add(id);
        card.classList.add("explored");
      } else {
        state.explored.delete(id);
        card.classList.remove("explored");
      }
      localStorage.setItem("oop-explored", JSON.stringify([...state.explored]));
      updateProgress();
    });
  });
}

function applyTheme() {
  document.documentElement.dataset.theme = state.theme === "light" ? "light" : "dark";
  $("#themeButton").textContent = state.theme === "light" ? "☾" : "☼";
}

function applyLanguageSelection() {
  $$(".language-choice").forEach(button => {
    button.classList.toggle("active", button.dataset.learnLanguage === state.language);
  });
}

function init() {
  renderChapters();
  renderTopics();
  updateProgress();
  applyTheme();
  applyLanguageSelection();

  $("#searchInput").addEventListener("input", event => {
    state.search = event.target.value;
    renderTopics();
  });
  $("#filterGroup").addEventListener("click", event => {
    const button = event.target.closest("[data-filter]");
    if (!button) return;
    state.filter = button.dataset.filter;
    $$(".filter-button").forEach(item => item.classList.toggle("active", item === button));
    renderTopics();
  });
  $("#topicList").addEventListener("click", event => {
    const languageTab = event.target.closest(".language-tab");
    if (!languageTab) return;
    const details = languageTab.closest(".topic-details");
    details.querySelectorAll(".language-tab").forEach(button => button.classList.remove("active"));
    details.querySelectorAll(".code-panel").forEach(panel => panel.classList.remove("active"));
    languageTab.classList.add("active");
    details.querySelector(`[data-code-language="${languageTab.dataset.language}"]`).classList.add("active");
  });
  document.querySelector(".language-switcher").addEventListener("click", event => {
    const button = event.target.closest("[data-learn-language]");
    if (!button) return;
    state.language = button.dataset.learnLanguage;
    localStorage.setItem("oop-language", state.language);
    renderTopics();
    updateProgress();
    applyLanguageSelection();
  });
  $("#chapterNav").addEventListener("click", event => {
    const button = event.target.closest("[data-chapter]");
    if (!button) return;
    const first = topics.find(topic => topic.chapter === button.dataset.chapter);
    state.search = "";
    $("#searchInput").value = "";
    state.filter = "all";
    $$(".filter-button").forEach(item => item.classList.toggle("active", item.dataset.filter === "all"));
    renderTopics();
    document.querySelector(`[data-topic-id="${first.id}"]`)?.scrollIntoView({ behavior: "smooth", block: "center" });
    $$(".chapter-link").forEach(item => item.classList.toggle("active", item === button));
  });
  $("#startButton").addEventListener("click", () => {
    document.querySelector(".topic-card")?.scrollIntoView({ behavior: "smooth", block: "center" });
    document.querySelector(".topic-summary")?.focus();
  });
  $("#themeButton").addEventListener("click", () => {
    state.theme = state.theme === "light" ? "dark" : "light";
    localStorage.setItem("oop-theme", state.theme);
    applyTheme();
  });
  document.addEventListener("keydown", event => {
    if ((event.metaKey || event.ctrlKey) && event.key.toLowerCase() === "k") {
      event.preventDefault();
      $("#searchInput").focus();
    }
  });
}

document.addEventListener("DOMContentLoaded", init);
