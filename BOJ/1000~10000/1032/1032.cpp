/*
	Author : Young Jo,An
	Date : 19.03.21
	Problem Number: 1032
	Problem Name: 명령 프롬프트
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string result[51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> result[i];
	}
	bool equal = true;
	char first = ' ';
	for (int i = 0; i < result[0].size(); i++) {
		equal = true;
		first = result[0][i];
		for (int j = 1; j < n; j++) {
			if (first != result[j][i]) {
				equal = false;
				break;
			}
		}
		if (equal) {
			cout << first;
		} else {
			cout << "?";
		}
	}
	return 0;
}