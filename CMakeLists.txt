cmake_minimum_required(VERSION 3.5)

project(ConferenceRegistration VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Xml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Xml)

set(PROJECT_SOURCES
    src/main.cpp

    # Core Classes
    "src/core_classes/person.cpp"
    "src/core_classes/person.h"
    "src/core_classes/registration.cpp"
    "src/core_classes/registration.h"
    "src/core_classes/standardregistration.cpp"
    "src/core_classes/standardregistration.h"
    "src/core_classes/studentregistration.cpp"
    "src/core_classes/studentregistration.h"
    "src/core_classes/guestregistration.cpp"
    "src/core_classes/guestregistration.h"

    # Data Management
    "src/data_management/registrationlist.cpp"
    "src/data_management/registrationlist.h"
    "src/data_management/registrationfactory.cpp"
    "src/data_management/registrationfactory.h"
    "src/data_management/registrationtypes.cpp"
    "src/data_management/registrationtypes.h"

    # Qt Models
    "src/qt_models/registrationmodel.cpp"
    "src/qt_models/registrationmodel.h"
    "src/qt_models/registrationfilterproxymodel.cpp"
    "src/qt_models/registrationfilterproxymodel.h"

    # Serialization
    "src/serialization/filewriter.cpp"
    "src/serialization/filewriter.h"
    "src/serialization/filereader.cpp"
    "src/serialization/filereader.h"
    "src/serialization/registrationlistwriter.cpp"
    "src/serialization/registrationlistwriter.h"
    "src/serialization/registrationlistreader.cpp"
    "src/serialization/registrationlistreader.h"

    # UI Components
    "src/ui_components/mainwindow.cpp"
    "src/ui_components/mainwindow.h"
    "src/ui_components/newregistrationdialog.cpp"
    "src/ui_components/newregistrationdialog.h"
    "src/ui_components/totalfeesdialog.cpp"
    "src/ui_components/totalfeesdialog.h"
    "src/ui_components/totalregistereddialog.cpp"
    "src/ui_components/totalregistereddialog.h"

    # Resources
    resources/resources.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ConferenceRegistration
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ConferenceRegistration APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ConferenceRegistration SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ConferenceRegistration
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ConferenceRegistration PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(ConferenceRegistration PRIVATE Qt6::Xml)

target_include_directories(ConferenceRegistration PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    "${CMAKE_CURRENT_SOURCE_DIR}/src/core_classes"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/data_management"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/qt_models"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/serialization"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ui_components"
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ConferenceRegistration)
endif()
set_target_properties(ConferenceRegistration PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ConferenceRegistration
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ConferenceRegistration)
endif()
