/*
	Author : Ji heon, Kim
	Date : 19.03.26
	Problem Number: 2563
	Problem Name: 색종이
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int a, b, c, d, r;
int m[100][100];

int main() {
   scanf("%d", &a);
   for (int i = 0; i < a; i++) {
      scanf("%d%d", &b, &c);
      for (int j = b; j < b + 10; j++) {
         for (int k = c; k < c + 10; k++) {
            m[j][k] = 1;
         }
      }
   }
   for (int i = 0; i < 100; i++) {
      for (int j = 0; j < 100; j++) {
         if (m[i][j])
            r++;
      }
   }
   printf("%d\n", r);
}