#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

template <typename T>
class DoubleList{
    public:
        T data;
        DoubleList<T>* prev = nullptr;
        DoubleList<T>* next = nullptr;
};

//creating a node:
template <typename T>
DoubleList<T> *CreateNewNode(T newData){
    //dynamically allocate a new memory for the code
    DoubleList<T> *newNode = new DoubleList<T>;


    //store the data in the node
    newNode->data = newData;

    //point next and prev to null
    newNode->next = nullptr;
    newNode->prev = nullptr;
    //return the address of the newly created node
    return newNode;

}

template <typename T>
void dllTraverse(DoubleList<T>* currentNode){

    //temp variable to store the lat node visited
    DoubleList<T> *tail;

    //check if the list is empty
    if(currentNode == nullptr){
        std::cout<<"The list is empty" <<std::endl;
        return;
    }
    
    //move forward
    std::cout << "Forward: \n";
    while(currentNode != nullptr){
        std::cout << currentNode->data << " ";
        tail = currentNode;
        currentNode = currentNode->next;
    }

    //add a next line 
    std::cout << std::endl;

    //move backward
    std::cout << "Backward: \n";

    while(tail != nullptr){
        std::cout<< tail->data<<" ";
        tail = tail->prev;
    }
    std::cout<<std::endl;

}



//inserting at the head of the list
template <typename T>
void dllInsertHead(T newData, DoubleList<T> ** currentHead){
    // creating a new mode
    DoubleList<T>* newNode = CreateNewNode(newData);
     
    //new node should point to the current head
    newNode->next = *currentHead;

    //current Head should point back to the newNode
    (*currentHead)->prev = newNode;

    //update the pointer head
    *currentHead = newNode;
}

template <typename T>

void dllInsertEnd(T newData, DoubleList<T> * currentHead){
    //create a new node
    DoubleList<T>* newNode = CreateNewNode(newData);

    //traverse until we reach the last node
    while(currentHead->next != nullptr){
        currentHead = currentHead->next;
    }

    //connect the last node to the new node
    currentHead->next = newNode;

    //connect the new node back to last node
    newNode->prev = currentHead;

}

//general insert
template <typename T>
void dllGeneralInsert(T newData, DoubleList<T>* prevNode){
    if(prevNode == nullptr){
        std::cout<<"Previous value cannot be null" <<std::endl;
        return;
    }
    DoubleList<T>* newNode = new DoubleList<T>;
    newNode->data = newData;
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
	newNode->next->prev = newNode;	
    prevNode->next = newNode;
	

}


//delete a node
template <typename T>
void dllDeleteList(T findData, DoubleList<T> ** head){
    if (*head== nullptr) return;
    DoubleList<T>* currentNode = *head;
    DoubleList<T>* prev = nullptr;

    while (currentNode != nullptr && currentNode->data != findData){
        prev = currentNode;
        currentNode = currentNode->next;
    }

    if(currentNode == nullptr) {
        return;
    }
	
	if(currentNode == *head){
		*head = currentNode -> next;
		if (*head != nullptr){
			(*head)->prev = nullptr;
		}
	}
	
	else{
        prev->next = currentNode->next;
    
		if (currentNode->next != nullptr){
			currentNode->next->prev = prev;
		}
	}
    delete currentNode;
}
#endif
