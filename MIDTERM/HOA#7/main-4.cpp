#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int max_size =100;

void displayArr(int arr[]);


int main() { 

    // Create an array with unsorted list with 100 maximum size
    int unsorted_arr[max_size] = {};

    // Use time (0) as seed for random values
    std::srand(std::time(0));

    // Populate the array
    for (int i = 0; i < max_size; i++) {
        unsorted_arr[i] = std::rand() % 100; 
    }

    // Display the unsorted array
    std::cout << "Unsorted array: " << std::endl;
    displayArr(unsorted_arr);

    // Sort the array using bubble sort
    std::cout << "Bubble Sort: " << std::endl;
    bubbleSort(unsorted_arr, max_size);
    displayArr(unsorted_arr);

    // Sort the array using selection sort
    std::cout << "Selection Sort: " << std::endl;
    selectionSort(unsorted_arr, max_size);
    displayArr(unsorted_arr);

    // Sort the array using insertion sort
    std::cout << "Insertion Sort: " << std::endl;
    insertionSort(unsorted_arr, max_size);
    displayArr(unsorted_arr);
}


void displayArr(int arr[]) {
    for (int i = 0; i < max_size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}