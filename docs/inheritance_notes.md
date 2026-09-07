# Inheritance design notes

This lab explores the relationship between classes in a simple academic domain.

## Why Person is the base class
Every student, faculty member, and teaching assistant is a person. Shared identity fields belong in one base class.

## Why TA uses multiple inheritance
A teaching assistant is both a student and a faculty-like role. This is a standard example of multiple inheritance in C++.

## Why virtual inheritance is needed
Because both Student and Faculty inherit from Person, a naive multiple inheritance design would create two copies of Person. Virtual inheritance ensures the Person subobject is shared exactly once.

## Why virtual methods matter
A collection of Person* or std::unique_ptr<Person> can hold Student, Faculty, and TA objects. Virtual dispatch ensures the right method is called at runtime.
