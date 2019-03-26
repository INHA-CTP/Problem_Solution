/*
	Author : Ji heon, Kim
	Date : 19.03.26
	Problem Number: 5063
	Problem Name: TGN
*/

#include <iostream>
using namespace std;

int main() {
   int T, r, e, c;
   cin >> T;
   while (T--) {
      cin >> r >> e >> c;
      if (r > e - c) {
         cout << "do not advertise" << endl;
      }
      else if (r == e - c) {
         cout << "does not matter" << endl;
      }
      else {
         cout << "advertise" << endl;
      }
   }
}