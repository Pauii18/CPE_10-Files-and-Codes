#include<iostream>


int main ( ) {
	double Total = 0;
	double QuizScore = 0;
	int counter = 1;
	
	while (counter <= 3) {
		std::cout << "Input the score for Quiz "	<< counter << ":" << std::endl;
		std::cin >> QuizScore;
		
		Total = Total + QuizScore;
		counter = counter + 1;
	}
	
	double average = Total / 3;
	
	std::cout << "=====Results=====" << std::endl;
	std::cout << "Total Score: " << Total << std::endl;
	
	std::cout << "Average Score: " << average << std::endl;
	
	return 0;

}

