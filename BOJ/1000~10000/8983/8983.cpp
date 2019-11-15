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
const int INF = 1000000000;

int arr[100000];
pair<int, int> brr[100000];

int main()
{
	int M, N, L;
	scanf("%d %d %d", &M, &N, &L);
	for (int i = 0; i < M; i++)
		scanf("%d", arr + i);
	sort(arr, arr + M);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &brr[i].first, &brr[i].second);
	sort(brr, brr + N);
	int result = 0;
	int idx = 0;
	for (int i = 0; i < N; i++)
	{
		while (idx != M - 1 && arr[idx + 1] < brr[i].first)
			idx++;
		if (abs(arr[idx] - brr[i].first) + brr[i].second <= L)
		{
			result++;
			continue;
		}
		if (idx != M - 1)
		{
			if (abs(arr[idx+1] - brr[i].first) + brr[i].second <= L)
			{
				result++;
				continue;
			}
		}
	}
	printf("%d\n", result);
	return 0;
}
