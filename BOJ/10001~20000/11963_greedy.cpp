#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <set>
#include <stack>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1e9 + 1;
const long long LINF = 1e18 + 1;
const int MOD = 1000000007;
typedef long long ll;

bool check[100001];

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> elsie;
	for (int i = 0; i < N; i++)
	{
		int x;
		scanf("%d", &x);
		check[x] = true;
		elsie.push_back(x);
	}
	priority_queue<int> epq1,epq2;
	for (int i = 0; i < N; i++)
	{
		if (i < N / 2)
			epq1.push(elsie[i]);
		else
			epq2.push(elsie[i]);
	}
	vector<int> vt;
	for (int i = 1; i <= 2 * N; i++)
	{
		if (!check[i])
			vt.push_back(i);
	}
	sort(vt.begin(), vt.end());
	priority_queue<int> bpq1, bpq2;
	for (int i = 0; i < N; i++)
	{
		if (i < N / 2)
			bpq2.push(vt[i]);
		else
			bpq1.push(vt[i]);
	}
	int ans = 0;
	while (!epq1.empty() && !bpq1.empty())
	{
		int t1 = epq1.top();
		int t2 = bpq1.top();
		if (t1 < t2)
		{
			epq1.pop();
			bpq1.pop();
			ans++;
		}
		else
			epq1.pop();
	}
	while (!epq2.empty() && !bpq2.empty())
	{
		int t1 = epq2.top();
		int t2 = bpq2.top();
		if (t1 > t2)
		{
			epq2.pop();
			bpq2.pop();
			ans++;
		}
		else
			bpq2.pop();
	}
	printf("%d\n", ans);
	return 0;
}
