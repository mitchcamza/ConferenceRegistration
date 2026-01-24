#!/bin/bash

# Check if the script is run as root
if [[ "$EUID" -ne 0 ]]; then
  echo "Please run this script as root (use sudo)."
  exit 1
fi

# Function to install a package if not already installed
install_if_needed() {
    if ! dpkg -s "$1" >/dev/null 2>&1; then
        echo "Installing $1..."
        sudo apt-get install -y "$1"
    else
        echo "$1 is already installed."
    fi
}

# Update package list
echo "Updating package list..."
sudo apt-get update

# Check and install required packages
install_if_needed "libgl1-mesa-dev"
install_if_needed "qt6-base-dev"
install_if_needed "qt6-tools-dev"
install_if_needed "qt6-tools-dev-tools"
install_if_needed "cmake"
install_if_needed "g++"

# Navigate to the project directory
cd "$(dirname "$0")"

# Create and navigate to the build directory
mkdir -p build
cd build

# Run CMake to configure the project
echo "Configuring the project with CMake..."
cmake -S ../.. -B .

# Build the project
echo "Building the project..."
make

# Run the application
echo "Running the application..."
./ConferenceRegistration

# Print completion message
echo "Build and run completed successfully."

