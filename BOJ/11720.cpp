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
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%1d", &num);
		sum += num;
	}
	printf("%d\n", sum);
	return 0;
}
