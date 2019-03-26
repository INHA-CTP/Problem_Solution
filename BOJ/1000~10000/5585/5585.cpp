/*
	Author : Ji heon, Kim
	Date : 19.03.26
	Problem Number: 5585
	Problem Name: 거스름 돈
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int N, m;

int main() {
   cin >> N;
   N = 1000 - N;
   m += N / 500;
   N = N % 500;
   m += N / 100;
   N = N % 100;
   m += N / 50;
   N = N % 50;
   m += N / 10;
   N = N % 10;
   m += N / 5;
   N = N % 5;
   m += N;
   cout << m << endl;
}