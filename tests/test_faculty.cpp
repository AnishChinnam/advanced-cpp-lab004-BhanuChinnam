#include "test_framework.h"
#include "Faculty.h"

namespace {
void test_faculty_state() {
    Faculty faculty("Dr. Smith", "F102", "smith@school.edu", "Math", "Associate Professor", "M-214");
    REQUIRE(faculty.getDepartment() == "Math");
    REQUIRE(faculty.getRank() == "Associate Professor");
    REQUIRE(faculty.getOffice() == "M-214");
    REQUIRE(faculty.getRole() == "Faculty");
}

void test_faculty_validation() {
    REQUIRE_THROWS(Faculty("Dan", "F1", "dan@school.edu", "", "Professor", "A-1"));
}
}

REGISTER_TEST("Faculty stores department, rank, and office", test_faculty_state);
REGISTER_TEST("Faculty rejects empty department", test_faculty_validation);
