/*
	Author : Ji heon, Kim
	Date : 19.03.26
	Problem Number: 2869
	Problem Name: 달팽이는 올라가고 싶당
*/

#include <iostream>
using namespace std;

int main() {
   int A, B, V, day;
   cin >> A >> B >> V;
   day = (V - A) / (A - B) + 1;
   if ((V - A) % (A - B))
      day++;
   cout << day << endl;
}