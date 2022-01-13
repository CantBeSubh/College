#include "headers/app.h"

int main(){
    char testMode;
    
    cout<<"Enter Mode (`T` => TEST MODE | `any char` for NORMAL MODE): ";
    cin>>testMode;
    app(testMode);
    return 0;
}