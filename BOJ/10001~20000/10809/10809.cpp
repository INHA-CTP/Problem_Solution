/*
	Author : Young Jo,An
	Date : 19.03.21
	Problem Number: 10809
	Problem Name: 알파벳 찾기
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int pos[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	memset(pos, -1, sizeof(pos));	//pos배열 -1로 초기화
	for (int i = 0; i < s.size(); i++) {
		if (pos[s[i] - 'a'] == -1) {
			pos[s[i] - 'a'] = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << pos[i] << ' ';
	}
}