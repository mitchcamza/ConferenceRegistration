cmake_minimum_required(VERSION 3.5)

project(RegistrationListUnitTest LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test Gui)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(RegistrationListUnitTest tst_registrationlistunittest.cpp
    ../../COS3711-02-01/guestregistration.cpp ../../COS3711-02-01/guestregistration.h
    ../../COS3711-02-01/person.cpp ../../COS3711-02-01/person.h
    ../../COS3711-02-01/registration.cpp ../../COS3711-02-01/registration.h
    ../../COS3711-02-01/registrationlist.cpp ../../COS3711-02-01/registrationlist.h
    ../../COS3711-02-01/registrationmodel.cpp ../../COS3711-02-01/registrationmodel.h
    ../../COS3711-02-01/standardregistration.cpp ../../COS3711-02-01/standardregistration.h
    ../../COS3711-02-01/studentregistration.cpp ../../COS3711-02-01/studentregistration.h)
add_test(NAME RegistrationListUnitTest COMMAND RegistrationListUnitTest)

target_link_libraries(RegistrationListUnitTest
    PRIVATE Qt${QT_VERSION_MAJOR}::Test
    PRIVATE Qt${QT_VERSION_MAJOR}::Gui
)

