#include <iostream>
#include <string>
#include "printer_job.h"

int main() {
	Printer p;
	
	std::cout << "------------------------------------ \n";
	std::cout << "Simulating Job Additions\n";
	std::cout << "------------------------------------ \n";
	 
	p.addJob( Job (107, "Paul", 9));
	p.addJob( Job (108, "Sarah", 2));
	p.addJob( Job (109, "Rade", 4));
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "------------------------------------ \n";
	std::cout << "Simulating Printer Processing\n";
	std::cout << "------------------------------------ \n";
	
	p.processJob();
	p.processJob();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "------------------------------------ \n";
	std::cout << "Adding more assignment\n";
	std::cout << "------------------------------------ \n";
	p.addJob(Job(110, "Diana", 3));
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "------------------------------------ \n";
	std::cout << "Processing Remaining Job\n";
	std::cout << "------------------------------------ \n";
	p.processJob();
	p.processJob();
	p.processJob();
	std::cout << std::endl;
	std::cout << std::endl;
	
	return 0;
		
}
