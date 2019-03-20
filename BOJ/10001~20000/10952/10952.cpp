/*
	Author : SIYUN LEE
	Date : 19.03.18
*/

#include <cstdio>
using namespace std;

int main()
{
	int a, b;
	while (scanf("%d %d", &a, &b) == 2)
	{
		if (a == 0 && b == 0)
			return 0;
		printf("%d\n", a + b);
	}
	return 0;
}
