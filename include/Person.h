#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

class Person {
public:
    Person();
    Person(std::string name, std::string id, std::string email);
    virtual ~Person() = default;

    const std::string& getName() const noexcept;
    void setName(const std::string& name);

    const std::string& getId() const noexcept;
    void setId(const std::string& id);

    const std::string& getEmail() const noexcept;
    void setEmail(const std::string& email);

    virtual std::string getRole() const = 0;
    virtual std::string getDescription() const = 0;
    virtual double calculateWorkload() const = 0;
    virtual void display(std::ostream& os) const = 0;
    virtual std::unique_ptr<Person> clone() const = 0;

protected:
    std::string name_;
    std::string id_;
    std::string email_;
};

std::ostream& operator<<(std::ostream& os, const Person& person);
