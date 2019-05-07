#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF = 1000000000;

int dp[100001];
int dp2[100001];

int main()
{
	int N, M;
	while (scanf("%d %d", &N, &M) == 2)
	{
		if (N == 0 && M == 0)
			return 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				scanf("%d", dp + j);
			}
			for (int j = 2; j <= M; j++)
			{
				dp[j] = max(dp[j - 1], dp[j - 2] + dp[j]);
			}
			dp2[i] = dp[M];
		}
		for (int i = 2; i <= N; i++)
		{
			dp2[i] = max(dp2[i - 1], dp2[i - 2] + dp2[i]);
		}
		printf("%d\n", dp2[N]);
	}
	return 0;
}
