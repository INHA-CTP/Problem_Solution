#include <cstdio>
#define MAX 1e9

int t, candy, n;
int minn, patrick, sean;

int main() {

	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {

		scanf("%d", &n);
		minn = MAX;
		patrick = sean = 0;

		while (n--) {
			scanf("%d", &candy);
			patrick += candy;
			sean ^= candy;
			if (candy < minn) minn = candy;
		}
		printf("Case #%d: ", tc);
		if (sean) puts("NO");
		else printf("%d\n", patrick - minn);
	}
}
