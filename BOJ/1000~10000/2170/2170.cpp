#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include <map>
#include <set>
#include <stack>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1e9+1;
const int MOD = 1000000007;
typedef long long ll;

pair<int, int> a[1000000];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &a[i].first, &a[i].second);
	}
	sort(a, a + N);
	int result = 0;
	int l = -INF, r = -INF;
	for (int i = 0; i < N; i++)
	{
		if (r < a[i].first)
		{
			result += r - l;
			l = a[i].first;
			r = a[i].second;
		}
		else
		{
			r = max(r, a[i].second);
		}
	}
	result += r - l;
	printf("%d\n", result);
	return 0;
}
