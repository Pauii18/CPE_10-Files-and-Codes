#include <iostream>
#include "queueArr.h"

int main(){
	//creating an object
	std::cout << "------------------------------------------------- \n";
	std::cout << " Testing Initialization and Enqueue \n";
	std::cout << "------------------------------------------------- \n";	
	queueArr<int> q(5);
	
	std::cout<<std::endl;
	std::cout << "Is my queue empty? " << (q.Empty() ? "yes" : "no") << std::endl;
	std::cout<<std::endl;
	
	q.Enqueue(10);
	std::cout << "Queue Size: " << q.Size() << std::endl;
	std::cout << "Is my queue full? " << (q.Full() ? "yes" : "no" ) <<std::endl;
	std::cout << "Front Element: " << q.Front() << std::endl;
	std::cout << "Back Element: " << q.Back() << std::endl;
	std::cout<<std::endl;
	
	q.Enqueue(20);
	std::cout << "Queue Size: " << q.Size() << std::endl;
	std::cout << "Is my queue full? " << (q.Full() ? "yes" : "no" ) <<std::endl;
	std::cout << "Front Element: " << q.Front() << std::endl;
	std::cout << "Back Element: " << q.Back() << std::endl;
	std::cout<<std::endl;
	
	q.Enqueue(30);
	std::cout << "Queue Size: " << q.Size() << std::endl;
	std::cout << "Is my queue full? " << (q.Full() ? "yes" : "no" ) <<std::endl;
	std::cout << "Front Element: " << q.Front() << std::endl;
	std::cout << "Back Element: " << q.Back() << std::endl;
	std::cout<<std::endl;
	
	q.Enqueue(40);
	std::cout << "Queue Size: " << q.Size() << std::endl;
	std::cout << "Is my queue full? " << (q.Full() ? "yes" : "no" ) <<std::endl;
	std::cout << "Front Element: " << q.Front() << std::endl;
	std::cout << "Back Element: " << q.Back() << std::endl;
	std::cout<<std::endl;
	
	q.Enqueue(50);
	std::cout << "Queue Size: " << q.Size() << std::endl;
	std::cout << "Is my queue full? " << (q.Full() ? "yes" : "no" ) <<std::endl;
	std::cout << "Front Element: " << q.Front() << std::endl;
	std::cout << "Back Element: " << q.Back() << std::endl;
	std::cout<<std::endl;
	
	std::cout << "------------------------------------------------- \n";
	std::cout << " Testing Overflow Trigger \n";
	std::cout << "------------------------------------------------- \n";
	q.Enqueue(60);
	std::cout<<std::endl;
	std::cout << std::endl;
	
	std::cout << "------------------------------------------------- \n";
	std::cout << " Testing Dequeue \n";
	std::cout << "------------------------------------------------- \n";
	std::cout << "Dequeue: " << q.Dequeue() << std::endl;
	std::cout << "Dequeue: " << q.Dequeue() << std::endl;
	std::cout << "New Front Element: " << q.Front() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "------------------------------------------------- \n";
	std::cout << " Testing Circular \n";
	std::cout << "------------------------------------------------- \n";
	q.Enqueue(70);
 	q.Enqueue(80);
	std::cout << "New Back Element: " << q.Back() << std::endl;
 	std::cout << "Current Size: " << q.Size()	 << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "------------------------------------------------- \n";
	std::cout << " Testing Clear and Underflow \n";
	std::cout << "------------------------------------------------- \n";
	q.Clear();
	std::cout << "Size after clear: " << q.Size() << std::endl;
 	q.Dequeue();
 	std::cout << std::endl;
 	std::cout << std::endl;
 	
 	std::cout << "------------------------------------------------- \n";
	std::cout << " Testing Copy Constructor \n";
	std::cout << "------------------------------------------------- \n";
	queueArr<int> qA(5);
	qA.Enqueue(100);
	qA.Enqueue(200);
	
	queueArr<int> qB = qA;
	std::cout << "Queue B front: " << qB.Front() << std::endl;
	
	qA.Dequeue();
	std::cout << "After modifying the front is still: " <<qB.Front() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "------------------------------------------------- \n";
	std::cout << " END \n";
	std::cout << "------------------------------------------------- \n";
	return 0;
}
