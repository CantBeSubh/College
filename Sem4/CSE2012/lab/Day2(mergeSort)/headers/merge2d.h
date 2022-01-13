#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include "randomizer.h"
using namespace std;
int COUNT=0;

void merge2d(int array[][], int const left, int const mid, int const right,int XorY){
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	int leftArray[subArrayOne][2];
	int	rightArray[subArrayTwo][2];


    
	for (int i = 0; i < subArrayOne; i++)
		leftArray[i][0] = array[left + i][0];
		leftArray[i][1] = array[left + i][1];

	for (int j = 0; j < subArrayTwo; j++)
		rightArray[j][0] = array[mid + 1 + j][0];
		rightArray[j][1] = array[mid + 1 + j][1];

	auto indexOfSubArrayOne = 0, 
		indexOfSubArrayTwo = 0; 
	int indexOfMergedArray = left; 

	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne][XorY] <= rightArray[indexOfSubArrayTwo][XorY]) {
			COUNT+=1;
			array[indexOfMergedArray][XorY] = leftArray[indexOfSubArrayOne][XorY];
			array[indexOfMergedArray][1-XorY] = leftArray[indexOfSubArrayOne][1-XorY];
			indexOfSubArrayOne++;
		}
		else {
			COUNT+=1;
			array[indexOfMergedArray][XorY] = rightArray[indexOfSubArrayTwo][XorY];
			array[indexOfMergedArray][1-XorY] = rightArray[indexOfSubArrayTwo][1-XorY];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray][XorY] = leftArray[indexOfSubArrayOne][XorY];
		array[indexOfMergedArray][1-XorY] = leftArray[indexOfSubArrayOne][1-XorY];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray][XorY] = rightArray[indexOfSubArrayTwo][XorY];
		array[indexOfMergedArray][1-XorY] = rightArray[indexOfSubArrayTwo][1-XorY];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}

void mergeSort2d(int array[][], int const begin, int const end,int XorY){
	if (begin >= end)
		return; 

	auto mid = begin + (end - begin) / 2;
	mergeSort2d(array, begin, mid,XorY);
	mergeSort2d(array, mid + 1, end,XorY);
	merge2d(array, begin, mid, end,XorY);
}

void printCount(){
	cout<<"[!]Comparision count: "<<COUNT;
	COUNT=0;
}

void sortX(int array[][],int size){
    mergeSort2d(array,0,size-1,0);
}

void sortY(int array[][],int size){
    mergeSort2d(array,0,size-1,1);
}