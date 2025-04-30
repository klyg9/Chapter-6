#include <iostream>
using namespace std;

// Function to get a validated positive number
double getPositiveInput(string prompt) {
    double value;
    do {
        cout << prompt;
        cin >> value;
        if (value < 0)
            cout << "Input cannot be negative. Please try again.\n";
    } while (value < 0);
    return value;
}

// Function to calculate area
double calculateArea(double length, double width) {
    return length * width;
}

// Function to calculate perimeter
double calculatePerimeter(double length, double width) {
    return 2 * (length + width);
}

// Function to ask user if they want to continue
bool userWantsToContinue() {
    char choice;
    cout << "Would you like to process another rectangle? (Y/N): ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}

// Main program
int main() {
    cout << "=== Rectangle Properties Calculator ===\n";

    do {
        // Get valid inputs
        double length = getPositiveInput("Enter the length: ");
        double width = getPositiveInput("Enter the width: ");

        // Compute and display results
        double area = calculateArea(length, width);
        double perimeter = calculatePerimeter(length, width);

        cout << "Area: " << area << endl;
        cout << "Perimeter: " << perimeter << endl;

    } while (userWantsToContinue());

    cout << "Thank you for using the Rectangle Calculator!\n";
    return 0;
}