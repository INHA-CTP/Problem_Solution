/*
	Author : Hak kyu, Kim
	Date : 19.04.02
*/

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
#define ll long long
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define PI 3.14159265
#define RAND (rand()*rand())
using namespace std;
const int MAX = 1e5 + 10; //N
const ll MOD = 1e9 + 7;
int N, M, K, Q;
map<string, int> mp;

int main()
{
	int i, j, T;
	scanf("%d", &T);
	string s, t;
	while (T--) {
		mp.clear();
		scanf("%d", &N);
		for (i = 0; i < N; ++i) {
			cin >> s >> t;
			mp[t]++;
		}
		ll cnt = 1LL;
		for (auto it = mp.begin(); it != mp.end(); ++it) {
			cnt *= (ll)(it->second + 1);
		}
		cnt--;
		printf("%lld\n", cnt);
	}
	
}