cmake_minimum_required(VERSION 3.5)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Find Qt packages (needed for core classes)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

# Define source files to test (core logic only, no UI)
set(CORE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/core_classes/person.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/core_classes/person.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/core_classes/registration.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/core_classes/registration.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/core_classes/standardregistration.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/core_classes/standardregistration.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/core_classes/studentregistration.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/core_classes/studentregistration.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/core_classes/guestregistration.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/core_classes/guestregistration.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/data_management/registrationfactory.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/data_management/registrationfactory.h
)

# Unit test sources
set(TEST_SOURCES
    person_test.cpp
    registration_test.cpp
    registrationfactory_test.cpp
)

# Create unit test executable
add_executable(unit_tests ${TEST_SOURCES} ${CORE_SOURCES})

# Enable Qt MOC for QObject-based classes
set_target_properties(unit_tests PROPERTIES AUTOMOC ON)

# Link against GoogleTest and Qt
target_link_libraries(unit_tests
    PRIVATE
    GTest::gtest_main
    Qt${QT_VERSION_MAJOR}::Core
)

# Include directories
target_include_directories(unit_tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/core_classes
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/data_management
)

# Add tests to CTest
include(GoogleTest)
gtest_discover_tests(unit_tests)
