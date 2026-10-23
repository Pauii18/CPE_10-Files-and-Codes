#include <iostream>
#include <stack>

void display(std::stack<int> s){
    while (!s.empty()){
        std::cout<<s.top() <<" ";
        s.pop();
    }
    std::cout<<std::endl;
}

int main (){

    std::stack<int> stack1;
    std::stack<int> stack2;
    std::cout << "Testing the stack STL" <<std::endl;
    
    
    std::cout<<std::endl;

    //isempty
    std::cout << "Start up checking, is the stack empty? " << stack1.empty() << std::endl; 

	std::cout<<std::endl;

    //push
    stack1.push(10);
    std::cout << "the top of the stack 1 is " <<stack1.top() <<std::endl;
    stack1.push(9);
    std::cout << "the top of the stack 1 is " <<stack1.top() <<std::endl;
    
	stack2.push(8);
    std::cout<<"the top of the stack 2 is? " << stack2.top() <<std::endl;

    stack1.push(7);
    std::cout<<"the top of the stack 1 is? " << stack1.top() <<std::endl;
    
    std::cout<<std::endl;
    std::cout<< "-----------------------" << std::endl;
	std::cout<<std::endl;
	
	std::cout << "Stack 1: ";  
	display(stack1);
	
	std::cout << "Stack 2: " ;
	display(stack2);
	
	std::cout<<std::endl;
	std::cout<< "-----------------------" << std::endl;
	std::cout<<std::endl;
	
	//pop
    stack1.pop();
    std::cout<<"Popping a number in stack 1, is the stack empty now? " <<stack1.empty() <<std::endl;
    
    std::cout<<"Checking the size of stack 1: " <<stack1.size() <<std::endl;
	
	std::cout<<std::endl;
	
	stack1.pop();
	std::cout<<"Popping a 2nd number in stack 1, is the stack empty now? " <<stack1.empty() <<std::endl;
    
    std::cout<<"Checking the size of stack 1: " <<stack1.size() <<std::endl;

	std::cout<<std::endl;
	std::cout<< "-----------------------" << std::endl;
	std::cout<<std::endl;
	//emplace
    stack1.emplace(99);
    std::cout << "Emplace : 99 added to stack" << std::endl;
    
    std::cout << "After Emplace Stack 1: ";  
	display(stack1);

	std::cout<<std::endl;
	std::cout<< "-----------------------" << std::endl;
	std::cout<<std::endl; 
	//swap
    stack1.swap(stack2);
    std::cout << "swap: stack 1 and stack 2 swapped successfully" << std::endl;
    
	std::cout << "Swapped Stack 1: ";  
	display(stack1);
	
	std::cout << "Swapped Stack 2: " ;
	display(stack2);
    
}
