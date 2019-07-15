#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <iostream>
#include <string>
using namespace std;
#define ll long long
const int INF = 1000000000;
const int MAX = 100000;

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	queue<int> q[21];
	long long ans = 0;
	for (int i = 0; i < N; i++)
	{
		char name[21];
		scanf("%s", name);
		int len = strlen(name);
		while (!q[len].empty() && q[len].front() < i - K)
			q[len].pop();
		ans += q[len].size();
		q[len].push(i);
	}
	printf("%lld\n", ans);
	return 0;
}
