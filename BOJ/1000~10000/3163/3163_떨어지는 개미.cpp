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
			// ���̰� ������ �ٶ󺸰� �ִٸ� ���� ��ġ�� �� ���̰� �������� �ð�
			// �ٸ� �� ���̴� �ش� ID�� ���� ���̶�� ���� x
			if (A[j].second < 0) A[cur++].first = p;
			// �������� �ٶ󺸰� �ִٸ� ������ �ݴ��� �������� �Ÿ��� �� �ð�
			else vt.push_back(l - p);
		}
		for (int j = 0; j < vt.size(); j++) {
			A[cur++].first = vt[j];
		}
		// �������� �ð��� ������������ �����Ͽ� k��°�� �������� ���̸� ����
		sort(A, A + n);
		cout << A[k - 1].second << endl;
	}
	return 0;
}