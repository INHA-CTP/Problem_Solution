/*
	Author : Young Jo,An
	Date : 19.03.21
	Problem Number: 2744
	Problem Name: 대소문자 바꾸기
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			cout << char(s[i] - 'A' + 'a');
		} else {
			cout << char(s[i] - 'a' + 'A');
		}
	}
	return 0;
}