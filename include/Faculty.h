#pragma once

#include "Person.h"

class Faculty : public virtual Person {
public:
    Faculty();
    Faculty(std::string name, std::string id, std::string email,
            std::string department, std::string rank, std::string office);

    const std::string& getDepartment() const noexcept;
    void setDepartment(const std::string& department);

    const std::string& getRank() const noexcept;
    void setRank(const std::string& rank);

    const std::string& getOffice() const noexcept;
    void setOffice(const std::string& office);

    std::string getRole() const override;
    std::string getDescription() const override;
    double calculateWorkload() const override;
    void display(std::ostream& os) const override;
    std::unique_ptr<Person> clone() const override;

protected:
    std::string department_;
    std::string rank_;
    std::string office_;
};
