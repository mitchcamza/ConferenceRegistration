# Conference Registration System
[![CI](https://github.com/mitchcamza/ConferenceRegistration/actions/workflows/ci.yml/badge.svg)](https://github.com/mitchcamza/ConferenceRegistration/actions/workflows/ci.yml)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
![C++](https://img.shields.io/badge/C++-17-blue.svg)
![Qt](https://img.shields.io/badge/Qt-5%20%7C%206-green.svg)

## 📋 Table of Contents
- [About This Project](#about-this-project)
- [Technical Skills Demonstrated](#technical-skills-demonstrated)
- [Key Technical Highlights](#key-technical-highlights)
- [Features](#features)
- [Screenshots](#screenshots)
- [Getting Started](#getting-started)
- [Project Structure](#project-structure)
- [Testing](#testing)
- [Usage](#usage)
- [What I Learned](#what-i-learned)
- [Future Enhancements](#future-enhancements)
- [API Documentation](#api-documentation)
- [About Me](#about-me)
- [License](#license)

<a id="about-this-project"></a>
## 🎯 About This Project

Conference Registration is a professional-grade, cross-platform desktop application that streamlines the management of conference attendees. Built with C++ and the Qt Framework, this project demonstrates enterprise-level software engineering practices including object-oriented design, design patterns, and modern C++ development.

**The Problem:** Conference organizers need an efficient way to manage different types of registrations (standard, student, and guest), calculate fees, track attendance, and maintain registration data with import/export capabilities.

**The Solution:** A robust desktop application featuring:
- Intuitive GUI for managing diverse registration types
- Real-time filtering and search capabilities
- XML-based serialization for data persistence
- Automated fee calculation based on registration type
- Cross-platform compatibility (Windows, macOS, Linux)

**Built With:**
- **Language:** C++17
- **Framework:** Qt 5/6 (Widgets)
- **Build System:** CMake 3.5+
- **CI/CD:** GitHub Actions
- **Documentation:** Doxygen

<a id="technical-skills-demonstrated"></a>
## 💼 Technical Skills Demonstrated

This project showcases proficiency in:

### Core Programming
- **C++ Development**: Modern C++17 features, STL usage, memory management
- **Object-Oriented Programming**: Inheritance, polymorphism, abstraction, encapsulation
- **Design Patterns**: Factory Pattern, Singleton Pattern, Model-View architecture

### Software Architecture
- **Separation of Concerns**: Clean separation between business logic, data models, and UI
- **SOLID Principles**: Single Responsibility, Open/Closed, Liskov Substitution
- **MVC Pattern**: Custom model implementation with Qt's Model/View framework

### Qt Framework Expertise
- **Qt Widgets**: Custom dialogs, main windows, interactive UI components
- **Qt Model/View**: Custom `QAbstractTableModel` and proxy filtering
- **Signal/Slot Mechanism**: Event-driven programming
- **Qt XML**: Serialization and deserialization using `QXmlStreamWriter` and `QXmlStreamReader`

### Development Practices
- **Build Automation**: CMake for cross-platform builds
- **CI/CD**: Automated builds and testing using GitHub Actions
- **Unit Testing**: Comprehensive test suite using GoogleTest framework
- **UI Testing**: Qt Test framework for GUI component testing
- **Code Coverage**: lcov/genhtml integration with 81.5% line coverage
- **Version Control**: Git with feature branch workflow
- **Documentation**: Comprehensive Doxygen documentation
- **Code Quality**: Consistent naming conventions, well-commented code

### Additional Skills
- **Cross-Platform Development**: Linux, Windows, macOS compatibility
- **File I/O Operations**: XML parsing, file system operations
- **Data Filtering**: Custom proxy models for real-time search
- **Resource Management**: Qt resource system integration

<a id="key-technical-highlights"></a>
## 🔧 Key Technical Highlights

### 1. **Factory Pattern Implementation**
Implemented a singleton Factory class to create different registration types dynamically:
```cpp
Registration *createRegistration(const QString &type, ...);
```

### 2. **Custom Qt Model**
Built a custom `QAbstractTableModel` to display registration data with real-time updates:
- Overrode virtual methods (`data()`, `headerData()`, `rowCount()`)
- Integrated with Qt's Model/View architecture
- Supports dynamic data insertion and filtering

### 3. **Proxy Model for Filtering**
Developed a custom `QSortFilterProxyModel` for real-time name-based filtering without modifying the underlying data model.

### 4. **XML Serialization**
Implemented complete serialization/deserialization system:
- Custom XML schema design
- Robust error handling for malformed files
- Support for appending imported data

### 5. **Polymorphic Design**
Abstract `Registration` base class with three derived types demonstrating runtime polymorphism for fee calculations and data management.

### 6. **Automated CI/CD**
GitHub Actions workflow for automated building and unit testing on multiple branches, ensuring code quality and build stability.

### 7. **Comprehensive Testing**
Implemented a robust test suite with 61 tests covering unit, integration, and UI testing:
- **Unit Tests (42)**: Core domain logic including Person class, Registration types, and Factory pattern using GoogleTest
- **Integration Tests (16)**: End-to-end XML persistence with round-trip validation and fixture-based testing using GoogleTest
- **UI Tests (3 suites, 38 test functions)**: Qt-based UI component testing using Qt Test framework
- Tests run automatically in CI pipeline ensuring code quality and preventing regressions

### 8. **Code Coverage Reporting**
Integrated code coverage reporting using lcov/genhtml:
- Achieves **81.5% line coverage** and **78.8% function coverage**
- Excludes third-party code (Qt, GoogleTest, system headers)
- HTML reports generated for detailed analysis
- Coverage metrics tracked in CI pipeline

<a id="features"></a>
## ✨ Features

- **📝 Registration Management**: Add, view, and manage different types of registrations (Standard, Student, Guest)
- **💰 Dynamic Fee Calculation**: Automatically calculate registration fees based on type
- **📊 Attendee Analytics**: Real-time display of attendee counts per affiliation
- **🔍 Smart Filtering**: Instantly filter registrations by attendee name with live updates
- **📤 Export Functionality**: Serialize registration data to XML format for backup and transfer
- **📥 Import Functionality**: Deserialize and append registration data from XML files
- **🎨 Intuitive UI**: Clean, user-friendly Qt-based interface with toolbar and menu access
- **🔄 Cross-Platform**: Runs seamlessly on Windows, macOS, and Linux

<a id="screenshots"></a>
## 📸 Screenshots

### Main Window - Viewing & Filtering Registrations
Registrations can be filtered using any of the fields
![filtering-registrations](https://github.com/user-attachments/assets/5dd71ed2-20d5-4dc2-826f-4408a68bf4d2)

### Handling XML
<img width="964" height="1144" alt="registrations-xml" src="https://github.com/user-attachments/assets/12e2a166-9436-4a98-a9cc-9702a0742c43" />


<a id="getting-started"></a>
## 🚀 Getting Started

### Prerequisites

Ensure you have the following installed on your system:

- **Qt Framework**: Version 5 or 6 ([Download Qt](https://www.qt.io/download))
- **CMake**: Version 3.5 or higher ([Download CMake](https://cmake.org/download/))
- **C++ Compiler**: C++17 compatible (GCC, Clang, MSVC)

### Installation

#### Option 1: Download Pre-built Release
1. Navigate to the [Releases](https://github.com/mitchcamza/ConferenceRegistration/releases) page
2. Download the latest release (format: `yyyy.mm.dd.<version>`)
3. Extract the archive to your desired location

#### Option 2: Build from Source
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/mitchcamza/ConferenceRegistration.git
   cd ConferenceRegistration
   ```
2. **Make the build script executable** (Linux/macOS):
   ```bash
   cd tools
   chmod +x ./build_and_run.sh
   ```

3. **Run the build script**:
   ```bash
   ./build_and_run.sh
   ```

   Or manually build:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ./ConferenceRegistration
   ```

**⏱️ Build Time:** Approximately 2-3 minutes on a modern system.
     
<a id="project-structure"></a>
## 📁 Project Structure

```
ConferenceRegistration/
├── CMakeLists.txt                      # CMake build configuration
├── resources/                          # Assets and Qt resource collection
│   ├── icons/                          # SVG icons used in the UI
│   └── resources.qrc                   # Qt resource file referencing icons
├── src/
│   ├── main.cpp                        # Application entry point
│   │
│   ├── core_classes
│   │   ├── person.h/cpp                # Base Person class
│   │   ├── registration.h/cpp          # Abstract Registration base class
│   │   ├── standardregistration.*      # Standard registration type
│   │   ├── studentregistration.*       # Student registration type
│   │   └── guestregistration.*         # Guest registration type
│   │
│   ├── data_management
│   │   ├── registrationlist.h/cpp      # Registration collection manager
│   │   ├── registrationfactory.*       # Factory pattern for creating registrations
│   │   └── registrationtypes.*         # Registration type enumerations
│   │
│   ├── qt_models
│   │   ├── registrationmodel.*         # Custom QAbstractTableModel
│   │   └── registrationfilterproxymodel.* # Filter proxy for search
│   │
│   ├── ui_components
│   │   ├── mainwindow.*                # Main application window
│   │   ├── newregistrationdialog.*     # Add registration dialog
│   │   ├── totalfeesdialog.*           # Display total fees
│   │   └── totalregistereddialog.*     # Display attendee counts
│   │
│   └── serialization
│       ├── filewriter.h/cpp            # Generic file writing
│       ├── filereader.h/cpp            # Generic file reading
│       ├── registrationlistwriter.*    # XML serialization
│       └── registrationlistreader.*    # XML deserialization
│
├── tests/
│   ├── unit/                           # Unit tests (42 tests)
│   │   ├── person_test.cpp             # Person class tests
│   │   ├── registration_test.cpp       # Registration types tests
│   │   └── registrationfactory_test.cpp # Factory pattern tests
│   │
│   ├── integration/                    # Integration tests (16 tests)
│   │   ├── xml_persistence_test.cpp    # End-to-end XML I/O tests
│   │   └── README.md                   # Integration test documentation
│   │
│   ├── ui/                             # UI tests (3 suites, 38 test functions)
│   │   ├── mainwindow_test.cpp         # MainWindow UI tests
│   │   ├── newregistrationdialog_test.cpp # Dialog UI tests
│   │   ├── statistics_dialogs_test.cpp # Statistics dialogs tests
│   │   └── README.md                   # UI test documentation
│   │
│   └── fixtures/
│       └── xml/                        # Test fixture files
│           ├── valid_standard.xml      # Valid test data
│           ├── malformed.xml           # Error case fixtures
│           └── README.md               # Fixture documentation
│
└── tools/
   ├── build_and_run.sh                # Helper build script
   ├── coverage_summary.sh             # Coverage metrics script
   └── registrationgenerator.py        # Utility script for generating registrations
```

**Total Lines of Code:** ~3,200 lines across 45+ files
  
<a id="testing"></a>
## 🧪 Testing

The project includes a comprehensive test suite to ensure code reliability and correctness. Tests are fast, deterministic, and suitable for CI/CD pipelines, covering unit-level logic, end-to-end integration scenarios, and UI component testing.

### Test Coverage

The test suite includes **61 tests** covering:

#### Unit Tests (42 tests)
Using **GoogleTest** framework:
- **Person Tests (6 tests)**: Constructor validation, empty/whitespace handling, special characters, and boundary testing
- **Registration Tests (17 tests)**: Fee calculations for all registration types (Standard: $100, Student: $50, Guest: $10), booking date validation, and toString formatting
- **RegistrationFactory Tests (19 tests)**: Singleton pattern verification, registration creation, case-insensitive type handling, and edge case validation

#### Integration Tests (16 tests)
Using **GoogleTest** framework:
- **Round-trip Integrity (5 tests)**: Write registrations to XML, read them back, and verify data integrity across all registration types
- **Golden File Fixtures (4 tests)**: Parse known-good XML files and validate correct deserialization behavior
- **Error & Edge Cases (7 tests)**: Malformed XML handling, missing required fields, missing type attributes, empty files, non-existent files, read-only locations, and deterministic output verification

#### UI Tests (3 suites, 38 test functions)
Using **Qt Test** framework:
- **MainWindow Tests (11 tests)**: Window initialization, menu structure (File, Edit, Reports), toolbar, table view/model, search widget
- **NewRegistrationDialog Tests (14 tests)**: Dialog initialization, form fields, validation, registration type switching, conditional field visibility (student qualification, guest category)
- **Statistics Dialogs Tests (13 tests)**: TotalFeesDialog and TotalRegisteredDialog initialization, calculations, and display

#### Code Coverage
- **Line Coverage**: 81.5% (555 of 681 lines)
- **Function Coverage**: 78.8% (78 of 99 functions)
- Coverage reports generated using lcov/genhtml
- Excludes third-party code (Qt, GoogleTest, system headers)

### Running Tests

#### Build and Run All Tests
```bash
cd build
# Set headless mode for UI tests
export QT_QPA_PLATFORM=offscreen
ctest --output-on-failure
```

#### Run Unit Tests Only
```bash
cd build/tests/unit
./unit_tests
```

#### Run Integration Tests Only
```bash
cd build
ctest --output-on-failure -R XmlPersistence
```

#### Run UI Tests Only
```bash
cd build
export QT_QPA_PLATFORM=offscreen
ctest --output-on-failure -R "MainWindowTests|NewRegistrationDialogTests|StatisticsDialogsTests"

# Or run individually
cd tests/ui
./mainwindow_test
./newregistrationdialog_test
./statistics_dialogs_test
```

#### Run Specific Tests
```bash
# Unit tests
./unit_tests --gtest_filter=PersonTest.*
./unit_tests --gtest_filter=RegistrationFactoryTest.CreateStandardRegistration*

# Integration tests
cd build/tests/integration
./integration_tests --gtest_filter=XmlPersistenceTest.RoundTripStandardRegistration
```

#### Generate Code Coverage Report
```bash
# Build with coverage enabled
cmake -S . -B build -DENABLE_COVERAGE=ON
cd build
make

# Run tests
export QT_QPA_PLATFORM=offscreen
ctest --output-on-failure

# Generate coverage report
make coverage

# View coverage summary
../tools/coverage_summary.sh

# View HTML report
xdg-open coverage_report/index.html  # Linux
open coverage_report/index.html      # macOS
```

### CI Integration

Tests run automatically on every pull request via GitHub Actions, ensuring code changes don't introduce regressions. Unit, integration, and UI tests must all pass before merging. Code coverage reports are generated and uploaded as artifacts.

**For detailed test documentation**, see:
- Unit tests: [tests/README.md](tests/README.md)
- Integration tests: [tests/integration/README.md](tests/integration/README.md)
- UI tests: [tests/ui/README.md](tests/ui/README.md)
- Test fixtures: [tests/fixtures/xml/README.md](tests/fixtures/xml/README.md)
  
<a id="usage"></a>
## 📖 Usage

The application allows users to manage different types of registrations. The main window provides options to view and filter existing registrations, add new registrations and view the total fees and number of registrations.

### Adding a Registration

1. Click on "New Registration"
2. Fill in the required details (name, email, affiliation, booking date)
3. Select the type of registration (Standard, Student, or Guest)
4. Submit the registration

### Viewing Total Fees and Registrations

- Click on "Total Fees" to view the total registration fees
- Click on "Total Registrations" to view the number of registrations per affiliation

### Filtering Registrations

- Begin typing the first or last name of an attendee in the search bar and the displayed results will update in real-time
- Clear the filter by removing the text, or using the 'Clear Filter' button

### Exporting Registrations
1. Click on "Export Registrations" in the edit menu or toolbar
2. Browse to the desired directory using the file dialog and provide a file name
3. Click on "Save" and the registration list will be saved to file

**Note:** Selecting an existing file will overwrite its contents.

### Importing Registrations
1. Click on "Import Registrations" in the edit menu or toolbar
2. Browse for the XML file containing the registration list to be imported
3. Once the file has been selected, the imported registrations will be appended to the existing registration list

### Generating Test Registrations

For testing and demonstration purposes, a Python script is provided to generate sample registration data:

1. **Navigate to the tools directory**:
   ```bash
   cd tools
   ```

2. **Run the registration generator**:
   ```bash
   python3 registrationgenerator.py
   ```

3. **Output**: The script will create a file named `registrationlist.xml` in the current directory containing 200 sample registrations with the following distribution:
   - **Student registrations**: 67 registrations (fee: $50 each)
   - **Standard registrations**: 67 registrations (fee: $100 each)
   - **Guest registrations**: 66 registrations (fee: $10 each)

4. **Import the generated file**: 
   - Launch the Conference Registration application
   - Click "Import Registrations" from the File menu or toolbar
   - Select the generated `registrationlist.xml` file
   - The 200 test registrations will be appended to your current registration list

**Note:** The generator creates sample data with placeholder names, emails, and affiliations for testing purposes. Each registration includes all required fields according to its type (qualification for students, category for guests).

<a id="what-i-learned"></a>
## 💡 What I Learned

Building this project provided hands-on experience with several important concepts:

### Technical Growth
- **Qt Framework Mastery**: Gained deep understanding of Qt's Model/View architecture, signal/slot mechanism, and widget system
- **Design Pattern Implementation**: Learned to recognize when and how to apply Factory and Singleton patterns effectively
- **Cross-Platform Development**: Understood the challenges and solutions for building applications that work across different operating systems
- **XML Processing**: Implemented robust parsing and generation of XML data with proper error handling

### Software Engineering Practices
- **Clean Architecture**: Practiced separating concerns between UI, business logic, and data layers
- **Code Organization**: Structured a medium-sized codebase with 40+ files in a maintainable way
- **Unit Testing**: Developed 42 unit tests using GoogleTest to validate individual components in isolation, ensuring each class and method works correctly independently
- **Integration Testing**: Created 16 integration tests to verify end-to-end workflows, particularly XML serialization/deserialization with round-trip validation and fixture-based testing
- **UI Testing**: Implemented 38 UI test functions using Qt Test framework to validate graphical components, ensuring proper widget initialization, user interactions, and signal/slot connections work correctly in headless mode
- **Code Coverage**: Integrated lcov/genhtml to track test coverage, achieving 81.5% line coverage and 78.8% function coverage, with HTML reports for detailed analysis
- **CI/CD Integration**: Set up automated build pipelines to catch issues early
- **Documentation**: Created comprehensive API documentation using Doxygen

### Problem-Solving Skills
- **Memory Management**: Handled Qt's parent-child object ownership model and avoided memory leaks
- **Polymorphism in Practice**: Implemented abstract base classes with multiple derived types
- **Real-time Data Filtering**: Developed efficient filtering without compromising user experience
- **Error Handling**: Implemented robust error handling for file operations and user input

<a id="future-enhancements"></a>
## 🚀 Future Enhancements

Potential improvements to demonstrate continuous learning:

- **Database Integration**: Replace XML with SQLite for better scalability and querying
- **Export Formats**: Support for CSV, JSON, and PDF export
- **Authentication**: User login system with different permission levels
- **Email Notifications**: Automated confirmation emails upon registration
- **Data Analytics**: Charts and graphs showing registration trends over time
- **Internationalization**: Multi-language support using Qt's translation system
- **Cloud Sync**: Optional cloud backup and synchronization across devices

<a id="api-documentation"></a>
## 📚 API Documentation
[View Full API Documentation](https://mitchcamza.github.io/ConferenceRegistration/)

<a id="about-me"></a>
## 👨‍💻 About Me

Hi, I'm **Mitch Campbell**, a software engineer with a passion for building practical, well-architected applications. This project demonstrates my ability to:

- Design and implement complete applications from scratch
- Write clean, maintainable, and well-documented code
- Apply software engineering principles and design patterns
- Work with modern C++ and popular frameworks like Qt
- Set up development workflows including build automation and CI/CD

I'm actively seeking junior software engineering or programmer positions where I can contribute to meaningful projects while continuing to grow my skills.

**Connect with me:**

[![LinkedIn](https://img.shields.io/badge/LinkedIn-mitch--campbell--93b18919b-blue?logo=linkedin)](https://www.linkedin.com/in/mitch-campbell-93b18919b/)
[![GitHub](https://img.shields.io/badge/GitHub-@mitchcamza-181717?logo=github)](https://github.com/mitchcamza)

<a id="license"></a>
## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

**⭐ If you found this project helpful or interesting, please consider starring the repository!**
