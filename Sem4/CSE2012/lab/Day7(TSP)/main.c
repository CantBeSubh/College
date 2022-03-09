#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int visited[10],dist[10][10];

int cost=0;
void remvk(int N[], int len, int k){
    int j=0;
    for(int i=0;i<len;i++){
        if(N[i]!=k){
            N[j]=N[i];j=j+1;
        }
    }
}

int TSP(int N[], int len, int s){
    int i, j;
    visited[s-1]=1;if(len==2) {
        for(i=0;i<2;i++){
            if(N[i]!=s){
                cost=dist[s-1][i];
                break;
            }
        }
    }else{
        for(j=0;j<len;j++){
            for(i=0;i<len;i++){
                if(visited[i]==0){
                    if(j!=i && j!=s){
                        remvk(N, len, i+1); 
                        cost=TSP(N, len-1, j+1)+ dist[j][i];
                    }
                }
            }
        }
    }    
    return cost;
}

int main(){
    int n, i, j=0, k=0, s;
    printf("Number of cities:\n");
    scanf("%d", &n);
    int cities[n];
    int N[n-1];
    printf("The %d cities are:\n", n);
    for(i=0; i<n; i++){
        cities[i]= i+1;
        printf("%d ", cities[i]);
    }
    for(i=0; i<n; i++){
        for(j=0;j<n;j++){
            if(j!=i){
                printf("\n %d => %d: ", i+1, j+1);
                scanf("%d", &dist[i][k]);k=k+1;
            }
        }
        k=0;
    }
    j=0;
    memset(visited, 0, (n-1)*sizeof(int));
    printf("\nStarting point: ");
    scanf("%d", &s); 
    for(i=0; i<n; i++){
        if(cities[i]!=s){
            N[j]=cities[i];j++;
        }
    }
    printf("------------------\n cost: %d\n\n", TSP(cities, n, s));
    return 0;
}