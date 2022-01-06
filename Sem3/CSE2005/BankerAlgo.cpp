#include <iostream>
using namespace std;

int main(){
int n, m, i, j, k;
n = 4; 
m = 4; 
int alloc[4][4] = { {2,0,1,1}, 
					{1,1,0,0}, 
					{1,0,1,0}, 
					{0,1,0,1}};

int max[4][4] = {{3,2,1,1}, 
				{1,2,0,2}, 
				{3,2,1,0}, 
				{2,1,0,1}}; 

int avail[4] = {6,4,4,2};

int f[n], ans[n], ind = 0;
for (k = 0; k < n; k++) {
	f[k] = 0;
}
int need[n][m];
for (i = 0; i < n; i++) {
	for (j = 0; j < m; j++)
	need[i][j] = max[i][j] - alloc[i][j];
}
int y = 0;
for (k = 0; k < 5; k++) {
	for (i = 0; i < n; i++) {
	if (f[i] == 0){
		int flag = 0;
		for (j = 0; j < m; j++) {
		if (need[i][j] > avail[j]){
			flag = 1;
			break;
		}
		}
		if (flag == 0){
		ans[ind++] = i;
		for (y = 0; y < m; y++)
			avail[y] += alloc[i][y];
		f[i] = 1;
		}
	}
	}
}

cout << "Sequence :" << endl;
for (i = 0; i < n - 1; i++)
	cout << " P" << ans[i] << " ->";
cout << " P" << ans[n - 1] <<endl;

	return (0);
}