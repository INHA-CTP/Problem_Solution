/*
	Author : SIYUN LEE
	Date : 19.03.18
*/

#include <cstdio>
using namespace std;

int arr[1000];

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int N;
		scanf("%d", &N);
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			scanf("%d", arr + i);
			sum += arr[i];
		}
		sum /= N;
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			if (arr[i] > sum)
				cnt++;
		}
		printf("%.3lf", (double)cnt*100 / N);
		puts("%");
	}
	return 0;
}
