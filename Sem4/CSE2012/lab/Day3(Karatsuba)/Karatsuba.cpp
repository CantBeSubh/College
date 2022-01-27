#include "headers/Karatsuba.h"
#include <time.h>
using namespace std;

void testMode(){
	for(long long i=1;i<9223372036854775807;i*=10){
		time_t begin=time(NULL);
		long long a = genRand(i);
		long long b = genRand(i);
		cout<<a<<" * "<<b<<endl;
		cout << multiply(a,b) << endl;
		time_t end=time(NULL);
		double time_spent=difftime(end,begin);
		begin=0;end=0;
		cout<<"[!]Time spent(ms): "<<time_spent<<endl<<endl;
	}
}

int main() {
	testMode();
	return 0;
}
