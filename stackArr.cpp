#include <iostream>
#include <stack>
#define maxCap 6

int stackArr[maxCap];
int top = -1, i , newData;

void push();
void pop();
void Top(); 
bool Symmetric();
bool isEmpty();
bool isFull();
int choice;
void displayStack();

int main(){
    while (true){
        std::cout << "============================================\n";
        std::cout << "Stack Operations\n";
        std::cout << "1. PUSH 2. POP 3. TOP 4. Check (Symmetric or Not) 5. isEmpty 6. isFull 7. Display\n";
        std::cout << "============================================\n";
        std::cin >> choice;

        switch(choice){
            case 1 : push();
            break;
            case 2 : pop();
            break;
            case 3 : Top();
            break;
            case 4 : std::cout << "is the line up symmetric? " << Symmetric() << std::endl;
            break;
            case 5 : std::cout << "is stack empty? " << isEmpty() << std::endl;
            break;
            case 6: std::cout << "is the stack full? " << isFull () <<std::endl;
            break;
            case 7: displayStack() ;
            break; 
            default: std::cout<<"Invalid Choice" << std::endl;
            break;
        }
    }
}

bool Symmetric() {
    if (top = 5) return true;
    while (top != 5) return false;
}

bool isEmpty(){
    if(top == -1) return true;
    return false;    
}

bool isFull(){
    if( top == maxCap -1 ) return true;
    return false;
}

void push (){
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
    if(isEmpty()){
        std::cout << "Stack Underflow" << std::endl;
        return;
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
        
    }
    for (i=top; i>=0; i--){
        std::cout << stackArr[i] << std::endl;
    }

}