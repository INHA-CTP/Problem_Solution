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
map<ll, int> mp;

int main()
{
	int i, j;
	ll x;
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%lld", &x);
		mp[x]++;
	}
	int maxi = 0;
	ll ans;
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		if (it->second > maxi) {
			ans = it->first;
			maxi = it->second;
		}
	}
	printf("%lld", ans);
}