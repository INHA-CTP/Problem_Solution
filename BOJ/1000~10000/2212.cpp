#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
using namespace std;
#define ll long long
const int INF = 1000000000;
const int MAX = 100000;
const ll LINF = 1000000000000000000;

int arr[10001];

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", arr + i);
	sort(arr, arr + N);
	priority_queue<int> pq;
	for (int i = 1; i < N; i++)
	{
		int temp = arr[i] - arr[i - 1];
		if (temp > 0)
			pq.push(temp);
	}
	K--;
	while (K-- && !pq.empty())
	{
		pq.pop();
	}
	int sum = 0;
	while (!pq.empty())
	{
		sum += pq.top();
		pq.pop();
	}
	printf("%d\n", sum);
	return 0;
}
