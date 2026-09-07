#include "test_framework.h"

int main() {
    for (const auto& test : test_framework::registry()) {
        try {
            test.fn();
            std::cout << "[PASS] " << test.name << std::endl;
        } catch (const std::exception& ex) {
            std::cerr << "[FAIL] " << test.name << ": " << ex.what() << std::endl;
            return 1;
        }
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}
