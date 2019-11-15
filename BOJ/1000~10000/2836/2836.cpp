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

pair<int, int> p[300000];

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	int D = M;
	int idx = 0;
	for (int i = 0; i < N; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		D = max({D,s,e});
		if (s > e && e < M)
			p[idx++] = { e,min(s,M) };
	}
	sort(p, p + idx);
	long long ans = D + (D - M);
	int l = -1, r = -1;
	for (int i = 0; i < idx; i++)
	{
		if (r < p[i].first)
		{
			ans += 2 * (r - l);
			l = p[i].first;
			r = p[i].second;
		}
		else
			r = max(r, p[i].second);
	}
	ans += 2 * (r - l);
	printf("%lld\n", ans);
	return 0;
}
//http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220907708368&parentCategoryNo=&categoryNo=299&viewDate=&isShowPopularPosts=false&from=postList
//https://github.com/kks227/BOJ/blob/master/2800/2836.cpp
//이문제에선 D라는 변수를 안써도 되는데 혹시 문제에서 집 위치가 M보다 크게 나올경우엔 이렇게 푼다.
