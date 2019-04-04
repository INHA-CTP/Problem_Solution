/*
	Author : Hak kyu, Kim
	Date : 19.04.02
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <cmath>
#include <time.h>
#include <unordered_map>
#define ll long long
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define PI 3.14159265
#define RAND (rand()*rand())
using namespace std;
const int MAX = 1e5 + 10; //N
const ll MOD = 1e9 + 7;
int N, M, K, Q;
ll A[10010], psum[10010];

int main()
{
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; ++i) {
		scanf("%lld", &A[i]);
	}
	sort(A + 1, A + 1 + N);
	for (i = 1; i <= N; ++i) {
		psum[i] = psum[i - 1] + A[i];
	}
	ll res = 0LL;
	for (i = 1; i <= N; ++i) {
		res += psum[N] - psum[i - 1] - (ll)(N - i + 1)*A[i];
	}
	printf("%lld", 2LL * res);

}