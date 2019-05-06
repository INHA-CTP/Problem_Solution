/*
Author : INSIK CHO
Date : 19.04.30
*/
#include <iostream>
#include <algorithm>
using namespace std;
int n, l, m, r;
pair<int, int> f[101];

bool chk(int x, int y, int lx, int ly, int rx, int ry) {
	return lx <= x && x <= rx && ly <= y && y <= ry;
}
int count(int lx, int ly, int rx, int ry) {
	int ret = 0;
	for (int i = 0; i < m; i++)
		ret += chk(f[i].first, f[i].second, lx, ly, rx, ry);
	return ret;
}
void getnet(pair<int, int> p) {
	for (int k = 1; k < l; k++) {
		int nx = k;
		int ny = l - k;
		// 각 물고기가 있는 좌표가 그물의 테두리에 위치하는 모든 경우를 탐색
		// 테두리의 길이(그물의 둘레)는 100이하, 물고기 수도 100이하 이므로 시간은 충분
		for (int i = p.first - nx; i <= p.first; i++) {			
			for (int j = p.second - ny; j <= p.second; j++) {
				r = max(r, count(i, j, i + nx, j + ny));
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &l, &m);
	l /= 2;
	for (int i = 0; i < m; i++)
		scanf("%d%d", &f[i].first, &f[i].second);
	for (int i = 0; i < m; i++)
		getnet(f[i]);
	printf("%d\n", r);
	return 0;
}