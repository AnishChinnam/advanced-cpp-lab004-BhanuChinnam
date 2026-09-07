#include "Faculty.h"

Faculty::Faculty() : Person(), department_("General"), rank_("Instructor"), office_("TBD") {}

Faculty::Faculty(std::string name, std::string id, std::string email,
                 std::string department, std::string rank, std::string office)
    : Person(std::move(name), std::move(id), std::move(email)),
      department_(std::move(department)), rank_(std::move(rank)), office_(std::move(office)) {
    if (department_.empty()) {
        throw std::invalid_argument("department cannot be empty");
    }
}

const std::string& Faculty::getDepartment() const noexcept { return department_; }
void Faculty::setDepartment(const std::string& department) {
    if (department.empty()) {
        throw std::invalid_argument("department cannot be empty");
    }
    department_ = department;
}

// TODO: Implement getRank and setRank methods.
const std::string& Faculty::getRank() const noexcept { }
void Faculty::setRank(const std::string& rank) { }

//TODO: Implement getOffice and setOffice methods.
const std::string& Faculty::getOffice() const noexcept {}
void Faculty::setOffice(const std::string& office) { }


//TODO: Implement getRole method to return "Faculty".
std::string Faculty::getRole() const {

}

//TODO: Implement getDescription method to return a string describing the faculty member.
std::string Faculty::getDescription() const {
    
}

double Faculty::calculateWorkload() const {
    return 10.0 + static_cast<double>(department_.size()) * 0.25;
}

void Faculty::display(std::ostream& os) const {
    os << "Faculty[" << name_ << ", id=" << id_ << ", department=" << department_
       << ", rank=" << rank_ << ", office=" << office_ << "]";
}

std::unique_ptr<Person> Faculty::clone() const {
    return std::make_unique<Faculty>(*this);
}
