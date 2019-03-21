/*
	Author : Young Jo,An
	Date : 19.03.20
	Problem Number: 11718
	Problem Name: 그대로 출력하기
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	while (getline(cin, s)) {
		cout << s << "\n";
	}
}
