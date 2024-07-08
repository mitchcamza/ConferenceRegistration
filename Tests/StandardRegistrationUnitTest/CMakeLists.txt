cmake_minimum_required(VERSION 3.5)

project(StandardRegistrationUnitTest LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(StandardRegistrationUnitTest
    tst_standardregistrationunittest.cpp
    ../../COS3711-02-01/person.cpp ../../COS3711-02-01/person.h
    ../../COS3711-02-01/registration.cpp ../../COS3711-02-01/registration.h
    ../../COS3711-02-01/standardregistration.cpp ../../COS3711-02-01/standardregistration.h
)
add_test(NAME StandardRegistrationUnitTest COMMAND StandardRegistrationUnitTest)

target_link_libraries(StandardRegistrationUnitTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)
