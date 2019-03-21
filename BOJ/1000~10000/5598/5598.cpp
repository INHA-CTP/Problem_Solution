/*
	Author : Young Jo,An
	Date : 19.03.21
	Problem Number: 5598
	Problem Name: 카이사르 암호
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		s[i] = (s[i] - 'A' - 3) % 26;
		if (s[i] < 0) {
			s[i] += 26;
		}
		cout << (char)(s[i] +'A');
	}
	return 0;
}