#include"./header/genrator.h"
using namespace std;

void print(int **arr,int rSize,int cSize){
    for(int i=0;i<rSize;i++){
        for(int j=0;j<cSize;j++){
            cout<<arr[i * cSize + j];
        }
        cout<<endl;
    }
}

int multiply(int **a,int **b,int arSize,int acSize,int bcSize){
    int res=0;
    for(int i=0;i<arSize;i++){
        for(int j=0;j<bcSize;j++){
            for(int k=0;k<acSize;k++)
                res+=a[i][k]*b[k][j];
        }
    }
    return res;
}

int main(){
    int arSize,acSize,brSize,bcSize;
    cin>>arSize;
    cin>>acSize;
    cin>>brSize;
    cin>>bcSize;
    int *arr=new int[arSize*acSize];
    return 0;
}