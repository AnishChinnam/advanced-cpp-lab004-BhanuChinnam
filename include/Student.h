#pragma once

#include "Person.h"

class Student : public virtual Person {
public:
    Student();
    Student(std::string name, std::string id, std::string email,
            std::string major, double gpa, int completedCredits);

    const std::string& getMajor() const noexcept;
    void setMajor(const std::string& major);

    double getGpa() const noexcept;
    void setGpa(double gpa);

    int getCompletedCredits() const noexcept;
    void setCompletedCredits(int credits);

    std::string getRole() const override;
    std::string getDescription() const override;
    double calculateWorkload() const override;
    void display(std::ostream& os) const override;
    std::unique_ptr<Person> clone() const override;

protected:
    std::string major_;
    double gpa_;
    int completedCredits_;
};
