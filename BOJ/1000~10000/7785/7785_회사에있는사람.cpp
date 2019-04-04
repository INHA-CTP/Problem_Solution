/*
	Author : Hak kyu, Kim
	Date : 19.04.02
	Problem Number:  7785
	Problem Name: 회사에있는사람
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

int main()
{
	int i, j;
	scanf("%d", &N);
	string s, t;
	set<string> st;
	for (i = 0; i < N; ++i) {
		cin >> s >> t;
		if (t == "enter") st.insert(s);
		else st.erase(s);
	}
	vector<string> res;
	for (auto it = st.begin(); it != st.end(); ++it) {
		res.push_back(*it);
	}
	for (i = res.size() - 1; i >= 0; --i) cout << res[i] << "\n";
}