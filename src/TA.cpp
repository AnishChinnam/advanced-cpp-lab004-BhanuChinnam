#include "TA.h"

// Person is a virtual base, so the most-derived class initializes it directly.
// The Person(...) initializers inside Student and Faculty are ignored here,
// which is exactly what keeps a single shared Person subobject.
TA::TA()
    : Person(), Student(), Faculty(),
      course_("CS101"), hoursPerWeek_(0.0), responsibilities_("None") {}

TA::TA(std::string name, std::string id, std::string email,
       std::string major, double gpa, int completedCredits,
       std::string department, std::string rank, std::string office,
       std::string course, double hoursPerWeek, std::string responsibilities)
    : Person(name, id, email),
      Student(name, id, email, std::move(major), gpa, completedCredits),
      Faculty(std::move(name), std::move(id), std::move(email),
              std::move(department), std::move(rank), std::move(office)),
      course_(std::move(course)), hoursPerWeek_(hoursPerWeek),
      responsibilities_(std::move(responsibilities)) {
    if (hoursPerWeek_ < 0.0) {
        throw std::invalid_argument("hours per week cannot be negative");
    }
}

const std::string& TA::getCourse() const noexcept {
    return course_;
}

void TA::setCourse(const std::string& course) {
    if (course.empty()) {
        throw std::invalid_argument("course cannot be empty");
    }
    course_ = course;
}

double TA::getHoursPerWeek() const noexcept {
    return hoursPerWeek_;
}

void TA::setHoursPerWeek(double hoursPerWeek) {
    if (hoursPerWeek < 0.0) {
        throw std::invalid_argument("hours per week cannot be negative");
    }
    hoursPerWeek_ = hoursPerWeek;
}

const std::string& TA::getResponsibilities() const noexcept {
    return responsibilities_;
}

void TA::setResponsibilities(const std::string& responsibilities) {
    responsibilities_ = responsibilities;
}

std::string TA::getRole() const {
    return "TA";
}

std::string TA::getDescription() const {
    return "TA for " + course_ + ", helping with " + responsibilities_;
}

// A TA's load is the student side plus the teaching side plus assigned hours.
double TA::calculateWorkload() const {
    return Student::calculateWorkload() + Faculty::calculateWorkload() + hoursPerWeek_;
}

void TA::display(std::ostream& os) const {
    os << "TA[" << name_ << ", id=" << id_ << ", course=" << course_
       << ", hours=" << hoursPerWeek_ << ", responsibilities=" << responsibilities_ << "]";
}

// Virtual copy: returns a base pointer that owns a real TA.
std::unique_ptr<Person> TA::clone() const {
    return std::make_unique<TA>(*this);
}
