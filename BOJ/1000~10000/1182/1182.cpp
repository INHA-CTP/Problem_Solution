/*
	author: Hyeoung Dong, Choi
	date: 19.04.04
*/

#include <iostream>
using namespace std;

int arr[21];
int s;
int n;
int cnt;


void Search(int a, int b)
{
	b += arr[a];

	if (a >= n)
		return;

	if (b == s)
	{
		cnt++;
	}

	Search(a + 1, b - arr[a]);
	Search(a + 1, b);

}


int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	Search(0, 0);

	cout << cnt << endl;

	return  0;
}
