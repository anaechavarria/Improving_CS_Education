#include <functional>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1000000;
int a [MAXN + 5];
int c [2 * MAXN + 5];
int w [MAXN + 5];
int N;

int main () {
    N = 0;
	while(scanf("%d", &a[N]) == 1) N++;
	
    sort(a, a+N);

    int cd = 0;
    int b = a[0];
    w[0] = a[0];
    for (int i = 0; i < N; ++i) {
        if (a[i] == b) {
            c[cd]++;
        } else {
            b = a[i];
            c[++cd]++;
            w[cd] = b;
        }
    }
}
