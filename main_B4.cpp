#include <iostream>

//global declaration
#define maxCap 10

int stackArr[maxCap];
int top = -1,i, newData;
//prototype functions
void push();
void pop();
void Top();
bool isEmpty();
bool isFull();
int choice;
void displayStack();

int main(){
    //main driver

    while(true)
    {
        std::cout << "============================================\n";
        std::cout << "Stack Operations\n";
        std::cout << "1. PUSH 2. POP 3. TOP 4. isEmpty 5. isFull 6. Display\n";
        std::cout << "============================================\n";
        std::cin >> choice;

        switch(choice){
            case 1 : push();
            break;
            case 2 : pop();
            break;
            case 3 : Top();
            break;
            case 4 : std::cout << "is stack empty? " << isEmpty() << std::endl;
            break;
            case 5: std::cout << "s the stack full? " << isFull () <<std::endl;
            break;
            case 6: displayStack() ;
            break; 
            default: std::cout<<"Invaid Choice" << std::endl;
            break;
        }
    
    }
    

}

//function definition
bool isEmpty(){
    if(top == -1) return true;
    return false;
}

bool isFull(){
    if(top == maxCap -1) return true;
    return false;
}

void push(){
    //error checking
    if(isFull()){
        std::cout << "Stack Overflow" << std::endl;
        return;
    }

    //pushing to the stack
    std::cout << "Enter a New Value" << std::endl;
    std::cin >> newData;

    //how do we insert the new data in the stack
    stackArr[++top] = newData;

}

void pop(){
    if(isEmpty){
        std::cout << "Stack Underflow" << std::endl;
    }

    std::cout <<"Popping: " << stackArr[top]<<std::endl;
    top--;
}

void Top(){
    //error catching
    if(isEmpty()){
        std::cout << "The stack is Empty" <<std::endl;
        return;
    }
    //check the top value:
    std::cout << "top element: " << stackArr[top] << std::endl;
}


void displayStack(){
    if (isEmpty()){
        std::cout << "Stack is Empty" << std::endl;
        return;
        pop();
    }
    for (i=top; i>=0; i--){
        std::cout << stackArr[i] << std::endl;
    }

}
