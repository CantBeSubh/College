#include <iostream>
#include <conio.h>
#include <time.h>
#include "randomizer.h"
#include "mergeSort.h"
using namespace std;

void app(char T='a'){

    int arr_size,elem_size;

    if(T=='T' || T=='t'){

        int test_arr_size[4]={10,50,250,1000};

        for(int a=0;a<4;a++){
            clock_t begin=clock();

            int *arr = genRand(test_arr_size[a]); 
            cout << "Given array(size="<<test_arr_size[a]<<")\n";
            printArray(arr,test_arr_size[a]);
            mergeSort(arr, 0,test_arr_size[a] - 1);
            cout << "\nSorted array \n";
            printArray(arr,test_arr_size[a]);

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
        cin>>arr_size;
        cout<<"Enter Ellement Size: ";
        cin>>elem_size;

        clock_t begin=clock();

        int *arr = genRand(arr_size,elem_size); 
        cout << "Given array is \n";
        printArray(arr,arr_size);
        mergeSort(arr, 0,arr_size - 1);
        cout << "\nSorted array is \n";
        printArray(arr,arr_size);
        
        clock_t end=clock();

        double time_spent=(double)(end-begin);
        cout<<endl<<"Time spent(ms): "<<time_spent<<endl;
        cout<<"Press any key to exit..."<<endl;
        getch();
        return;
    }
}
