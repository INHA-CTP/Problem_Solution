/*
	Author : SIYUN LEE
	Date : 19.03.18
*/

#include <cstdio>
using namespace std;

int main()
{
	int N, X;
	scanf("%d %d", &N, &X);
	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		if (num < X)
			printf("%d ", num);
	}
	puts("");
	return 0;
}
