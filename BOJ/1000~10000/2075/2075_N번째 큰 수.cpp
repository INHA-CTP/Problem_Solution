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
#define ll long long
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define PI 3.14159265
using namespace std;
const int MAX = 1e5 + 10;
const ll MOD = 1e9 + 7;
int N, M, K, Q;

int main()
{
	int i, j, k, x;
	scanf("%d", &N);
	priority_queue<int> pq;
	for (i = 1; i <= N*N; ++i) {
		scanf("%d", &x);
		pq.push(-x);
		if (pq.size() > N) pq.pop();
	}
	printf("%d", -pq.top());
}