#include <iostream>
#include <string>
using namespace std;

// Function to get validated accident input
int getAccidents(string regionName) {
    int accidents;
    do {
        cout << "Enter number of reported accidents in the " << regionName << " region: ";
        cin >> accidents;
        if (accidents < 0)
            cout << "Error: Number of accidents cannot be negative. Please try again.\n";
    } while (accidents < 0);
    return accidents;
}

// Function to find the region with the fewest accidents
string findLowest(int north, int south, int east, int west, int central) {
    int lowest = north;
    string region = "North";

    if (south < lowest) {
        lowest = south;
        region = "South";
    }
    if (east < lowest) {
        lowest = east;
        region = "East";
    }
    if (west < lowest) {
        lowest = west;
        region = "West";
    }
    if (central < lowest) {
        lowest = central;
        region = "Central";
    }

    return region;
}

int main() {
    cout << "=== Safest Driving Area Program ===\n";

    // Collect accident data
    int north = getAccidents("North");
    int south = getAccidents("South");
    int east = getAccidents("East");
    int west = getAccidents("West");
    int central = getAccidents("Central");

    // Determine region with fewest accidents
    string safestRegion = findLowest(north, south, east, west, central);

    // Display result
    cout << "\nThe region with the fewest accidents last year was: " << safestRegion << endl;

    return 0;
}