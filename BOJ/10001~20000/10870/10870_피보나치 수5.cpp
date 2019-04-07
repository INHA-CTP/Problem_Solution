/*
	author: Hyeoung Dong, Choi
	date: 19.04.04
*/

#include <iostream>
using namespace std;

int N;
int arr[50];
int visited[50];

int Fibo(int a)
{
	if (a == 0)
		return 0;
	if (a == 1)
		return 1;
	if (visited[a] != 1)
	{
		visited[a] = 1;
		arr[a] = Fibo(a - 1) + Fibo(a - 2);
		return Fibo(a - 1) + Fibo(a - 2);
	}
	else
	{
		return arr[a];
	}

}
int main()
{
	cin >> N;

	cout << Fibo(N) << endl;
	return 0;
}