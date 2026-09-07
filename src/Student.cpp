#include "Student.h"

Student::Student() : Person(), major_("Undeclared"), gpa_(0.0), completedCredits_(0) {}

Student::Student(std::string name, std::string id, std::string email,
               std::string major, double gpa, int completedCredits)
    : Person(std::move(name), std::move(id), std::move(email)),
      major_(std::move(major)), gpa_(gpa), completedCredits_(completedCredits) {
    if (gpa_ < 0.0 || gpa_ > 4.0) {
        throw std::invalid_argument("gpa must be between 0.0 and 4.0");
    }
    if (completedCredits_ < 0) {
        throw std::invalid_argument("completed credits cannot be negative");
    }
}

const std::string& Student::getMajor() const noexcept {
    return major_;
}

void Student::setMajor(const std::string& major) {
    if (major.empty()) {
        throw std::invalid_argument("major cannot be empty");
    }
    major_ = major;
}

double Student::getGpa() const noexcept {
    return gpa_;
}

// Setters repeat the constructor's rule so an object cannot be pushed into an
// invalid state after construction.
void Student::setGpa(double gpa) {
    if (gpa < 0.0 || gpa > 4.0) {
        throw std::invalid_argument("gpa must be between 0.0 and 4.0");
    }
    gpa_ = gpa;
}

int Student::getCompletedCredits() const noexcept {
    return completedCredits_;
}

void Student::setCompletedCredits(int credits) {
    if (credits < 0) {
        throw std::invalid_argument("completed credits cannot be negative");
    }
    completedCredits_ = credits;
}

std::string Student::getRole() const {
    return "Student";
}

std::string Student::getDescription() const {
    return major_ + " student with GPA " + std::to_string(gpa_);
}

double Student::calculateWorkload() const {
    return 0.5 * static_cast<double>(completedCredits_) / 10.0 + 1.0;
}

void Student::display(std::ostream& os) const {
    os << "Student[" << name_ << ", id=" << id_ << ", major=" << major_
       << ", GPA=" << gpa_ << ", credits=" << completedCredits_ << "]";
}

std::unique_ptr<Person> Student::clone() const {
    return std::make_unique<Student>(*this);
}
