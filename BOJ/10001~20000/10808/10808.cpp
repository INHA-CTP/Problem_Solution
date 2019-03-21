/*
	Author : Young Jo,An
	Date : 19.03.21
	Problem Number: 10808
	Problem Name: 알파벳 개수
*/
#include <iostream>
#include <string>
using namespace std;
int cnt[26];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		cnt[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << cnt[i] << ' ';
	}
	return 0;
}