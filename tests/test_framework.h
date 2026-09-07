#pragma once

#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace test_framework {
using TestFn = void (*)();

struct TestCase {
    const char* name;
    TestFn fn;
};

inline std::vector<TestCase>& registry() {
    static std::vector<TestCase> tests;
    return tests;
}

inline void add_test(const char* name, TestFn fn) {
    registry().push_back({name, fn});
}
}

#define REGISTER_TEST(name, fn) \
    namespace { \
    void fn(); \
    static bool _test_registration_##fn = (test_framework::add_test(name, &fn), true); \
    } \
    void fn()

#define REQUIRE(cond) do { if (!(cond)) throw std::runtime_error("REQUIRE failed: " #cond); } while (0)
#define REQUIRE_THROWS(expr) do { bool thrown = false; try { expr; } catch (...) { thrown = true; } if (!thrown) throw std::runtime_error("REQUIRE_THROWS failed: " #expr); } while (0)
#define Approx(value) (value)
