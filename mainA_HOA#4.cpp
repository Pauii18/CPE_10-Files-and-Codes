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

    //isempty
    std::cout << "is the stack empty ? " << stack1.empty() << std::endl; 

    //push
    stack1.push(10);
    std::cout << "the top of the stack is " <<stack1.top() <<std::endl;
    stack1.push(9);
    std::cout << "the top of the stack is " <<stack1.top() <<std::endl;
    stack2.push(8);
    std::cout<<"is the stack empty? " << stack2.top() <<std::endl;

    stack1.push(7);
    std::cout<<"is the stack empty? " << stack1.top() <<std::endl;

    stack1.pop();
    std::cout<<"the top of the stack is  " <<stack1.empty() <<std::endl;
    std::cout<<"is the stack empty? " <<stack1.empty() <<std::endl;
    std::cout<<"the size of the stack is: " <<stack1.size() <<std::endl;

    stack1.emplace();
    std::cout << "emplace : " << stack1.emplace(99) << std::endl;
    
    display(stack1);

    stack1.swap();
    std::cout << "swap: 10 and 8 " << stack1.swap(stack2);



   


}