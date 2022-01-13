#include "merge2d.h"
int main(){

    int**a=gen2D(10);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 10; j++) { 
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    sortX(a,10);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 10; j++) { 
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}