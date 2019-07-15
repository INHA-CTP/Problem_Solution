#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
using namespace std;

const int INF = 1000000000;
int arr[2001];
vector<pair<int, pair<int, int>>> vt;


int main()
{
	int N, C;
	scanf("%d %d", &N, &C);
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		vt.push_back({ v,{u,w} });
	}
	sort(vt.begin(), vt.end());
	int ans = 0;
	for (int i = 0; i < M; i++)
	{
		int get = 0;
		int from = vt[i].second.first;
		int to = vt[i].first;
		int val = vt[i].second.second;

		for (int j = from; j < to; j++)
			get = max(get, arr[j]);

		get = min(C - get, val);
		ans += get;

		for (int j = from; j < to; j++)
			arr[j] += get;

	}

	printf("%d\n", ans);
	return 0;
}
//구글링 하세요;;;....
