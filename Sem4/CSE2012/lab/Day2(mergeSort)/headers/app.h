#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include "randomizer.h"
#include "mergeSort.h"
using namespace std;

void app(char T){

    int arrSize,elemSize;

    if(T == 'T'){

        int testArrSize[4]={10,50,250,1000};

        for(int a=0;a<4;a++){
            clock_t begin=clock();

            int *arr = genRand(testArrSize[a]); 
            cout << "Given array(size="<<testArrSize[a]<<")\n";
            printArray(arr,testArrSize[a]);
            mergeSort(arr, 0,testArrSize[a] - 1);
            cout << "\nSorted array \n";
            printArray(arr,testArrSize[a]);

            clock_t end=clock();

            double time_spent=(double)(end-begin);
            cout<<endl<<"Time spent(ms): "<<time_spent<<endl;
            cout<<"Press any key to continue..."<<endl;
            getch();
        }
        return;
    }
    else{
        cout<<"Enter Array Size: ";
        cin>>arrSize;
        cout<<"Enter Ellement Size: ";
        cin>>elemSize;

        clock_t begin=clock();

        int *arr = genRand(arrSize,elemSize); 
        cout << "Given array is \n";
        printArray(arr,arrSize);
        mergeSort(arr, 0,arrSize - 1);
        cout << "\nSorted array is \n";
        printArray(arr,arrSize);
        
        clock_t end=clock();

        double time_spent=(double)(end-begin);
        cout<<endl<<"Time spent(ms): "<<time_spent<<endl;
        cout<<"Press any key to exit..."<<endl;
        getch();
        return;
    }
}
