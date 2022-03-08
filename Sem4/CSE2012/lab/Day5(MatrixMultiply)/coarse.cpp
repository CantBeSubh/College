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
  
void matrix_multiply(int** A,int r1,int c1,int** B,int r2,int c2,int**C,int coarse){
    static int i =0, j =0, k =0;
    if(i >= r1){return;}
    else if(i < r1){
        if(j < c2){
            if(k < c1){
                for(int x =0; x < coarse; x++){
                    C[i][j + x]+= A[i][k]* B[k][j + x];
                }
                k++;
                matrix_multiply(A,r1,c1,B,r2,c2,C,coarse);
            }
            k =0;
            j+=coarse;
            matrix_multiply(A,r1,c1,B,r2,c2,C,coarse);
        }
        j =0;
        i++;
        matrix_multiply(A,r1,c1,B,r2,c2,C,coarse);
    }
}


int main(){    
    int task = random(1,6);
    int n = task *4;
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
            A[i][j]= random(1,20);            
            B[i][j]= random(1,20);            
            result[i][j]=0;
        }
    }    
    cout <<"N : "<< n << endl;    
    cout <<"matrix A : "<< endl;    
    display(A,n);    
    cout <<"matrix B : "<< endl;    
    display(B,n);    
    matrix_multiply(A,n,n,B,n,n,result,task);    
    cout <<"Result matrix : "<< endl;    
    display(result,n);return 0;
} 