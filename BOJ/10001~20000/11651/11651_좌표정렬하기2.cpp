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
set<pair<int, int>> st;

int main()
{
	int i, j, x, y;
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%d %d", &x, &y);
		st.insert({ y, x });
	}
	for (auto it = st.begin(); it != st.end(); ++it) printf("%d %d\n", it->second, it->first);

}