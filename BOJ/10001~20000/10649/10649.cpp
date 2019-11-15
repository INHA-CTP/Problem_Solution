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

int N, H;
pair<pair<int, int>, int> arr[20];

bool cmp(pair<pair<int, int>, int>& A, pair<pair<int, int>, int>& B)
{
	if (A.first.first == B.first.first)
	{
		if (A.first.second == B.first.second)
		{
			return A.second > B.second;
		}
		else
			return A.first.second > B.first.second;
	}
	else
		return A.first.first > B.first.first;
}

int go(int pos, int curh, int curRest)
{
	if (curh >= H)
		return curRest;
	if (pos == N)
		return -1;
	int ret = -1;
	for (int i = pos; i < N; i++)
	{
		if (curRest >= arr[i].first.second)
			ret = max(ret, go(i + 1, curh + arr[i].second, min(curRest - arr[i].first.second, arr[i].first.first-arr[i].first.second)));
	}
	return ret;
}

int main()
{
	scanf("%d %d", &N, &H);
	for (int i = 0; i < N; i++)
	{
		int h, w, p;
		scanf("%d %d %d", &h, &w, &p);
		arr[i].first.first = p+w;
		arr[i].first.second = w;
		arr[i].second = h;
	}
	sort(arr, arr + N, cmp);
	int ans = go(0, 0, INF);
	if (ans == -1)
		puts("Mark is too tall");
	else
		printf("%d\n", ans);
	return 0;
}
