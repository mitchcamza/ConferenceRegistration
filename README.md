# COS3711-02-01
A Conference Registration Application

## Project Overview

This project is a Qt-based application designed to manage different types of registrations. It includes the following main components:

- **Registration Classes**: An abstract base class `Registration` and derived classes representing various registration types (`StandardRegistration`, `StudentRegistration`, `GuestRegistration`).
- **Graphical User Interface**: A Qt Widgets-based GUI to interact with the application.
- **CMake Build System**: The project uses CMake to manage the build process.

## Features

- **Registration Management**: Add, view, and manage different types of registrations.
- **Fee Calculation**: Calculate registration fees based on the type of registration.
- **Attendee Numbers**: Display the number of attendees registered per affilaition.
- **Filter Registrations**: Filter registrations based on attendee name.
- **User Interface**: Intuitive GUI for interacting with the registration system.
<img width="1312" alt="Screenshot 2024-07-11 at 16 57 13" src="https://github.com/user-attachments/assets/9d061f63-47ad-472e-9d9c-c7773dfb07aa">
<img width="1312" alt="Screenshot 2024-07-11 at 16 57 21" src="https://github.com/user-attachments/assets/d1472679-bcf3-4d5e-80c4-a7b5f6fa6215">
<img width="540" alt="Screenshot 2024-07-11 at 17 01 35" src="https://github.com/user-attachments/assets/bf47b5af-9967-478f-814b-2ea132827e2a">
<img width="464" alt="Screenshot 2024-07-11 at 16 57 34" src="https://github.com/user-attachments/assets/80b83476-91c6-43be-80f6-0a6d9f531fd0">
<img width="424" alt="Screenshot 2024-07-11 at 16 57 48" src="https://github.com/user-attachments/assets/eeaa6e2f-baf0-4321-9cc5-80f43f6dba05">

## Getting Started

### Prerequisites

- **Qt**: Ensure you have Qt installed (version 5 or 6).
- **CMake**: Version 3.5 or higher.
- **C++ Compiler**: Ensure you have a C++17 compatible compiler.

### Building the Project

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/mitchcamza/COS3711-02-01
    cd COS3711-02-01
    ```

2. **Configure the Project**:
    ```bash
    cmake -B build
    ```

3. **Build the Project**:
    ```bash
    cmake --build build
    ```

4. **Run the Application**:
    ```bash
    ./build/COS3711-02-01
    ```

## Project Structure

- **CMakeLists.txt**: CMake configuration file for building the project.
- **src/**: Source files for the project.
  - `main.cpp`: Entry point of the application.
  - `person.h`, `person.cpp`: Base class for all registration types.
  - `registration.h`, `registration.cpp`: Abstract class for registration.
  - `standardregistration.h`, `standardregistration.cpp`: Class for standard registration.
  - `studentregistration.h`, `studentregistration.cpp`: Class for student registration.
  - `guestregistration.h`, `guestregistration.cpp`: Class for guest registration.
  - `registrationlist.h`, `registrationlist.cpp`: Class for handling registrations.
  - `registrationmodel.h`, `registrationmodel.cpp`: Custom model of registration data.
  - `registrationfilterproxymodel.h`, `registrationfilterproxymodel.cpp`: Custom proxy model that filters data based on a filter text.
  - `registrationtypes.h`, `registrationtypes.cpp`: Provides an enumeration to represent registration types.
  - `mainwindow.h`, `mainwindow.cpp`: Main window class for the GUI.
  - `newregistrationdialog.h`, `newregistrationdialog.cpp`: Dialog for adding new registrations.
  - `totalfeesdialog.h`, `totalfeesdialog.cpp`: Dialog for displaying total fees.
  - `totalregistereddialog.h`, `totalregistereddialog.cpp`: Dialog for displaying total registrations.
  - `resources.qrc`: A resource file containing resources used.
  
## Usage

The application allows users to manage different types of registrations. The main window provides options to view and filter existing registrations, add new registrations and view the total fees and number of registrations.

### Adding a Registration

1. Click on "New Registration".
2. Fill in the required details.
3. Select the type of registration (Standrd, Student or Guest).
4. Submit the registration.

### Viewing Total Fees and Registrations

- Click on "Total Fees" to view the total registration fees.
- Click on "Total Registrations" to view the number of registrations.

### Filtering Registrations

- Begin typing the first or last name of an attendee in the search bar and the displayed results will update accordingly.
- Clear the filter by removing the text, or using the 'Clear Filter' pushbutton.

## Authors

- Mitch Campbell

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
