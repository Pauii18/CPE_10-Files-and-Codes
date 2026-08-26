#ifndef QUEUEARR_H 
#define QUEUEARR_H

#include <iostream>

template <typename T>
class queueArr{
    private:
        T*q_array;
        size_t q_capacity;
        size_t q_size;
        int q_front;
        int q_back;

    public:
        queueArr(size_t capacity = 10);
        ~queueArr();
        bool Empty();
        bool Full();
        bool Symmetric();
        size_t  Size();
        void Clear();
        T Front();
        T Back();
        void Enqueue (T value);
        T Dequeue ();
        

};

template (typename T)
queueArr<T> ::queueArr (size_t capacity) {
    q_capacity = capacity ;
    q_size = 0;
    q_front = 0;
    q_back = -1;
    q_array = new T[q_capacity];

}

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

template<typename T>
bool queueArr<T>::Symmetric(){
    // how to check symmetric of the whole line?
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