# Conference Registration
A Cross-Platform Desktop Application written in C++ using the Qt Framework.

## Project Overview

- **Registration Classes**: An abstract base class `Registration` and derived classes representing various registration types (`StandardRegistration`, `StudentRegistration`, `GuestRegistration`).
- **Graphical User Interface**: A Qt Widgets-based GUI to interact with the application.
- **CMake Build System**: The project uses CMake to manage the build process.

## Features

- **Registration Management**: Add, view, and manage different types of registrations.
- **Fee Calculation**: Calculate registration fees based on the type of registration.
- **Attendee Numbers**: Display the number of attendees registered per affilaition.
- **Filter Registrations**: Filter registrations based on attendee name.
- **Export Registration List**: Exports (serializes) the registration list to an XML file.
- **Import Registration List**: Imports (deserializes) a registration list from an XML file and appends the contents to the current registration list.
- **User Interface**: Intuitive GUI for interacting with the registration system.
<img width="1112" alt="Screenshot 2024-07-16 at 18 43 00" src="https://github.com/user-attachments/assets/3f972a05-0744-4f37-a1ad-db6616388b1a">
<img width="1112" alt="Screenshot 2024-07-16 at 18 43 08" src="https://github.com/user-attachments/assets/6ea16e03-a629-49c4-b512-337289cd9080">
<img width="952" alt="Screenshot 2024-07-16 at 18 42 21" src="https://github.com/user-attachments/assets/aff71448-a1bf-44b3-865a-9acf8fdec458">
<img width="540" alt="Screenshot 2024-07-11 at 17 01 35" src="https://github.com/user-attachments/assets/bf47b5af-9967-478f-814b-2ea132827e2a">
<img width="464" alt="Screenshot 2024-07-11 at 16 57 34" src="https://github.com/user-attachments/assets/80b83476-91c6-43be-80f6-0a6d9f531fd0">
<img width="424" alt="Screenshot 2024-07-11 at 16 57 48" src="https://github.com/user-attachments/assets/eeaa6e2f-baf0-4321-9cc5-80f43f6dba05">


## Getting Started

### Prerequisites

- **Qt**: Ensure you have Qt installed (version 5 or 6).
- **CMake**: Version 3.5 or higher.
- **C++ Compiler**: Ensure you have a C++17 compatible compiler.

### Getting the source code:

#### Option 1: Download the Release
1. **Download the Release**: Navigate to the [Releases](https://github.com/mitchcamza/ConferenceRegistration/releases) page of this repository.
2. **Select the Latest Release**: Download the release with the version number formatted as `yyyy.mm.dd.<question_number>`.
3. **Extract the Files**: Extract the downloaded archive to your desired location.

#### Option 2: Clone the Repository
1. **Clone the Repository**:
    ```bash
    git clone https://github.com/mitchcamza/COS3711-02
    cd COS3711-02
    ```
2. **Checkout the COS3711-02-04 branch**
   ```bash
   git checkout COS3711-02-04
   ```

### Building the Project
1. **Navigate to the Project Directory**: Open a terminal or command prompt and navigate to the extracted project directory.
2. **Make sure the build script is executable**: On linux: 
   ```bash
   sudo chmod +x ./build_and_run.sh
   ```
4. **Run the build script**:
   ```bash
   sudo ./build_and_run.sh
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
  - `filewriter.h`, `filewriter.cpp`: Class for writing provided text to file.
  - `filereader.h`, `filereader.cpp`: Class for reading XML file.
  - `registrationlistwriter.h`, `registrationlistwriter.cpp`: Class for serializing Registration objects to XML.
  - `registrationlistreader.h`, `registrationlistreader.cpp`: Class for deserializing Registration objects from XML.
  - `registrationfactory.h`, `registrationfactory.cpp`: Factory class for creating `Registration` objects.
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

### Exporting Registrations
1. Click on "Export Registrations" in the edit menu or tool bar.
2. Browse to the desired directory using the file dialog and provide a file name to save the file.
3. Click on the "save" and the registration list will be saved to file.

**Note that selecting an existing file will overwrite its contents.**

### Importing Registrations
1. Click on "Import Registrations" in the edit menu or tool bar.
2. Browse for the XML file containing the registration list to be imported.
3. Once the file has been selected, the imported registrations will be appended to the existing registration list.

## Authors

- Mitch Campbell

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
