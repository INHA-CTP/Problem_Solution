/*
	Author : SIYUN LEE
	Date : 19.03.18
*/

#include <cstdio>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n%d\n%d\n%d\n", (a + b) % c, (a%c + b % c) % c, (a*b) % c, (a%c*b%c) % c);
	return 0;
}
