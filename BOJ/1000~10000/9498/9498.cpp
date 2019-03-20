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
	if (N == 100)
		puts("A");
	else
	{
		int temp = N / 10;
		if (temp == 9)
			puts("A");
		else if (temp == 8)
			puts("B");
		else if (temp == 7)
			puts("C");
		else if (temp == 6)
			puts("D");
		else
			puts("F");
	}
	return 0;
}
