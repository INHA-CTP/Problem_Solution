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
multiset<string> st;

int main()
{
	int i, j, k;
	scanf("%d", &N);
	string s;
	for (i = 0; i < N; ++i) {
		cin >> s;
		st.insert(s);
	}
	for (i = 0; i < N - 1; ++i) {
		cin >> s;
		st.erase(st.find(s));
	}
	cout << *st.begin();
	

}