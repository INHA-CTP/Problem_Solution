/*
	Author : INSIK CHO
	Date : 19.04.30
*/
#include <iostream>
using namespace std;
int m, result = 1;

int main() {
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == result) result = b;
        else if (b == result) result = a;
    }
    printf("%d\n", result);
    return 0;
}