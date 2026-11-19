# oops_concepts

This repository contains object-oriented programming practice examples in C++ and
a separate Java-native OOP practice set.

Open [`index.html`](./index.html) in a browser to use the interactive learning
guide. The guide contains 22 detailed topics, side-by-side C++ and Java
examples, language-aware filtering, search, category filters, progress tracking,
and light/dark themes. C++-only topics such as RAII, friend access, operator
overloading, and move semantics are hidden when Java is selected.
Progress is updated only when you manually check a topic's completion box.

## Folders

- [`PracticeCodes/CPP/`](./PracticeCodes/CPP) contains the original C++ examples,
  organized by topic.
- [`PracticeCodes/Java/`](./PracticeCodes/Java) contains one focused Java OOP
  concept per file. The examples
  cover classes, encapsulation, constructors, inheritance, polymorphism,
  abstraction, interfaces, composition, aggregation, enums, and generics.
  Each file includes a detailed explanation and one runnable class with a
  `main` method.

## Website files

- [`index.html`](./index.html) contains the learning content.
- [`styles.css`](./styles.css) contains the responsive dark-theme styling.
- [`app.js`](./app.js) contains tab navigation, expandable cards, code-language
  switching, and progress tracking.

Compile all Java examples with:

```text
javac -d out PracticeCodes/Java/*.java
```