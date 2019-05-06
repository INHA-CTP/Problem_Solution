/*
Author : INSIK CHO
Date : 19.04.30
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, area[51][51];
int go(int r, int c, int color) {
	int ret = 0;
	for (int i = r; i < r + 8; i++) {
		for (int j = c; j < c + 8; j++) {
			if (!(j % 2) && area[i][j] != color) ret++;
			else if (j % 2 && area[i][j] == color) ret++;
		}
		color != color;
	}
	return ret;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char num;
			scanf(" %C", &num);
			if (num == 'W') area[i][j] = 0;
			else area[i][j] = 1;
		}
	}
	int ret = 9999;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			ret = min(ret, go(i, j, 0));
			ret = min(ret, go(i, j, 1));
		}
	}
	printf("%d\n", ret);
	return 0;
}