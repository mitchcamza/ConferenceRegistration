cmake_minimum_required(VERSION 3.5)

project(StudentRegistrationUnitTest LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(StudentRegistrationUnitTest tst_studentregistrationunittest.cpp
    ../../COS3711-02-01/person.cpp ../../COS3711-02-01/person.h
    ../../COS3711-02-01/registration.cpp ../../COS3711-02-01/registration.h
    ../../COS3711-02-01/studentregistration.cpp ../../COS3711-02-01/studentregistration.h)
add_test(NAME StudentRegistrationUnitTest COMMAND StudentRegistrationUnitTest)

target_link_libraries(StudentRegistrationUnitTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)

