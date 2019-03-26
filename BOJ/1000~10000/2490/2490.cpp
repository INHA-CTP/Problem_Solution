/*
	Author : Ji heon, Kim
	Date : 19.03.26
	Problem Number: 2490
	Problem Name: 윳놀이
*/
#include <iostream>
using namespace std;

int main() {
   int array[4];
   int zero;
   for (int i = 0; i < 3; i++) {
      zero = 0;
      for (int j = 0; j < 4; j++) {
         cin >> array[j];
         if (array[j] == 0)
            zero++;
      }
      switch (zero) {
      case 0: cout << 'E' << endl; break;
      case 1: cout << 'A' << endl; break;
      case 2: cout << 'B' << endl; break;
      case 3: cout << 'C' << endl; break;
      case 4: cout << 'D' << endl; break;
      }
   }
}