CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -Iinclude -Itests
SRC_DIR := src
TEST_DIR := tests
BUILD_DIR := build

SRCS := $(filter-out $(SRC_DIR)/main.cpp,$(wildcard $(SRC_DIR)/*.cpp))
TEST_SRCS := $(filter-out $(TEST_DIR)/test_main.cpp,$(wildcard $(TEST_DIR)/*.cpp))
TEST_EXES := $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/%,$(TEST_SRCS))

.PHONY: all clean run test

all: $(BUILD_DIR)/main

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/main: $(BUILD_DIR) $(SRC_DIR)/main.cpp $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/main.cpp $(SRCS) -o $@

run: $(BUILD_DIR)/main
	./$(BUILD_DIR)/main

test: $(BUILD_DIR) $(TEST_EXES)
	for t in $(TEST_EXES); do echo "Running $$t"; ./$$t || exit $$?; done

$(BUILD_DIR)/%: $(TEST_DIR)/%.cpp $(TEST_DIR)/test_main.cpp $(SRCS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SRCS) $(TEST_DIR)/test_main.cpp $(TEST_DIR)/$*.cpp -o $@

clean:
	rm -rf $(BUILD_DIR)
