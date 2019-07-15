#include <cstdio>
#include <algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
const int INF = 1000000000;

int main()
{
	int N, T, P;
	scanf("%d %d %d", &N, &T, &P);
	priority_queue<int> pq;
	int ans = 0;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (T < i*P)
			break;
		int k;
		scanf("%d", &k);
		sum += k;
		pq.push(k);
		while (sum + i*P > T)
		{
			sum -= pq.top();
			pq.pop();
		}
		ans = max(ans, (int)pq.size());
	}
	printf("%d\n", ans);
	return 0;
}
