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

const std::string& Faculty::getRank() const noexcept {
    return rank_;
}

void Faculty::setRank(const std::string& rank) {
    if (rank.empty()) {
        throw std::invalid_argument("rank cannot be empty");
    }
    rank_ = rank;
}

const std::string& Faculty::getOffice() const noexcept {
    return office_;
}

void Faculty::setOffice(const std::string& office) {
    if (office.empty()) {
        throw std::invalid_argument("office cannot be empty");
    }
    office_ = office;
}

std::string Faculty::getRole() const {
    return "Faculty";
}

std::string Faculty::getDescription() const {
    return rank_ + " in the " + department_ + " department, office " + office_;
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
