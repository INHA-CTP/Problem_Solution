#include <cstdio>
#include <algorithm>
using namespace std;

int arr[100000];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", arr + i);
	sort(arr, arr + N);
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int num;
		scanf("%d", &num);
		int t=binary_search(arr, arr + N, num);
		printf("%d\n", t);
	}
	return 0;
}
