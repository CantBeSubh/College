#include <iostream> 
#include <time.h> 
using namespace std;
int random(int min,int max){
    static bool first =true;
    if(first){      
        srand(time(NULL));      
        first =false;
    }
    return min + rand()%(( max +1)- min);
}
    
void display(int** matrix,int n){
    for(int i =0; i < n; i++){
        for(int j =0; j < n; j++){
            cout << matrix[i][j]<<" ";
        }        
        cout << endl;
    }    
    cout << endl;
}
  
void matrix_multiply(int** A,int r1,int c1,int** B,int r2,int c2,int**C){
    static int i =0, j =0, k =0;
    if(i >= r1){
        return;
    }else if(i < r1){
        if(j < c2){
            if(k < c1){
                C[i][j]+= A[i][k]* B[k][j];                
                k++;                
                matrix_multiply(A,r1,c1,B,r2,c2,C);
            }            
            k =0;            
            j++;            
            matrix_multiply(A,r1,c1,B,r2,c2,C);
        }        
        j =0;        
        i++;        
        matrix_multiply(A,r1,c1,B,r2,c2,C);
    }
}


int main(){    
    int n =4;
    int** A;
    int** B;
    int** result;    
    A =new int*[n];
    B =new int*[n]; 
    result =new int*[n];
    for(int i =0; i < n; i++){        
        A[i]=new int[n];        
        B[i]=new int[n];        
        result[i]=new int[n];
    }
    for(int i =0; i < n; i++){
        for(int j =0; j < n; j++){            
            A[i][j]= random(1,10);            
            B[i][j]= random(1,10);            
            result[i][j]=0;
        }
    }    
    cout <<"N : "<< n << endl;
    cout <<"matrix A : "<< endl;    
    display(A,n);   
    cout <<"matrix B : "<< endl;    
    display(B,n);clock_t begin = clock();    
    matrix_multiply(A,n,n,B,n,n,result);
    clock_t end = clock();
    double time_spent =(double)(end - begin)/ CLOCKS_PER_SEC;    
    cout <<"Result matrix : "<< endl;   
    display(result,n);    
    cout <<"Take Taken : "<< time_spent << endl;
    return 0;
}