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

        int testArrSize[10]={10,50,250,1000,5000,10000,50000,100000,500000,1000000};

        for(int a=0;a<10;a++){
            clock_t begin=clock();

            int *arr = genRand(testArrSize[a]); 
            cout << "[+]Given array(SIZE="<<testArrSize[a]<<"): ";
            printArray(arr,testArrSize[a]);
            cout<<endl<<"[*]Sorting...";
            mergeSort(arr, 0,testArrSize[a] - 1);
            cout << endl<<"[+]Sorted array: ";
            printArray(arr,testArrSize[a]);

            clock_t end=clock();

            double time_spent=(double)(end-begin);
            begin=0;end=0;
            cout<<endl<<endl<<"[!]Time spent(ms): "<<time_spent<<endl;
            printCount();
            cout<<endl<<endl;
            cout<<"----------------------"<<endl<<endl;
        }
        cout<<"Press any key to exit..."<<endl;
        getch();
        return;
    }
    else{
        cout<<"[?]Enter Array Size: ";
        cin>>arrSize;
        cout<<"[?]Enter Ellement Size: ";
        cin>>elemSize;

        clock_t begin=clock();

        int *arr = genRand(arrSize,elemSize); 
        cout << "[+]Given array: ";
        printArray(arr,arrSize);
        cout<<endl<<"[*]Sorting...";
        mergeSort(arr, 0,arrSize - 1);
        cout<<endl<<"Sorted array: ";
        printArray(arr,arrSize);
        
        clock_t end=clock();

        double time_spent=(double)(end-begin);
        cout<<endl<<endl<<"[!]Time spent(ms): "<<time_spent<<endl;
        printCount();
        cout<<endl<<endl;
        cout<<"----------------------"<<endl<<endl;
        cout<<"Press any key to exit..."<<endl;
        getch();
        return;
    }
}
