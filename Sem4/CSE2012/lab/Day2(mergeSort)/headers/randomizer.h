#include <iostream>
#include <time.h>

using namespace std;

int* genRand(int arr_size,int elem_size=2147483647){
    srand(time(0));
    auto arr= new int[arr_size];
    for (int i = 0; i < arr_size; i++)
        arr[i]=rand()%elem_size;
    return arr;
}

int** gen2D(int arr_size,int elem_size=2147483647){
    srand(time(0));
    int **arr= new int*[arr_size];
    for(int i=0;i<2;i++){
        arr[i]=new int[2];
    }

    for (int i = 0; i < arr_size; i++){
        for(int j=0;j<2;j++)
            arr[i][j]=rand()%elem_size;
    }
    return arr;
}