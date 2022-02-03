#include<iostream>
#include<conio.h>
#include <time.h>

using namespace std;

int MIN;
int MAX;
int COUNT=0;
long long int elem_size=2147483647;
long long int arr[1000000];

void MinMax(int i,int j){
    int max,min,mid;
    if(i==j){
        MAX=arr[i];
        MIN=arr[i];
    }else{
        if(i==j-1){
            if(arr[i]<arr[j]){
                MAX=arr[j];
                MIN=arr[i];
            }else{
                MAX=arr[i];
                MIN=arr[j];
            }
        }else{
            mid=(i+j)/2;
            MinMax(i,mid);
            max=MAX;
            min=MIN;
            MinMax(mid+1,j);
            if(MAX<max)
                MAX=max;
            if(MIN>min)
                MIN=min;
        }
    }
}

int main(){
    int n;
    char M;
    int std[10000][6];
    cout<<"[?]ENTER MODE: ";
    cin>>M;

    if(M=='T'){
        long long int testSize[8]={10,50,100,500,1000,10000};
        clock_t begin=clock();
        for(int i=0;i<6;i++){
            n=testSize[i];
            srand(time(0));
            for(int j=0;j<n;j++){
                std[j][0]=rand()%99+202000;
                for(int k=1;k<6;k++){
                    std[j][k]=rand()%99+1;
                }
            }

            for(int j=1;j<6;j++){
                for(int k=0;k<n;k++)
                    arr[k+1]=std[k][j];
                MAX=arr[0];
                MIN=arr[0];
                MinMax(1,n);
                for(int k=0;k<n;k++){
                    if(std[k][j]==MAX){
                        COUNT++;
                    }
                    if(std[k][j]==MIN){
                        COUNT++;
                    }
                }
            }
            clock_t end=clock();
            float t=(float)(end-begin)/CLOCKS_PER_SEC;
            cout<<COUNT;
            cout<<endl<<"[!]TIME: "<<t;
            cout<<endl<<"----------------------"<<endl;
        }
    }else{
        cout<<"[?]ENTER SIZE: ";
        cin>>n;
        clock_t begin=clock();
        for(int j=0;j<n;j++){
            std[j][0]=rand()%99+202000;
            cout<<endl<<std[j][0]<<"\t";
            for(int k=1;k<6;k++){
                std[j][k]=rand()%99+1;
                cout<<std[j][k]<<"\t";
            }
        }

        for(int j=1;j<6;j++){
            for(int k=0;k<n;k++)
                arr[k+1]=std[k][j];
            MAX=arr[0];
            MIN=arr[0];
            MinMax(1,n);
            for(int k=0;k<n;k++){
                if(std[k][j]==MAX){
                    cout<<endl<<"[+]ROLL NO: "<<std[k][0]<<" SCORED MAX "<<MAX<<" IN SUBJECT "<<j;
                }
                if(std[k][j]==MIN){
                    cout<<endl<<"[+]ROLL NO: "<<std[k][0]<<" SCORED MIN "<<MIN<<" IN SUBJECT "<<j;
                }
            }
            cout<<endl;
        }
        clock_t end=clock();
        float t=(float)(end-begin)/CLOCKS_PER_SEC;
        cout<<endl<<"[!]TIME: "<<t<<endl;
    }
    return 0;
}