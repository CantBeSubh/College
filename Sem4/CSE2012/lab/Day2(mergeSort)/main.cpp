#include "headers/app.h"

int main(){
    char test_mode;
    cout<<"Enter Mode (`T` => TEST MODE | `any char` for NORMAL MODE): ";
    cin>>test_mode;
    app(test_mode);
    return 0;
}