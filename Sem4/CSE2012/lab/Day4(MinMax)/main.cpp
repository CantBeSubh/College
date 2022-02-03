#include<iostream>
#include<conio.h>
#include <time.h>

using namespace std;

int MIN;
int MAX;
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
    long long int n;
    char M;
    cout<<"[?]ENTER MODE: ";
    cin>>M;
    
    if(M=='T'){
        long long int testSize[10]={10,50,100,500,1000,10000,50000,100000,500000,1000000};
        for(int i=0;i<10;i++){
            n=testSize[i];
            srand(time(0));
            for(int i=0;i<n;i++)
                arr[i]=rand()%elem_size+1;
            cout<<endl<<"[*]"<<n;
            MAX=arr[0];
            MIN=arr[0];
            clock_t begin=clock();
            MinMax(0,n);
            clock_t end=clock();
            float t=(float)(end-begin)/CLOCKS_PER_SEC;
            cout<<endl<<"[*]"<<MAX<<" | "<<MIN;
            cout<<endl<<"[!]TIME: "<<t;
            cout<<endl<<"--------------------";
        }
        return 0;
    }
    else{
        cout<<("[?]Enter size: ");
        cin>>n;
        srand(time(0));
        for(int i=0;i<n;i++){
            arr[i]=rand()%elem_size+1;
            cout<<arr[i]<<'\t';
        }
        cout<<"[*]"<<n<<endl;
        MAX=arr[0];
        MIN=arr[0];
        clock_t begin=clock();
        MinMax(0,n);
        clock_t end=clock();
        cout<<"[*]"<<endl<<MAX<<'\t'<<MIN;
        float t=(float)(end-begin)/CLOCKS_PER_SEC;
        cout<<endl<<"[!]TIME: "<<t;
        return 0;
    }
}