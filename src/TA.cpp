#include "TA.h"

TA::TA()
    : Person(), Student(), Faculty(),
      course_("CS101"), hoursPerWeek_(0.0), responsibilities_("None") {}

TA::TA(std::string name, std::string id, std::string email,
       std::string major, double gpa, int completedCredits,
       std::string department, std::string rank, std::string office,
       std::string course, double hoursPerWeek, std::string responsibilities)
    : Person(std::move(name), std::move(id), std::move(email)),
      Student(std::move(name), std::move(id), std::move(email), std::move(major), gpa, completedCredits),
      Faculty(std::move(name), std::move(id), std::move(email), std::move(department), std::move(rank), std::move(office)),
      course_(std::move(course)), hoursPerWeek_(hoursPerWeek), responsibilities_(std::move(responsibilities)) {
    if (hoursPerWeek_ < 0.0) {
        throw std::invalid_argument("hours per week cannot be negative");
    }
}

// TODO: Implement getCourse and setCourse methods.
const std::string& TA::getCourse() const noexcept { }
void TA::setCourse(const std::string& course) {  }


// TODO: Implement getHoursPerWeek and setHoursPerWeek methods.
double TA::getHoursPerWeek() const noexcept { }
void TA::setHoursPerWeek(double hoursPerWeek) {
}

//TODO: Implement getResponsibilities and setResponsibilities methods.
const std::string& TA::getResponsibilities() const noexcept {  }
void TA::setResponsibilities(const std::string& responsibilities) {  }

// TODO: Implement getRole method to return "TA".
std::string TA::getRole() const {

}

std::string TA::getDescription() const {
    return "TA for " + course_ + ", helping with " + responsibilities_;
}

double TA::calculateWorkload() const {
    return Student::calculateWorkload() + Faculty::calculateWorkload() + hoursPerWeek_;
}

void TA::display(std::ostream& os) const {
    os << "TA[" << name_ << ", id=" << id_ << ", course=" << course_
       << ", hours=" << hoursPerWeek_ << ", responsibilities=" << responsibilities_ << "]";
}

// TODO: Implement clone method to return a unique_ptr to a new TA object.
std::unique_ptr<Person> TA::clone() const {

}
