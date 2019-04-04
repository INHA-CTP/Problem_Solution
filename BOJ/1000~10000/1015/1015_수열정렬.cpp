#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <cmath>
#include <time.h>
#include <unordered_map>
#define ll long long
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define PI 3.14159265
#define RAND (rand()*rand())
using namespace std;
const int MAX = 1e5 + 10; //N
const ll MOD = 1e9 + 7;
int N, M, K, Q;
int ans[55];

int main()
{
	int i, j, x;
	scanf("%d", &N);
	priority_queue<pair<int, int>> pq;
	for (i = 0; i < N; ++i) {
		scanf("%d", &x);
		pq.push({ -x, -i });
	}

	for (i = 0; i < N; ++i) {
		x = -pq.top().first;
		int idx = -pq.top().second;
		ans[idx] = i;
		pq.pop();
	}
	for (i = 0; i < N; ++i) printf("%d ", ans[i]);
}