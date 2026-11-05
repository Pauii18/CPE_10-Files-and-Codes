#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "sortingAlgo.h"

const int max_size =101;

void displayArr(int arr[], int size);
void winnerVotes(int arr[], int size);


int main() { 

    // Create an array with unsorted list with 101 maximum size
    int unsorted_arr[max_size] = {};

    // Use time (0) as seed for random values
    std::srand(std::time(0));

    // Populate the array
    for (int i = 0; i < max_size; i++) {
        unsorted_arr[i] = (std::rand() % 5) + 1; 
    }

    // Display the unsorted array
    std::cout << "Unsorted array: " << std::endl;
    displayArr(unsorted_arr, max_size);
    std::cout << std::endl;
    
    std::cout << "Sorted Array using Insertion Sort: " << std::endl;
    insertionSort_two(unsorted_arr, max_size);
    displayArr(unsorted_arr, max_size);
    std::cout << std::endl;

    // Sort the array using bubble sort
    std::cout << "Election Results: " << std::endl;
    winnerVotes(unsorted_arr, max_size);
	std::cout << std::endl;
    
    
    
}


void displayArr(int arr[], int size) {
    for (int i = 0; i < max_size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void winnerVotes(int arr[], int size){
	std::string candidates[5] = {
		"Bo Dalton Capistrano",
        "Cornelius Raymon Agustin",
        "Deja Jayla Banaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
	};
	
	int vote_counts[5] = {0,0,0,0,0};
	
	for (int i = 0; i < size; i++){
		int vote = arr[i];
		if(vote >= 1 && vote <= 5){
			vote_counts[vote - 1]++;
		}
	}
	
	int max_votes = -1;
	int winner = 0;
	bool tie = false;
	
	for(int i = 0; i <5; i++){
		std::cout << "Candidate " << (i + 1) << ":" << candidates[i] << " with " <<
					vote_counts[i] << " votes" << std::endl;
	
		if(vote_counts[i] > max_votes){
			max_votes = vote_counts[i];
			winner = i;
			tie = false;
		}else if(vote_counts[i] == max_votes){
			tie = true;
		}
	}
	
	std::cout << std::endl;
	if(tie){
		std::cout << "The election is a TIE!" << std::endl;
	}else{
		std::cout << "The winner of this election is " << candidates[winner] 
				<< "!!!!" <<  " with the total votes of " << max_votes << "!" 
				<< std::endl;
	}
}
