#include "Person.h"

// TODO: Implement default constructor and parameterized constructor with validation.
Person::Person() {}

// TODO: Implement default constructor and parameterized constructor with validation.
Person::Person(std::string name, std::string id, std::string email){
}

//TODO: Implement getName and setName methods.
const std::string& Person::getName() const noexcept { }
void Person::setName(const std::string& name) { }


// TODO: Implement getId and setId methods.
const std::string& Person::getId() const noexcept { }
void Person::setId(const std::string& id) {

}

// TODO: Implement getEmail and setEmail methods.
const std::string& Person::getEmail() const noexcept { }
void Person::setEmail(const std::string& email) {
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << person.getName() << " (" << person.getId() << ")";
    return os;
}
