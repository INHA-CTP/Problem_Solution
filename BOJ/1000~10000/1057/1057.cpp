/*
	Author : Ji heon, Kim
	Date : 19.03.26
	Problem Number: 1057
	Problem Name: 토너먼트
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int a, b, c, d, r;

int main() {
   scanf("%d%d%d", &a, &b, &c);
   while (b != c) {
      r++;
      c = (c + 1) / 2;
      b = (b + 1) / 2;
   }
   printf("%d\n", r);
}