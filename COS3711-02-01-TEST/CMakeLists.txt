cmake_minimum_required(VERSION 3.5)

project(PersonUnitTest LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(PersonUnitTest tst_personunittest.cpp
    ../COS3711-02-01/person.cpp ../COS3711-02-01/person.h)
add_test(NAME PersonUnitTest COMMAND PersonUnitTest)

target_link_libraries(PersonUnitTest PRIVATE Qt${QT_VERSION_MAJOR}::Test)

