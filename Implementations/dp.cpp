#include <iostream>
#include <string>
using namespace std;

const int MAXN = 1000000;
int a [MAXN + 5];
int c [MAXN + 5];
int N;

int main () {
    N = 0;
	while(scanf("%d", &a[N]) == 1) N++;
	
	// Count the number of instructions in the algorithm
	long long num_inst = 0;

    for (int i = N - 1; i >= 0; --i) {
        int j = i + 1;
        while (j < N) {
			num_inst++;
            if (a[i] == a[j]) {
                c[i] = c[j] + 1;
                break;
            }
            ++j;
        }

        if (j == N) {
            c[i] = 1;
        }
    }
	printf("%lld\n", num_inst);
}
