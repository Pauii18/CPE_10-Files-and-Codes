#include <iostream>
#include "singly_ll.h"
#include "doubly_ll.h"

void dllist();
void sllist();


int main () {
	sllist();
	dllist();
	return 0;
}

void sllist()
{
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

}

void dllist(){

    //create a list 'C P E'
    DoubleList<char>* head = CreateNewNode('C');
    DoubleList<char>* second = CreateNewNode('P');
    DoubleList<char>* third = CreateNewNode('E');

    head->next = second;
    second->prev = head;
    
    second->next = third;
    third->prev = second;


    //traversal
    std::cout << "\n\nTesting the DLL Traversal" << std::endl;
    dllTraverse(head);

    //teasting the inser at the head
    std::cout << "Testing the insertion at the head node" <<std::endl;
    dllInsertHead('X' , &head);
    dllTraverse(head);

    //testing the insert at the end
    std::cout<<"Testing the insertion at the end" << std::endl;
    dllInsertEnd('0', head);
    dllTraverse(head);

    //testing general insert
    std::cout<<"Testing general insert" <<std::endl;
    dllGeneralInsert('B', head);
    dllTraverse(head);
    
    std::cout<<"Testing Delete Node"  <<std::endl;
    dllDeleteList('X', &head);
    dllTraverse(head);

}
