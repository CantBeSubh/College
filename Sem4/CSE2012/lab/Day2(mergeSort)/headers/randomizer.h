#include <iostream>
#include <time.h>

using namespace std;

int* genRand(int arr_size,int elem_size=1000000){
    srand(time(0));
    auto arr= new int[arr_size];
    for (int i = 0; i < arr_size; i++){
        arr[i]=rand()%elem_size;
    }
    return arr;
}