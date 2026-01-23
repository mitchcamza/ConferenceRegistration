cmake_minimum_required(VERSION 3.5)

# Find Qt packages
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Xml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Xml)

# Define source files needed for integration tests
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
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/serialization/filewriter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/serialization/filewriter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/serialization/filereader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/serialization/filereader.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/serialization/registrationlistwriter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/serialization/registrationlistwriter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/serialization/registrationlistreader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/serialization/registrationlistreader.h
)

# Integration test sources
set(INTEGRATION_TEST_SOURCES
    xml_persistence_test.cpp
)

# Create integration test executable
add_executable(integration_tests ${INTEGRATION_TEST_SOURCES} ${CORE_SOURCES})

# Enable Qt MOC for QObject-based classes
set_target_properties(integration_tests PROPERTIES AUTOMOC ON)

# Link against GoogleTest and Qt
target_link_libraries(integration_tests
    PRIVATE
    GTest::gtest_main
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Xml
)

# Include directories
target_include_directories(integration_tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/core_classes
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/data_management
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/serialization
)

# Define fixtures path as compile definition
target_compile_definitions(integration_tests PRIVATE
    FIXTURES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/../fixtures/xml"
)

# Add tests to CTest
include(GoogleTest)
gtest_discover_tests(integration_tests)
