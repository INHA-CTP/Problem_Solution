/*
	Author : Ji heon, Kim
	Date : 19.03.26
	Problem Number: 2798
	Problem Name: 블랙잭
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int a, b, c, d, r, n, m;
int t[100];

int main()
{
    scanf("%d%d", &a, &b);
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &t[i]);
    }
    for (int i = 0; i < a - 2; i++)
        for (int j = i + 1; j < a - 1; j++)
            for (int k = j + 1; k < a; k++)
                if (t[i] + t[j] + t[k] <= b)
                    m = max(m, t[i] + t[j] + t[k]);

    printf("%d\n", m);
}