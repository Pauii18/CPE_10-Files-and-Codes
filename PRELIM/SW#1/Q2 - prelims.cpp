#include<iostream>


int main ( ) {
	double TotalPR = 0;
	double price = 0;
	double payment = 0;
	double change = 0;
	
	for (int i = 1; i <= 3; i++) {
		std::cout << "Input the price for item " << i << ":" ;
		std::cin >> price;
		TotalPR = TotalPR + price;
	}
	
	std::cout << "\n Amount Total: " << TotalPR << std::endl;
	std::cout << "Customer Cash Payment: ";
	std::cin >> payment;
	
	change = payment - TotalPR;
	
	std::cout << "\n===Transaction Receipt===" <<std::endl;
	std::cout << "Total Price: " << TotalPR << std::endl;
	std::cout << "Payment: " << payment <<std::endl;
	std::cout << "Change: " << change << std::endl;
	
	
	return 0;

}

