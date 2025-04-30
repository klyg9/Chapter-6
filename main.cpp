#include <iostream>
#include <iomanip>
using namespace std;

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(int fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}

// Main function to display the table
int main() {
    cout << "=== Fahrenheit to Celsius Conversion Table ===\n\n";
    cout << left << setw(15) << "Fahrenheit" << "Celsius\n";
    cout << "-----------------------------\n";

    for (int f = 0; f <= 20; f++) {
        double celsius = fahrenheitToCelsius(f);
        cout << left << setw(15) << f << fixed << setprecision(2) << celsius << endl;
    }

    return 0;
}