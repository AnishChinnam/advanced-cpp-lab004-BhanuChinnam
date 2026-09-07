#include "Person.h"

#include <utility>

namespace {

// Shared validation helpers. Keeping them in an anonymous namespace gives them
// internal linkage, so they stay private to this translation unit.
void requireNonEmpty(const std::string& value, const char* field) {
    if (value.empty()) {
        throw std::invalid_argument(std::string(field) + " cannot be empty");
    }
}

void requireValidEmail(const std::string& value) {
    requireNonEmpty(value, "email");
    if (value.find('@') == std::string::npos) {
        throw std::invalid_argument("email must contain '@'");
    }
}

}  // namespace

// Default constructor: placeholder identity for a not-yet-populated Person.
Person::Person()
    : name_("Unknown"), id_("UNKNOWN"), email_("unknown@example.com") {}

// Parameterized constructor: takes by value and moves, then validates.
Person::Person(std::string name, std::string id, std::string email)
    : name_(std::move(name)), id_(std::move(id)), email_(std::move(email)) {
    requireNonEmpty(name_, "name");
    requireNonEmpty(id_, "id");
    requireValidEmail(email_);
}

const std::string& Person::getName() const noexcept {
    return name_;
}

void Person::setName(const std::string& name) {
    requireNonEmpty(name, "name");
    name_ = name;
}

const std::string& Person::getId() const noexcept {
    return id_;
}

void Person::setId(const std::string& id) {
    requireNonEmpty(id, "id");
    id_ = id;
}

const std::string& Person::getEmail() const noexcept {
    return email_;
}

void Person::setEmail(const std::string& email) {
    requireValidEmail(email);
    email_ = email;
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << person.getName() << " (" << person.getId() << ")";
    return os;
}
