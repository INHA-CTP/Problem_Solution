/*
	Author : SIYUN LEE
	Date : 19.03.18
*/

#include <cstdio>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= 9; i++)
	{
		printf("%d * %d = %d\n", N, i, N*i);
	}
	return 0;
}
