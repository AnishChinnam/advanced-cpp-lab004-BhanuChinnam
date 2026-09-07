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

// TODO: Implement getMajor and setMajor methods.
const std::string& Student::getMajor() const noexcept { }
void Student::setMajor(const std::string& major) {  }

// TODO: Implement getGpa and setGpa methods.
double Student::getGpa() const noexcept { }
void Student::setGpa(double gpa) {
}

// TODO: Implement getCompletedCredits and setCompletedCredits methods.
int Student::getCompletedCredits() const noexcept { }
void Student::setCompletedCredits(int credits) {
   
}

// TODO: Implement getRole method to return "Student".
std::string Student::getRole() const {

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
