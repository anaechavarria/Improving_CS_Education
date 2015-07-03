#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

const int MAXN = 10e6 + 5;
int a[MAXN];
vector<int> counter;

int main(){
	int n = 0;
	while(scanf("%d ", &a[n]) > 0) n++;
	
	if (n == 0) return 0;
	
	int maximum = a[0];
	int minimum = a[0];
	for (int i = 1; i < n; ++i){
		maximum = max(maximum, a[i]);
		minimum = min(minimum, a[i]);
	}
	assert(minimum >= 0);
	
	// Initialized with zeroes
	counter.resize(maximum + 1);
	
	for (int i = 0; i < n; ++i){
		counter[a[i]]++;
	}
	
	return 0;
}
