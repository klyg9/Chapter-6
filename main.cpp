#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Constants
const double SQFT_PER_GALLON = 110.0;
const double HOURS_PER_GALLON = 8.0;
const double HOURLY_RATE = 25.0;

// Validated input
double getValidatedInput(string prompt, double min) {
    double value;
    do {
        cout << prompt;
        cin >> value;
        if (value < min) {
            cout << "Invalid input. Must be at least " << min << ". Try again.\n";
        }
    } while (value < min);
    return value;
}

// Get total wall space
double getTotalWallSpace(int numRooms) {
    double total = 0.0;
    for (int i = 1; i <= numRooms; i++) {
        double space = getValidatedInput("Enter square feet of wall space for room " + to_string(i) + ": ", 0);
        total += space;
    }
    return total;
}

// Calculations
int calculateGallons(double wallSpace) {
    return static_cast<int>(ceil(wallSpace / SQFT_PER_GALLON));
}

double calculateLaborHours(int gallons) {
    return gallons * HOURS_PER_GALLON;
}

double calculatePaintCost(int gallons, double pricePerGallon) {
    return gallons * pricePerGallon;
}

double calculateLaborCost(double hours) {
    return hours * HOURLY_RATE;
}

int main() {
    cout << "=== Paint Job Estimator ===\n\n";

    // Get user inputs
    int numRooms = static_cast<int>(getValidatedInput("Enter number of rooms to paint: ", 1));
    double pricePerGallon = getValidatedInput("Enter price per gallon of paint: $", 10.0);

    double totalWallSpace = getTotalWallSpace(numRooms);
    int gallons = calculateGallons(totalWallSpace);
    double laborHours = calculateLaborHours(gallons);
    double paintCost = calculatePaintCost(gallons, pricePerGallon);
    double laborCost = calculateLaborCost(laborHours);
    double totalCost = paintCost + laborCost;

    // Display results
    cout << fixed << setprecision(2);
    cout << "\n--- Paint Job Estimate ---\n";
    cout << "Total wall space: " << totalWallSpace << " sq ft\n";
    cout << "Gallons of paint required: " << gallons << endl;
    cout << "Hours of labor required: " << laborHours << endl;
    cout << "Cost of the paint: $" << paintCost << endl;
    cout << "Labor charges: $" << laborCost << endl;
    cout << "Total cost: $" << totalCost << endl;

    return 0;
}