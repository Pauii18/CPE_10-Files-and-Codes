#ifndef SOTRINGALGO_H
#define SOTRINGALGO_H
#include <iostream>

template<typename T>
void insertionSort_two(T arr[], size_t arrSize){
	for (int i = 1; i <arrSize; i++){
		int temp = arr[i];
		int j = i - 1;
		
		while(j >= 0 && arr[j] > temp){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}



#endif
