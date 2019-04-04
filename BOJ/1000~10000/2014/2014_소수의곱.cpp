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
using namespace std;
const int MAX = 1e5 + 10;
const int MOD = 1e9 + 7;
int N, M, K, Q;
priority_queue<ll> pq;
int primes[110];

int main()
{
	int i, j, k;
	scanf("%d%d", &K, &N);
	for (i = 0; i < K; ++i) {
		scanf("%d", &primes[i]);
		pq.push(-primes[i]);
	}
	int cnt = 0;
	ll x;
	while (1) {
		x = -pq.top();
		for (i = 0; i < K; ++i) {
			pq.push(-x * (ll)primes[i]);
			if (x%primes[i] == 0) break;
		}
		pq.pop();
		cnt++;
		if (cnt == N) break;
	}
	printf("%d", x);
}