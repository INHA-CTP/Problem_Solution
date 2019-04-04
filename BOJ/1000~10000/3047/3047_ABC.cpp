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

int main()
{
	int i, j;
	int arr[4];
	scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
	if (arr[1] < arr[0]) swap(arr[0], arr[1]);
	if (arr[2] < arr[0]) swap(arr[0], arr[2]);
	if (arr[2] < arr[1]) swap(arr[1], arr[2]);
	char str[4];
	scanf("%s", str);
	for (i = 0; i < 3; ++i) {
		printf("%d ", arr[str[i] - 'A']);
	}

}