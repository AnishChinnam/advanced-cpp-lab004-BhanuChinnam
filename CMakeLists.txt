cmake_minimum_required(VERSION 3.16)
project(InheritanceLab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

add_library(personlib
    src/Person.cpp
    src/Student.cpp
    src/Faculty.cpp
    src/TA.cpp
)

target_include_directories(personlib PUBLIC include)

add_executable(person_demo src/main.cpp)
target_link_libraries(person_demo PRIVATE personlib)

add_executable(test_student tests/test_student.cpp tests/test_main.cpp)
target_link_libraries(test_student PRIVATE personlib)
add_executable(test_faculty tests/test_faculty.cpp tests/test_main.cpp)
target_link_libraries(test_faculty PRIVATE personlib)
add_executable(test_ta tests/test_ta.cpp tests/test_main.cpp)
target_link_libraries(test_ta PRIVATE personlib)
add_executable(test_polymorphism tests/test_polymorphism.cpp tests/test_main.cpp)
target_link_libraries(test_polymorphism PRIVATE personlib)

if(BUILD_TESTING)
    add_test(NAME test_student COMMAND test_student)
    add_test(NAME test_faculty COMMAND test_faculty)
    add_test(NAME test_ta COMMAND test_ta)
    add_test(NAME test_polymorphism COMMAND test_polymorphism)
endif()
