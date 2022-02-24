#include<stdio.h>
int FID[5]={1001,1002,1003,1004,1005};

int main(){
    float ar[5]={1.35,2.25,9.0,10.45,11.0};
    char arT[5]={'a','a','a','p','p'};
    float dp[5]={3.25,5.40,11.30,2.0,5.50};
    char dpT[5]={'a','a','a','a','a'};
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if((dp[i] > ar[j]) && (dpT[i]==arT[j])){
                float diff= dp[i] - ar[j];
                if((diff>0.5 && diff<1.5) )
                    printf("(%d,%d) ",FID[i],FID[j]);    
            }else{
                if((dpT[i]!=arT[j])){
                    float a=(dp[i]>ar[j])?dp[i]:ar[j];
                    float b=(dp[i]<ar[j])?dp[i]:ar[j]; 
                    float res=(12 - a) + b;
                    if(res>0.5 && res<1.5)
                        printf("(%d,%d) ",FID[i],FID[j]);        
                }  
            }  
        } 
    }
    return 0;
}