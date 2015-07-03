#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


const int MAXN = 10e6 + 5;
int a[MAXN];
int counter[MAXN];

int main(){
	int n = 0;
	while(scanf("%d", &a[n]) == 1) n++;
	
	// Count the number of instructions. Should be n*n.
	long long num_inst = 0;
	
	for (int i = 0; i < n; ++i){
		int element = a[i];
		for (int j = 0; j < n; ++j){
			num_inst++;
			if (element == a[j]){
				counter[i]++;
			}
		}
	}
	
	printf("%lld\n", num_inst);
	
	return 0;
}
