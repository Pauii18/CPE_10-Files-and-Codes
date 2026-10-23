#include<iostream>
class Triangle{

    private:
        double totalAngle, angleA, angleB, angleC;
    public:
        Triangle(double A, double B, double C);
        void setAngles(double A, double B, double C);
        const bool validateTriangle();
};



int main () {
    //#1 create a function thatwill take two numbers and display the sum
    int sumOfTwoNum(int fNum, int sNum);

    std::cout << "the sum of the two numbers is: " << sumOfTwoNum(6,7) << "\n\n";
    
    
     // #2 Create a function that will return whether variable A is greater than variable B
    void agreaterb(int varA, int varB);
    agreaterb(8, 9);
    

    // #3 Create a function that will take two Boolean values and display the result of all logical operations then return true if it was a success.
    bool bulV(bool a, bool b);
    bulV(0,1); 
    std::cout << "Function returned success status: " << std::boolalpha << bulV << "\n\n";
    
    	Triangle set1(40,50,110);
	if(set1.validateTriangle()){
		std::cout<<"the shape is a valid triangle \n.";
	}else{
		std::cout<<"the shape is a NOT valid triangle \n.";
	}

    return 0;
}
// #1
int sumOfTwoNum(int fNum, int sNum){
    
    int sum = fNum + sNum;
    return sum;
}
// #2 
void agreaterb(int varA,int varB){
    if (varA > varB) {
        std::cout << "Comparison between A and B: " << varA << " is greater than " << varB << "\n\n";

    }else{
        std::cout << "Comparison between A and B: " << varA << " is less than  " << varB <<"\n\n";
    }
        
}
// # 3 
bool bulV(bool a, bool b) {
    std::cout << std::boolalpha;

    
    std::cout << "Logical AND (" << a << ", " << b << "): " << (a && b) << "\n\n";
    std::cout << "Logical OR  (" << a << ", " << b << "): " << (a || b) << "\n\n";
    std::cout << "Logical NOT (!" << a << "): " << (!a) << "\n\n";
    std::cout << "Logical NOT (!" << b << "): " << (!b) << "\n\n";

    return true;
}

	Triangle::Triangle(double A, double B, double C){
	angleA = A;
	angleB = B;
	angleC = C;
	totalAngle = A+B+C;
	
}

void Triangle::setAngles(double A, double B, double C){
	angleA = A;
	angleB = B;
	angleC = C;
	totalAngle = A+B+C;
}

// to fix an error in my code
const bool Triangle::validateTriangle() {
    // A triangle is valid if all angles are greater than 0 and their sum is exactly 180
    if (angleA > 0 && angleB > 0 && angleC > 0 && totalAngle == 180.0) {
        return true;
    }
    return false;
}
 
