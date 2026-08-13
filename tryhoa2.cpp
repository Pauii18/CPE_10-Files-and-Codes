#include<iostream>


int main () {
	
	double kelvinF;
	double faren;
		
	std::cout << "Enter Temperature in Kelvin: " ;
	std::cin >> kelvinF;
	
	faren = (kelvinF - 273.15) * 9 / 5 + 32;
	
	std::cout << "The temperature in Kelvin: " << kelvinF << "\n";
	std::cout << "The temnperature in Fahrenheit: " << faren << "\n";
	
	
    return 0;
}
