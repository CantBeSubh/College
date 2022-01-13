#include <iostream>
using namespace std;
int COUNT=0;

void merge(int arr[], int const l, int const m, int const r){
	auto const sub1 = m - l + 1;
	auto const sub2 = r - m;

	auto *lArr = new int[sub1],
		*rArr = new int[sub2];

	for (auto i = 0; i < sub1; i++)
		lArr[i] = arr[l + i];
	for (auto j = 0; j < sub2; j++)
		rArr[j] = arr[m + 1 + j];

	auto indexOfSub1 = 0, 
		indexOfSub2 = 0; 
	int indexOfMergedarr = l; 

	while (indexOfSub1 < sub1 && indexOfSub2 < sub2) {
		if (lArr[indexOfSub1] <= rArr[indexOfSub2]) {
			COUNT+=1;
			arr[indexOfMergedarr] = lArr[indexOfSub1];
			indexOfSub1++;
		}
		else {
			COUNT+=1;
			arr[indexOfMergedarr] = rArr[indexOfSub2];
			indexOfSub2++;
		}
		indexOfMergedarr++;
	}

	while (indexOfSub1 < sub1) {
		arr[indexOfMergedarr] = lArr[indexOfSub1];
		indexOfSub1++;
		indexOfMergedarr++;
	}

	while (indexOfSub2 < sub2) {
		arr[indexOfMergedarr] = rArr[indexOfSub2];
		indexOfSub2++;
		indexOfMergedarr++;
	}
}

void mergeSort(int arr[], int const begin, int const end){
	if (begin >= end)
		return; 

	auto m = begin + (end - begin) / 2;
	mergeSort(arr, begin, m);
	mergeSort(arr, m + 1, end);
	merge(arr, begin, m, end);
}

void printArray(int A[], int size){
	cout << A[0] << " | " << A[1] << " ... " << A[size-2] << " | " << A[size-1];
}

void printCount(){
	cout<<"[!]Comparision count: "<<COUNT;
	COUNT=0;
}