#include "test_framework.h"
#include "Student.h"

namespace {
void test_student_state() {
    Student student("Bob", "S101", "bob@school.edu", "CS", 3.7, 90);

    REQUIRE(student.getName() == "Bob");
    REQUIRE(student.getMajor() == "CS");
    REQUIRE(student.getGpa() == Approx(3.7));
    REQUIRE(student.getCompletedCredits() == 90);
    REQUIRE(student.getRole() == "Student");
}

void test_student_validation() {
    REQUIRE_THROWS(Student("Bad", "S1", "bad@school.edu", "CS", -1.0, 0));
    REQUIRE_THROWS(Student("Bad", "S1", "bad@school.edu", "CS", 5.0, 0));
    REQUIRE_THROWS(Student("Bad", "S1", "bad@school.edu", "CS", 3.5, -1));
}
}

REGISTER_TEST("Student stores realistic state", test_student_state);
REGISTER_TEST("Student validates GPA and credits", test_student_validation);
