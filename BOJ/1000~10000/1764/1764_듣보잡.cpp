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
set<string> st1, st2;

int main()
{
	int i, j, k;
	scanf("%d%d", &N, &M);
	string s;
	for (i = 0; i < N; ++i) {
		cin >> s;
		st1.insert(s);
	}
	for (i = 0; i < M; ++i) {
		cin >> s;
		if (st1.find(s) != st1.end()) st2.insert(s);
	}
	printf("%d\n", st2.size());
	for (auto it = st2.begin(); it != st2.end(); ++it) cout << *it << "\n";

}