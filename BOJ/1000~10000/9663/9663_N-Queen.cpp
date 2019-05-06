/*
Author : INSIK CHO
Date : 19.04.30
*/
#include<iostream>
using namespace std;
#define MAX 15

bool r[MAX], rd[MAX * 2], ld[MAX * 2];	//세로, 대각선에 퀸이 있는지 체크
int n, ans;
void dfs(int i) {
	for (int j = 0; j < n; j++) {
		if (!r[j] && !rd[i + j] && !ld[i - j + (n - 1)]) {
			if (i == (n - 1))
				ans++;
			else {
				r[j] = rd[i + j] = ld[i - j + (n - 1)] = true;
				dfs(i + 1);
				r[j] = rd[i + j] = ld[i - j + (n - 1)] = false;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	dfs(0);
	cout << ans << '\n';
	return 0;
}