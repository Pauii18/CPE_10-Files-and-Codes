#ifndef QUEUEARR_H
#define QUEUEARR_H

#include <iostream>

//array-based circular queue
template <typename T>
class queueArr{
	private:
		//pointer to dynamically allocate the array
		T*q_array;
		
		//maximum number of elements of queue can hold
		size_t q_capacity;
		
		// current number of the elements in the wueue
		size_t q_size;
		
		//index of the front element 
		int q_front;
		
		// indec of the back element
		int q_back;
		
	public:
		
		//constructor
		queueArr(size_t capacity = 10);
		
		//copy constructor
		queueArr(const queueArr& other);
		
		//copy assignment operator
		queueArr& operator=(const queueArr& other);
		
		//destructor
		~queueArr();
		
		//queue opereations
		bool Empty();
		bool Full();
		
		size_t Size();
		
		void Clear();
		
		T Front();
		
		T Back();
		
		void Enqueue(T value);
		
		T Dequeue();
};

//constructor
template <typename T>
queueArr<T>::queueArr(size_t capacity) {
    q_capacity = capacity;
    q_size = 0;
    q_front = 0;  
    q_back = -1;   
    q_array = new T[q_capacity]; 
}

		
		
//copy constructor
template <typename T>
queueArr<T>::queueArr(const queueArr& other) {
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;
    
    // Allocate brand new array memory
    q_array = new T[q_capacity];
    
    // Perform a deep copy of elements
    for (size_t i = 0; i < q_capacity; i++) {
        q_array[i] = other.q_array[i];
    }
}		
		
//copy assignment operator
template <typename T>
queueArr<T>& queueArr<T>::operator=(const queueArr& other) {
    // 1. Guard against self-assignment (e.g., q1 = q1)
    if (this != &other) {
        // 2. Free current existing memory
        delete[] q_array;

        // 3. Copy scalar values
        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;

        // 4. Allocate and copy array elements
        q_array = new T[q_capacity];
        for (size_t i = 0; i < q_capacity; i++) {
            q_array[i] = other.q_array[i];
        }
    }
    return *this; // Return reference to self
}

		//destructor
template <typename T>
queueArr<T>::~queueArr() {
    delete[] q_array; // Free dynamic memory allocation
}		
		
		//queue opereations

//empty()
template<typename T>
bool queueArr<T>::Empty(){
	//check if the size is 0
	return q_size == 0 ;
}

//Full()
template<typename T>
bool queueArr<T>::Full(){
	//check if the q_size reached the maximum capacity
	return q_size == q_capacity;
}


//sizeT
template <typename T>
size_t queueArr<T>::Size(){ //identifier"size_t" is undefined
	return q_size;
}

//clear;
template<typename T>
T queueArr<T>::Front(){
	// check if the queue is empty
	if(Empty()){
		std::cout<<"Queue is Empty\n";
		return T{};
	}
	
	//return the front
	return q_array[q_front];
	
	
}

//back
template <typename T>
T queueArr<T>::Back(){
	//check if the queue is empty
	if(Empty()){
		std::cout<<"queue is empty" <<std::endl;
		return T{};
	}
	
	return q_array[q_back];
}

template<typename T>
void queueArr<T>::Clear(){
	
	//rest the q_size, q_frint, q_back
	q_size = 0;
	q_front = 0;
	q_back = -1;
	
	
}
template <typename T>
void queueArr<T>::Enqueue(T value) {
    // check if the queue is Full
    if (Full()) {
        std::cout << "Queue is Full\n";
        return;
    }

    // if inserting the very first element, set q_front to 0
    if (Empty()) {
        q_front = 0;
    }

    // move q_back circularly
    q_back = (q_back + 1) % q_capacity;

    // store the value to the back
    q_array[q_back] = value;

    // increment the q_size
    q_size++;
}

//T dequeue();
template<typename T>
T queueArr<T>::Dequeue(){
	// check if ifempty
	if (Empty()) {
        std::cout << "Queue is Empty\n";
        return T{};
	}
	
	//create a templorary variable to store the current front
	T temp = q_array[q_front];
	
	//move q_frint circularly
	q_front = (q_front + 1) % q_capacity;
	
	//decrement the q_size
	q_size--;
	
	//reset the indexes of the queue become empty
	if(Empty()) Clear();
	
	
	//return the temporary variable
	return temp;

}

#endif //QUEUEARR_H
