cmake_minimum_required(VERSION 3.5)

project(RegistrationModelUnitTest LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test Gui)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(RegistrationModelUnitTest tst_registrationmodelunittest.cpp
    ../../COS3711-02-01/registrationmodel.cpp ../../COS3711-02-01/registrationmodel.h
    ../../COS3711-02-01/guestregistration.cpp ../../COS3711-02-01/guestregistration.h
    ../../COS3711-02-01/registration.cpp ../../COS3711-02-01/registration.h
    ../../COS3711-02-01/registrationlist.cpp ../../COS3711-02-01/registrationlist.h
    ../../COS3711-02-01/standardregistration.cpp ../../COS3711-02-01/standardregistration.h
    ../../COS3711-02-01/studentregistration.cpp ../../COS3711-02-01/studentregistration.h
    ../../COS3711-02-01/person.cpp ../../COS3711-02-01/person.h)
add_test(NAME RegistrationModelUnitTest COMMAND RegistrationModelUnitTest)

target_link_libraries(RegistrationModelUnitTest
    PRIVATE Qt${QT_VERSION_MAJOR}::Test
    PRIVATE Qt${QT_VERSION_MAJOR}::Gui
)
