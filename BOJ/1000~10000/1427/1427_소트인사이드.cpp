/*
	Author : Hak kyu, Kim
	Date : 19.04.02
	Problem Number:  1427
	Problem Name: 소트인사이드
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

int main()
{
	int i, j, x;
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	for (i = s.size() - 1; i >= 0; --i) printf("%c", s[i]);
}