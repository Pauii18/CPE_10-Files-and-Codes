#include <iostream>
#include <string>

#define maxCap 100

char stackArr[maxCap];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == maxCap - 1;
}

void push(char newData) {
    if (isFull()) {
        std::cout << "Stack Overflow" << std::endl;
        return;
    }
    stackArr[++top] = newData; // position first before writing the character
}

void pop() {
    if (isEmpty()) {
        std::cout << "Stack Underflow" << std::endl;
        return;
    }
    top--; // decrements the index down by 1
}

char Top() {
    if (isEmpty()) {
        return '\0'; // prevent viewing random garbage memory
    }
    return stackArr[top];
}

// Balance checking driver using the global stack
bool checkBalance(std::string expr) {
    // Reset global stack pointer for each new test string
    top = -1; 
    
    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        
        // Step 2a: Ignore non-bracket characters
        if (ch != '(' && ch != '{' && ch != '[' && ch != ')' && ch != '}' && ch != ']') {
            continue;
        }
        
        // Step 2b: Push opening symbols
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } 
        // Step 2c: Handle closing symbols
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty()) {
                return false; // Error: closing symbol with no opening partner
            }
            
            char open = Top();
            pop();
            
            // Step 2d: Verify matching pairs
            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '[')) {
                return false; // Error: mismatched bracket types
            }
        }
    }
    
    // Step 3: If stack is empty, it is balanced
    return isEmpty();
}

int main() {
    // The exact expressions from your assignment table image
    std::string expressions[] = {
        "(A+B)+(C-D)", 
        "((A+B)+(C-D)", 
        "((A+B)+[C-D])", 
        "((A+B)+[C-D]}"
    };
    
    std::cout << "--- Testing Array Global Stack ---\n" << std::endl;
    
    for (int i = 0; i < 4; i++) {
        std::string currentExpr = expressions[i];
        
        std::cout << "Expression: " << currentExpr << std::endl;
        
        if (checkBalance(currentExpr)) {
            std::cout << "Result: Valid (Y)\n" << std::endl;
        } else {
            std::cout << "Result: Invalid (N)\n" << std::endl;
        }
        std::cout << "--------------------------------\n" << std::endl;
    }
    
    return 0; 
}
