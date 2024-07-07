cmake_minimum_required(VERSION 3.5)

project(TestConferenceRegistration LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(PersonUnitTest/)
add_subdirectory(StandardRegistrationUnitTest/)
add_subdirectory(StudentRegistrationUnitTest/)
