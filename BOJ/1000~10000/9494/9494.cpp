/*
	Author : Young Jo,An
	Date : 19.03.21
	Problem Number: 9494
	Problem Name: 데구르르
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cin.ignore();
	string s;
	int index = 1;
	while (n != 0) {
		index = 1;
		while (n--) {
			getline(cin, s);
			for (int i = index - 1; i < s.size(); i++) {
				if (s[i] == ' ') {
					index = i+1;
					break;
				}
				if (i == s.size() - 1) {
					index = s.size()+1;
				}
			}
		}
		cout << index << '\n';
		cin >> n;
		cin.ignore();
	}
	return 0;
}