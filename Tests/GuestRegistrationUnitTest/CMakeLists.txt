cmake_minimum_required(VERSION 3.5)

project(GuestRegistrationUnitTest LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(GuestRegistrationUnitTest tst_guestregistrationunittest.cpp
    ../../COS3711-02-01/person.cpp ../../COS3711-02-01/person.h
    ../../COS3711-02-01/registration.cpp ../../COS3711-02-01/registration.h
    ../../COS3711-02-01/guestregistration.cpp ../../COS3711-02-01/guestregistration.h
)
add_test(NAME GuestRegistrationUnitTest COMMAND GuestRegistrationUnitTest)

target_link_libraries(GuestRegistrationUnitTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)

