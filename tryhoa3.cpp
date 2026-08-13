#include <iostream>
#include <cmath> // Fixes: 'sqrt' and 'pow' is not a member of 'std'

// Declaring the function prototype above main so the compiler knows it exists
double calDistance(double x1, double x2, double y1, double y2);

int main() {
    double x1, x2, y1, y2;

    std::cout << "Enter the coordinates for point (x1, y1): ";
    std::cin >> x1 >> y1;

    std::cout << "Enter the coordinates for point (x2, y2): ";
    std::cin >> x2 >> y2;

    // Fix: Call the function normally without 'void' and store its return value
    double d = calDistance(x1, x2, y1, y2);

    std::cout << "The Distance Between The Two Points Is: " << d << "\n";

    return 0;
}

// Fix: Change return type from 'void' to 'double' since it returns a calculated value
double calDistance(double x1, double x2, double y1, double y2) {
    // Fix: Removed the broken 'std:' nested typo
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

