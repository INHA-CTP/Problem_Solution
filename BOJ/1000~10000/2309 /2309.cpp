/*
	Author : Ji heon, Kim
	Date : 19.03.26
	Problem Number: 2309
	Problem Name: 일곱난쟁이
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int key[9];
int sum;
int a, b;

int main()
{
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &key[i]);
        sum += key[i];
    }

    sort(key, key + 9);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (i != j && key[i] + key[j] == sum - 100)
            {
                a = i;
                b = j;
            }
        }
    }
    
    for (int i = 0; i < 9; i++)
    {
        if (i != a && i != b)
            printf("%d\n", key[i]);
    }
}