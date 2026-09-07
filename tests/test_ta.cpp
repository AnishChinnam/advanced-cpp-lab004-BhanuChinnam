#include "test_framework.h"
#include "TA.h"

namespace {
void test_ta_state() {
    TA ta("Tara", "T200", "tara@school.edu", "CS", 3.9, 110,
          "CS", "Graduate Assistant", "B-101", "CS210", 8.0, "grading");

    REQUIRE(ta.getRole() == "TA");
    REQUIRE(ta.getCourse() == "CS210");
    REQUIRE(ta.getHoursPerWeek() == Approx(8.0));
    REQUIRE(ta.getResponsibilities() == "grading");
    REQUIRE(ta.getMajor() == "CS");
    REQUIRE(ta.getDepartment() == "CS");
}

void test_ta_validation() {
    REQUIRE_THROWS(TA("Tara", "T200", "tara@school.edu", "CS", 3.9, 110,
                     "CS", "Graduate Assistant", "B-101", "CS210", -1.0, "grading"));
}
}

REGISTER_TEST("TA combines student and faculty responsibilities", test_ta_state);
REGISTER_TEST("TA validates hours", test_ta_validation);
