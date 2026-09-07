#include <iostream>
#include <memory>
#include <vector>

#include "Student.h"
#include "Faculty.h"
#include "TA.h"

int main() {
    Student student("Alice", "S1001", "alice@school.edu", "Computer Science", 3.8, 72);
    Faculty faculty("Dr. Chen", "F2002", "chen@school.edu", "Computer Science", "Professor", "B-215");
    TA ta("Sam", "T3003", "sam@school.edu", "Computer Science", 3.9, 96,
          "Computer Science", "Graduate Assistant", "C-101",
          "CS201", 8.0, "grading and office hours");

    std::vector<std::unique_ptr<Person>> people;
    people.push_back(std::make_unique<Student>(student));
    people.push_back(std::make_unique<Faculty>(faculty));
    people.push_back(std::make_unique<TA>(ta));

    for (const auto& person : people) {
        std::cout << person->getRole() << ": " << person->getDescription() << '\n';
    }

    return 0;
}
