#include <iostream>
#include <fstream>

int main() {
    // Open a file for writing
    std::ofstream outputFile("numbers.txt");

    // Check if the file is opened successfully
    if (!outputFile.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1; // Return with an error code
    }

    // Write a sequence of numbers to the file
    for (int i = 1; i <= 1000000; ++i) {
        outputFile << i << std::endl;
    }

    // Close the file
    outputFile.close();

    std::cout << "Numbers have been written to 'numbers.txt'." << std::endl;

    return 0; // Return with success
}

