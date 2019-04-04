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
#define ll long long
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
using namespace std;
const int MAX = 1e5 + 10;
const int MOD = 1e9 + 7;
int N, M, K, Q;
string S[] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };
map<string, pair<int, ll>> mp;

int main()
{
	int i, j, k;
	ll tens = 1LL;
	for (i = 0; i < 10; ++i) {
		mp[S[i]] = { i, tens};
		tens *= 10LL;
	}
	
	string s, t, r;
	cin >> s >> t >> r;
	ll num = mp[s].first * 10LL + mp[t].first;
	num *= mp[r].second;
	printf("%lld", num);
}