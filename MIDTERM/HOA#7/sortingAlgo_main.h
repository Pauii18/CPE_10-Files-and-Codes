#ifndef SOTRINGALGO_H
#define SOTRINGALGO_H
#include <iostream>

template <typename T>
void bubbleSort(T arr[], size_t arrSize) {
    // Step 1: for i = 0 to N-1 repeat inner loop
    for (int i = 0; i < arrSize - 1; i++) {

        // Step 2: Inner loop that for K = i+1 to N-1 repeat
        for (int j = i+1; j < arrSize; j++) {

            // Step 3: Swap if arr[j] > arr[i]
            if (arr[i] > arr[j]) {
                // Swap arr[j] and arr[i]
                std::swap(arr[j], arr[i]);
            }
        }
    }
}


template <typename T>
// Array, current position, size of array
int routineSmallest(T arr[], int K, const int arrSize) {
    int position = K;
    T smallestElem = arr[K];

    for(int j = K+1; j < arrSize; j++){
        if(arr[j] < smallestElem){
            smallestElem = arr[j];
            position = j;
        }
    }
    return position;
}

template<typename T>
void selectionSort(T arr[], size_t arrSize){
    int POS, temp, pass;
    for(int i=0; i < arrSize; i++){
        POS = routineSmallest(arr, i, arrSize);
        // Swapping:
        temp = arr[i];

        arr[i] = arr[POS];
        arr[POS] = temp;

        // For verification and counting of number of passes that was done
        pass++;
    }
}

template<typename T>
void insertionSort(T arr[], size_t arrSize){
    int K = 1, J;
    T temp;

    while(K < arrSize){
        temp = arr[K];
        J = K - 1;

        while(J >= 0 && temp < arr[J]){
            arr[J+1] = arr[J];
            J--;
        }

        arr[J+1] = temp;
        K++;
    }
}



#endif
