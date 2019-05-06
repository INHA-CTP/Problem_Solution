/*
Author : INSIK CHO
Date : 19.04.30
*/
#include <iostream>
using namespace std;
int k, n, t[101], cnt, time = 210;
char z[101];

int main() {
	scanf("%d%d", &k, &n);
	cnt = k;
	for (int i = 0; i < n; i++) {
		scanf("%d %c", &t[i], &z[i]);
	}
	for (int i = 0; i<n; i++) {
		cnt = cnt % 9;
		if (cnt == 0) cnt = 1;
		time -= t[i];
		if (z[i] == 'T') {
			if (time <= 0) break;
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}