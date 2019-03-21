/*
	Author : Young Jo,An
	Date : 19.03.21
	Problem Number: 8958
	Problem Name: OX 퀴즈
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	string s;
	while (t--) {
		cin >> s;
		int cnt = 0;
		int ret = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'O') {
				ret += (cnt + 1);
				cnt++;
			} else {
				cnt = 0;
			}
		}
		cout << ret << '\n';
	}
	return 0;
}