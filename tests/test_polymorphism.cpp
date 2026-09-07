#include <memory>
#include <vector>
#include "test_framework.h"
#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include "TA.h"

namespace {
void test_runtime_polymorphism() {
    std::vector<std::unique_ptr<Person>> people;
    people.push_back(std::make_unique<Student>("A", "S1", "a@e.com", "CS", 3.5, 30));
    people.push_back(std::make_unique<Faculty>("B", "F1", "b@e.com", "CS", "Professor", "A-1"));
    people.push_back(std::make_unique<TA>("C", "T1", "c@e.com", "CS", 3.9, 60,
                                        "CS", "TA", "A-2", "CS101", 6.0, "labs"));

    REQUIRE(people[0]->getRole() == "Student");
    REQUIRE(people[1]->getRole() == "Faculty");
    REQUIRE(people[2]->getRole() == "TA");

    REQUIRE(people[0]->calculateWorkload() > 0.0);
    REQUIRE(people[1]->calculateWorkload() > 0.0);
    REQUIRE(people[2]->calculateWorkload() > 0.0);
}

void test_virtual_inheritance() {
    TA ta("C", "T1", "c@e.com", "CS", 3.9, 60,
          "CS", "TA", "A-2", "CS101", 6.0, "labs");

    REQUIRE(ta.getId() == "T1");
    REQUIRE(ta.getName() == "C");
    REQUIRE(ta.getEmail() == "c@e.com");
}

void test_const_correctness() {
    const Student student("Alice", "S2", "a@school.edu", "Biology", 3.8, 50);
    REQUIRE(student.getRole() == "Student");
    REQUIRE(student.getGpa() == Approx(3.8));
    REQUIRE(student.calculateWorkload() > 0.0);
}
}

REGISTER_TEST("Runtime polymorphism dispatches derived classes correctly", test_runtime_polymorphism);
REGISTER_TEST("Virtual inheritance preserves one Person subobject", test_virtual_inheritance);
REGISTER_TEST("Const objects can call const methods", test_const_correctness);
