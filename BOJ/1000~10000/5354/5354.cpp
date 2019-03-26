/*
	Author : Ji heon, Kim
	Date : 19.03.26
	Problem Number: 5354
	Problem Name: J박스
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int a, b, c, d, r;

int main()
{
    scanf("%d", &a);
    for (int i = 0; i < a; i++){
        scanf("%d", &b);
        if (b == 1){
            printf("#\n\n");
        }
        else{
            for (int j = 0; j < b; j++) {
                printf("#");
            }
            for (int k = 0; k < b - 2; k++){
                printf("\n#");
                for (int j = 0; j < b - 2; j++){
                    printf("J");
                }
                printf("#");
            }
            puts("");
            for (int j = 0; j < b; j++){
                printf("#");
            }
            printf("\n\n");
        }
    }
}