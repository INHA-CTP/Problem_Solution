/*
Author : INSIK CHO
Date : 19.04.30
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t, n, l, k, cur;
pair<int, int> A[100001];
vector<int> vt;

int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d%d%d", &n, &l, &k);
		for (int j = 0; j < n; j++) {
			int p;
			scanf("%d%d", &p, &A[j].second);
			// 개미가 왼쪽을 바라보고 있다면 현재 위치가 곧 개미가 떨어지는 시각
			// 다만 그 개미는 해당 ID를 가진 개미라는 보장 x
			if (A[j].second < 0) A[cur++].first = p;
			// 오른쪽을 바라보고 있다면 막대의 반대쪽 끝까지의 거리가 곧 시각
			else vt.push_back(l - p);
		}
		for (int j = 0; j < vt.size(); j++) {
			A[cur++].first = vt[j];
		}
		// 떨어지는 시각을 오름차순으로 정렬하여 k번째로 떨어지는 개미를 구함
		sort(A, A + n);
		cout << A[k - 1].second << endl;
	}
	return 0;
}