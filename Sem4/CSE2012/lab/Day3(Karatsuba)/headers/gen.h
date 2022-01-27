#include <iostream>
#include <time.h>
using namespace std;

long long genRand(long long size){
    srand(time(0));
    return 9223372036854775807%size;
}

// long long => 9,223,372,036,854,775,807