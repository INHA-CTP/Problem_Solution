/*
Author : INSIK CHO
Date : 19.04.30
*/
#include <iostream>
#include <string>
using namespace std;
string k, s, d;
int N;
pair<char, char> move(char x, char y, string d) {
	char tx = x, ty = y;
	for (int i = 0; i < d.length(); i++) {
		if (d[i] == 'R') ty++;
		else if (d[i] == 'L') ty--;
		else if (d[i] == 'B') tx--;
		else tx++;
	}
	return { tx, ty };
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio("false");
	cin >> k >> s >> N;
	char ty = k[0], tx = k[1], tsy = s[0], tsx = s[1];
	for (int i = 0; i < N; i++) {
		cin >> d;
		pair<char, char> ktmp = move(tx, ty, d);
		pair<char, char> stmp = { tsx, tsy };
		if (tsx == ktmp.first && tsy == ktmp.second) {
			stmp = move(tsx, tsy, d);
		}
		if (ktmp.first >= '1' && ktmp.first <= '8' && ktmp.second >= 'A' && ktmp.second <= 'H'
			&& stmp.first >= '1' && stmp.first <= '8' && stmp.second >= 'A' && stmp.second <= 'H') {
			tx = ktmp.first;
			ty = ktmp.second;
			tsx = stmp.first;
			tsy = stmp.second;
		}
	}
	cout << ty << tx << "\n" << tsy << tsx << "\n";
	return 0;
}