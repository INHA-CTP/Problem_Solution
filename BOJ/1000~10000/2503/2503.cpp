/*
	Author : Ji heon, Kim
	Date : 19.03.26
	Problem Number: 2503 
	Problem Name: 숫자야구
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int n, q, w, e, r;
int a[1000];

pair<int, int> func(int a, int b) {
    int c = 0, d = 0;
    int e[3], f[3];
    for (int i = 2; i >= 0; i--)
    {
        e[i] = a % 10;
        a /= 10;
        f[i] = b % 10;
        b /= 10;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (e[i] == f[j])
            {
                if (i == j)
                    c++;
                else
                    d++;
            }
        }
    }
    return {c, d};
}

int main()
{
    cin >> n;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            for (int k = 1; k < 10; k++)
            {
                if (j != i && k != j && i != k)
                    a[100 * i + 10 * j + k] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> q >> w >> e;
        for (int i = 123; i < 988; i++)
        {
            if (func(q, i).first != w || func(q, i).second != e)
                a[i] = 0;
        }
    }
    for (int i = 123; i < 988; i++)
    {
        if (a[i])
            r++;
    }
    cout << r << endl;
}