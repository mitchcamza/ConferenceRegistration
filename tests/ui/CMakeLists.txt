cmake_minimum_required(VERSION 3.5)

# Find Qt packages (needed for UI testing)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Test Xml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Test Xml)

# Define source files needed for UI tests (all application sources except main.cpp)
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
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/data_management/registrationlist.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/data_management/registrationlist.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/data_management/registrationtypes.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/data_management/registrationtypes.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/qt_models/registrationmodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/qt_models/registrationmodel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/qt_models/registrationfilterproxymodel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/qt_models/registrationfilterproxymodel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/serialization/filewriter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/serialization/filewriter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/serialization/filereader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/serialization/filereader.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/serialization/registrationlistwriter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/serialization/registrationlistwriter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/serialization/registrationlistreader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/serialization/registrationlistreader.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/ui_components/mainwindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/ui_components/mainwindow.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/ui_components/newregistrationdialog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/ui_components/newregistrationdialog.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/ui_components/totalfeesdialog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/ui_components/totalfeesdialog.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/ui_components/totalregistereddialog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/ui_components/totalregistereddialog.h
)

# Common include directories
set(COMMON_INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/core_classes
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/data_management
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/qt_models
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/serialization
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/ui_components
)

# Create separate test executables for each test file
# This is required because QTEST_MAIN creates a main() function in each test

# MainWindow tests
add_executable(mainwindow_test mainwindow_test.cpp ${CORE_SOURCES})
set_target_properties(mainwindow_test PROPERTIES 
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)
target_link_libraries(mainwindow_test
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Test
    Qt${QT_VERSION_MAJOR}::Xml
)
target_include_directories(mainwindow_test PRIVATE ${COMMON_INCLUDES})
add_test(NAME MainWindowTests COMMAND mainwindow_test)

# NewRegistrationDialog tests
add_executable(newregistrationdialog_test newregistrationdialog_test.cpp ${CORE_SOURCES})
set_target_properties(newregistrationdialog_test PROPERTIES 
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)
target_link_libraries(newregistrationdialog_test
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Test
    Qt${QT_VERSION_MAJOR}::Xml
)
target_include_directories(newregistrationdialog_test PRIVATE ${COMMON_INCLUDES})
add_test(NAME NewRegistrationDialogTests COMMAND newregistrationdialog_test)

# Statistics dialogs tests
add_executable(statistics_dialogs_test statistics_dialogs_test.cpp ${CORE_SOURCES})
set_target_properties(statistics_dialogs_test PROPERTIES 
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)
target_link_libraries(statistics_dialogs_test
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Test
    Qt${QT_VERSION_MAJOR}::Xml
)
target_include_directories(statistics_dialogs_test PRIVATE ${COMMON_INCLUDES})
add_test(NAME StatisticsDialogsTests COMMAND statistics_dialogs_test)

