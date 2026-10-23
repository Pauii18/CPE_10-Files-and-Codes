#include <iostream>
#include "singly_ll.h"

int main (){
    //creation of node PAUE

    //creating a node stored in the stack
    SingleList<char>* head = nullptr;
    SingleList<char>* second = nullptr;
    SingleList<char>* third = nullptr;
    SingleList<char>* fourth = nullptr;

    //allocate memory in the heap
    head = new SingleList<char>;
    second = new SingleList<char>;
    third = new SingleList<char>;
    fourth = new SingleList<char>;

    //stored values in the node
    head ->data = 'P';
    second ->data = 'A';
    third ->data = 'U';
    fourth ->data = 'E';

    //link the nodes
    head ->next = second;
    second->next = third;
    third ->next = fourth;
    fourth ->next = nullptr;

    std::cout << "Testing of Traversal: \n";
    SingleListTraversal(head);

    std::cout << "\nTesting of sllinsertHead\n";
    sllinsertHead('Q', &head);
    SingleListTraversal(head);

    std::cout << "\nTesting of sllGeneralInsert\n";
    sllGeneralInsert('X', head->next->next);
    SingleListTraversal(head);

    std::cout << "\nTesting of sllInsertEnd\n";
    sllInsertEnd('W', &head);
    SingleListTraversal(head);

    std::cout << "\nTesting deleting node\n";
    sllDeleteNode('Q', &head);
    SingleListTraversal(head);
    std::cout << std::endl;
    sllDeleteNode('X', &head);
    SingleListTraversal(head);
    std::cout << std::endl;
    sllDeleteNode('W', &head);
    SingleListTraversal(head); 
    std::cout << std::endl;

    std::cout << "Deleting list\n";
    sllDeleteList(&head);
    SingleListTraversal(head);

    return 0;
}
