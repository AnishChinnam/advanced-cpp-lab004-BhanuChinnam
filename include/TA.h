#pragma once

#include "Student.h"
#include "Faculty.h"

class TA : public Student, public Faculty {
public:
    TA();
    TA(std::string name, std::string id, std::string email,
       std::string major, double gpa, int completedCredits,
       std::string department, std::string rank, std::string office,
       std::string course, double hoursPerWeek, std::string responsibilities);

    const std::string& getCourse() const noexcept;
    void setCourse(const std::string& course);

    double getHoursPerWeek() const noexcept;
    void setHoursPerWeek(double hoursPerWeek);

    const std::string& getResponsibilities() const noexcept;
    void setResponsibilities(const std::string& responsibilities);

    std::string getRole() const override;
    std::string getDescription() const override;
    double calculateWorkload() const override;
    void display(std::ostream& os) const override;
    std::unique_ptr<Person> clone() const override;

protected:
    std::string course_;
    double hoursPerWeek_;
    std::string responsibilities_;
};
