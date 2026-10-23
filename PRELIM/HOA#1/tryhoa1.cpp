#include<iostream>


int main () {
    int a1 = 9;
    int a2 = 87;
    int temp;
    
    std::cout << "This is before the swap (a1,a2): " << "(" << a1 << "," << a2 << ")" <<  std::endl;
    
    temp = a1;
    a1 = a2;
    a2 = temp;
    
    std::cout << "This is after the swap (a1,a2): " << "(" << a1 << "," << a2 << ")" <<  std::endl;

    return 0;
}
