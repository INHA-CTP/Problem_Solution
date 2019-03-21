/*
	Author : Young Jo,An
	Date : 19.03.21
	Problem Number: 2804
	Problem Name: 크로스워드 만들기
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a, b;
	cin >> a >> b;
	int aa,bb;
	int n = a.size();
	int m = b.size();
	for (aa = 0; aa < n; aa++) {
		bool flag = false;
		for (bb = 0; bb < m; bb++) {
			if (a[aa] == b[bb]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	char map[31][31] = { 0 };
	for (int i = 0; i < n; i++) {
		map[bb][i] = a[i];
	}
	for (int i = 0; i < m; i++) {
		map[i][aa] = b[i];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j]) {
				cout << map[i][j];
			} else {
				cout << '.';
			}
		}
		cout << '\n';
	}
}
