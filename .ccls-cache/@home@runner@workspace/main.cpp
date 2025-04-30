#include <iostream>
#include <iomanip>
using namespace std;

// Get a validated score between 0 and 10
double getScore() {
    double score;
    do {
        cout << "Enter a judge's score (0-10): ";
        cin >> score;
        if (score < 0 || score > 10) {
            cout << "Invalid score. Please enter a value between 0 and 10.\n";
        }
    } while (score < 0 || score > 10);
    return score;
}

// Find the lowest score
double findLowest(double a, double b, double c, double d, double e) {
    double lowest = a;
    if (b < lowest) lowest = b;
    if (c < lowest) lowest = c;
    if (d < lowest) lowest = d;
    if (e < lowest) lowest = e;
    return lowest;
}

// Find the highest score
double findHighest(double a, double b, double c, double d, double e) {
    double highest = a;
    if (b > highest) highest = b;
    if (c > highest) highest = c;
    if (d > highest) highest = d;
    if (e > highest) highest = e;
    return highest;
}

// Calculate average after dropping highest and lowest
double calculateAverage(double a, double b, double c, double d, double e) {
    double total = a + b + c + d + e;
    double lowest = findLowest(a, b, c, d, e);
    double highest = findHighest(a, b, c, d, e);
    return (total - lowest - highest) / 3.0;
}

int main() {
    cout << "=== Star Search Score Calculator ===\n";

    double score1 = getScore();
    double score2 = getScore();
    double score3 = getScore();
    double score4 = getScore();
    double score5 = getScore();

    double finalScore = calculateAverage(score1, score2, score3, score4, score5);

    cout << fixed << setprecision(2);
    cout << "Final contestant score: " << finalScore << endl;

    return 0;
}