#include<stdio.h>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

struct Count{
    int swapCount=0;
    int loopCount=0;
    int compareCount=0;
}S,B,I;

void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n){
	int i, j, min_idx;

	for (i = 0; i < n-1; i++){
		min_idx = i;
		for (j = i+1; j < n; j++){
            if (arr[j] < arr[min_idx])
                {min_idx = j;S.compareCount+=1;}
            S.loopCount+=1;
        }
		swap(&arr[min_idx], &arr[i]);
        S.swapCount+=1;
	}
}
void bubbleSort(int arr[], int n){
    int i, j;
    for (i = 0; i < n-1; i++){    
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1])
                {swap(&arr[j], &arr[j+1]);B.swapCount+=1;B.compareCount+=1;}
            B.loopCount+=1;
        }
    }
}

void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
            I.loopCount+=1;
        }
        arr[j + 1] = key;
    }
}
 
void printArray(int arr[], int size,Count X){
	int i;
	for (i=0; i < size; i++)
		cout << arr[i] << " ";
	cout<<"\t "<<X.loopCount<<" "<<X.swapCount<<" "<<X.compareCount<<endl;

}

int main(){
	int arr1[] = {64, 25, 12, 22, 11};
	int arr2[] = {64, 25, 12, 22, 11};
	int arr3[] = {64, 25, 12, 22, 11};
	int n = sizeof(arr1)/sizeof(arr1[0]);
	selectionSort(arr1, n);
	bubbleSort(arr2, n);
	insertionSort(arr3, n);
	cout << "Sorted array: \n";
	printArray(arr1, n,S);
	printArray(arr2, n,B);
	printArray(arr3, n,I);
	return 0;
}