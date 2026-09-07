# Lab 4 — Object-Oriented Programming with Inheritance

## CS 20 — Advanced Programming with C++

This lab focuses on classes, inheritance, overriding, virtual functions, polymorphism, and object lifetime management. The problem domain is intentionally simple so students can focus on core C++ OOP concepts.

## Learning objectives

- model a real-world domain with classes;
- use inheritance to share common data and behavior;
- override virtual methods;
- use runtime polymorphism with base-class pointers/smart pointers;
- reason about multiple inheritance and virtual inheritance;
- validate input with exceptions;
- use const-correct APIs where appropriate.

## Required hierarchy

Person
├── Student
├── Faculty
└── TA

A Person stores common identity data. Student and Faculty each add domain-specific state. TA combines student and faculty responsibilities.

## Required class data

### Person
- name
- id
- email

### Student
- major
- gpa
- completedCredits

### Faculty
- department
- rank
- office

### TA
- course
- hoursPerWeek
- responsibilities

## Required methods

Each class should provide meaningful getters/setters, virtual methods such as:

- getRole()
- getDescription()
- calculateWorkload()
- display()

A `TA` is expected to show the design tradeoff between single inheritance and multiple inheritance, and to use virtual inheritance so a single Person subobject is shared correctly.

## Assignment requirements

Students must implement:

- a Person base class;
- Student derived from Person;
- Faculty derived from Person;
- TA derived from both Student and Faculty;
- constructors and destructors;
- protected/private members and public accessors;
- pure virtual functions and method overriding;
- runtime polymorphism using a collection of Person* or std::unique_ptr<Person>;
- const-correct methods;
- input validation via exceptions.

## Testing

The project must include a test suite covering:

- constructors;
- getters/setters;
- inheritance relationships;
- overridden methods;
- polymorphic dispatch;
- invalid input;
- const correctness;
- TA multiple-inheritance behavior;
- object destruction via base-class pointer.

Run:

make
make test
