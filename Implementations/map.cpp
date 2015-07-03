#include <functional>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int MAXN = 1000000;
int a [MAXN + 5];
int N;
std::map <int, int> m;

int main () {
    N = 0;
	while(scanf("%d", &a[N]) == 1) N++;

    for (int i = 0; i < N; ++i) {;
        m[a[i]]++;
    }
}
