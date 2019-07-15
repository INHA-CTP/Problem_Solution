#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <functional>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1000000001;
const long long LINF = 1e18 + 1;
typedef long long ll;

pair<int,int> a[10000];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &a[i].second, &a[i].first);
	sort(a, a + N);
	priority_queue<int> pq;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += a[i].second;
		pq.push(-a[i].second);
		if (pq.size() > a[i].first)
		{
			sum += pq.top();
			pq.pop();
		}
	}
	printf("%d\n", sum);
	return 0;
}
