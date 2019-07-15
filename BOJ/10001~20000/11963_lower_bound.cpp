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
const int INF = 1e9 + 1;
const int MOD = 1000000007;
typedef long long ll;

bool check[100001];

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> a(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
		check[a[i]] = true;
	}
	vector<int> temp;
	for (int i = 1; i <= 2 * N; i++)
		if (!check[i])
			temp.push_back(i);
	sort(temp.begin(), temp.end());
	set<int> small, big;
	for (int i = 0; i < N; i++)
	{
		if (i < N / 2)
			small.insert(temp[i]);
		else
			big.insert(temp[i]);
	}
	int ans = 0;
	for (int i = 0; i < N / 2; i++)
	{
		auto it = big.lower_bound(a[i]);
		if (it != big.end())
		{
			ans++;
			big.erase(it);
		}
	}
	for (int i = N/2; i < N; i++)
	{
		auto it = small.lower_bound(a[i]);
		if (it == small.begin())
		{
			if (*it < a[i])
			{
				ans++;
				small.erase(it);
			}
		}
		else
		{
			it--;
			if (*it < a[i])
			{
				ans++;
				small.erase(it);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
