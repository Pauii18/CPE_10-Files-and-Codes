#include <iostream>
#include <cmath>     // Required for sqrt() and pow()
#include <string>    // Required for std::string

class Triangle {
    private:
        double totalAngle, angleA, angleB, angleC;

    public:
        // Constructor declaration
        Triangle(double A, double B, double C);
        
        void setAngles(double A, double B, double C);
        
        // Use 'const' matching your original setup
        const bool validateTriangle();

        // a. Function to compute for the area of a triangle (Heron's Formula)
        double computeArea(double a, double b, double c) {
            double s = (a + b + c) / 2.0; 
            return std::sqrt(s * (s - a) * (s - b) * (s - c));
        }

        // b. Function to compute for the perimeter of a triangle
        double computePerimeter(double a, double b, double c) {
            return a + b + c;
        }

        // c. Function that determines whether the triangle is acute, obtuse, or 'others'
        std::string determineType() {
            if (!validateTriangle()) {
                return "others (Invalid angles)";
            }
            // Check if any single angle is exactly 90 degrees (Right-angled)
            if (angleA == 90 || angleB == 90 || angleC == 90) {
                return "others (Right-angled)";
            }
            // Check if any single angle is greater than 90 degrees
            if (angleA > 90 || angleB > 90 || angleC > 90) {
                return "obtuse-angled";
            }
            // If all angles are less than 90 degrees
            return "acute-angled";
        }
};

// Dummy validation function matched from your main placeholder logic
bool bulV(bool a, bool b) {
    return a || b; 
}

int main () {
    // Standardizing your pointer/boolean display log
    std::cout << "Function returned success status: " << std::boolalpha << bulV(0, 1) << "\n\n";
    
    // Testing your test inputs (40, 50, 110)
    Triangle set1(40, 50, 110);
    
    if (set1.validateTriangle()) {
        std::cout << "the shape is a valid triangle.\n";
    } else {
        std::cout << "the shape is a NOT valid triangle.\n";
    }

    // Displaying the classification result
    std::cout << "The triangle is classified as: " << set1.determineType() << "\n\n";

    // Example execution for Perimeter and Area using sample side dimensions 
    // Example sides matching 40-50-110 setup rules: Side A=4.5, Side B=5.4, Side C=8.2
    double sideA = 4.5, sideB = 5.4, sideC = 8.2;
    std::cout << "--- Triangle Measurements ---\n";
    std::cout << "Perimeter: " << set1.computePerimeter(sideA, sideB, sideC) << "\n";
    std::cout << "Area     : " << set1.computeArea(sideA, sideB, sideC) << "\n";

    return 0;
}

// Constructor Implementation
Triangle::Triangle(double A, double B, double C) {
    setAngles(A, B, C);
}

// Member Function to Set Angles
void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

// Member Function to Validate Triangle Rules (Sum of angles must equal 180)
const bool Triangle::validateTriangle() {
    // Angles must also all be greater than zero to form a flat plane
    if (angleA <= 0 || angleB <= 0 || angleC <= 0) {
        return false;
    }
    return (totalAngle == 180.0);
}

