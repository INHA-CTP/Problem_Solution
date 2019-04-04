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

struct obj {
	int kor, eng, math;
	string name;

	obj(int k, int e, int m, string n) : kor(k), eng(e), math(m), name(n) {

	}

	bool operator<(const obj& rhs) const {
		if (kor == rhs.kor) {
			if (eng == rhs.eng) {
				if (math == rhs.math) {
					return name < rhs.name;
				}
				return math > rhs.math;
			}
			return eng < rhs.eng;
		}
		return kor > rhs.kor;
	}
};

vector<obj> vec;

int main()
{
	int i, j;
	scanf("%d", &N);
	
	string s;
	int a, b, c;
	for (i = 0; i < N; ++i) {
		cin >> s >> a >> b >> c;
		vec.push_back(obj(a, b, c, s));
	}
	sort(vec.begin(), vec.end());
	for (i = 0; i < N; ++i) {
		cout << vec[i].name << "\n";
	}

}