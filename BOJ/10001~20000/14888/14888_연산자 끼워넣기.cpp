/*
	author: Hyeoung Dong, Choi
	date: 19.04.04
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[12];
int brr[4];
long long mx = -1000000000;
long long mn = 1000000000;

void func(long long a,long long b)
{
	if (a >= N)
		return;

	if (a == N-1)
	{
		if (mx < b)
			mx = b;

		if (mn > b)
			mn = b;

		return;
	}
	if (brr[0] != 0)
	{
		brr[0]--;
		func(a+1,b + arr[a + 1]);
		brr[0]++;
	}
	if (brr[1] != 0)
	{
		brr[1]--;
		func(a+1,b - arr[a + 1]);
		brr[1]++;
	}
	if (brr[2] != 0)
	{
		brr[2]--;
		func(a+1,b * arr[a + 1]);
		brr[2]++;
	}
	if (brr[3] != 0)
	{
		brr[3]--;
		func(a+1,b / arr[a + 1]);
		brr[3]++;
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < 4; i++)
		cin >> brr[i];
        
	func(0,arr[0]);
	cout << mx << endl;
	cout << mn << endl;

	return 0;
}