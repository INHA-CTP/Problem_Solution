/*
	Author : Ji heon, Kim
	Date : 19.03.26
	Problem Number: 1773 
	Problem Name: 폭죽
*/

#include <iostream>
#include <algorithm>
using namespace std;

int ans, n, c, a[101], b[2000001];

int main()
{
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = 1; j * a[i] <= c; j++)
        {
            b[j * a[i]] = 1;
        }
    }
    for (int i = 0; i <= c; i++)
    {
        if (b[i])
            ans++;
    }
    cout << ans << endl;
}