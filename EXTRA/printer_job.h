#ifndef PRINTER_JOB_H
#define PRINTER_JOB_H

#include <iostream>
#include <string>

class Job {
	private:
		int jobId;
		std::string userName;
		int numPages;
		
	public:
		// FIXED: Corrected member names in the initializer list
		Job() : jobId(0), userName(""), numPages(0) {}
		
		Job(int id, std::string name, int pages) {
			jobId = id;
			userName = name;
			numPages = pages;
		}
		
		void displayJobDetails() const {
			std::cout << "[Job ID: " << jobId << " | User: " << userName 
			          << " | Pages: " << numPages << "]";
		}
		
		int getPages() const { return numPages; }
};

// FIXED: Added missing opening brace '{'
class Printer {
private:
	static const int maxCap = 10;
	Job queue[maxCap];
	int front;
	int rear;
	int size;
	
public:
	Printer() {
		front = 0;
		rear = -1;
		size = 0;
	}
	
	bool isFull() const {
		return size == maxCap;
	}
	
	bool isEmpty() const {
		return size == 0;
	} 
	
	void addJob(const Job& job) {
		if (isFull()) {
			std::cout << "Printer queue is full\n";
			return; 
		}
		
		rear = (rear + 1) % maxCap;
		queue[rear] = job;
		size++;
		
		std::cout << "Added to queue: ";
		job.displayJobDetails();
		std::cout << std::endl;
	}
	
	void processJob() {
		if (isEmpty()) {
			std::cout << "No pending jobs\n";
			return;
		}
		
		Job currentJob = queue[front];
		
		front = (front + 1) % maxCap;
		size--;
		
		std::cout << "Printing in process: ";
		currentJob.displayJobDetails();
		std::cout << " -> Successfully Printed\n";
	}
};


#endif

