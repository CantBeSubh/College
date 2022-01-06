#include<stdio.h>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

struct Count{
    int swapCount=0;
    int loopCount=0;
    int compareCount=0;
}M,Q;

void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

//Inspired from GFG 
//MERGESORT

void merge(int array[], int const left, int const mid, int const right){
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
  
    int *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
  
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
  
    int indexOfSubArrayOne = 0, 
        indexOfSubArrayTwo = 0; 
    int indexOfMergedArray = left; 

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo){
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]){
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            M.compareCount++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            M.compareCount++;
        }
        indexOfMergedArray++;
        M.loopCount++;
    }
    while (indexOfSubArrayOne < subArrayOne){
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
        M.loopCount++;
    }
    while (indexOfSubArrayTwo < subArrayTwo){
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
        M.loopCount++;
    }
}

void mergeSort(int array[], int const begin, int const end){
    if (begin >= end)
        return; 
    int mid = begin + (end - begin) / 2;
    M.loopCount++;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

//QUICK SORT

int partition (int arr[], int low, int high){ 
    int pivot = arr[high];
    int i = (low - 1); 
    for (int j = low; j <= high - 1; j++){ 
        if (arr[j] < pivot){ 
            i++;
            swap(&arr[i], &arr[j]);
            Q.swapCount++;
            Q.compareCount++;
        }
        Q.loopCount++;
    } 
    swap(&arr[i + 1], &arr[high]);
    Q.swapCount++;
    return (i + 1); 
} 
  
void quickSort(int arr[], int low, int high){ 
    if (low < high){ 
        Q.loopCount++;
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
 

void printArray(int arr[], int size,Count X){
	int i;
	for (i=0; i < size; i++)
		cout << arr[i] << " ";
	cout<<"\tLoop "<<X.loopCount<<" Swap "<<X.swapCount<<" Compare "<<X.compareCount<<endl;
}

int main(){
	int arr1[] = {64, 25, 12, 22, 11};
	int arr2[] = {64, 25, 12, 22, 11};
	int n = sizeof(arr1)/sizeof(arr1[0]);
    printArray(arr1,n,M);
    printArray(arr2,n,Q);
	mergeSort(arr1, 0, n-1);
    quickSort(arr2,0,n-1);
	cout << "Sorted array: \n";
    cout<<"1. Merge Sort: ";	printArray(arr1, n,M);
    cout<<"2. Quick Sort: ";	printArray(arr2, n,Q);
	return 0;
}