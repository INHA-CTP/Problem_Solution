/*
	author: Hyeoung Dong, Choi
	date: 19.04.04
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N;
string a;
string sang = "ABC";
string chang = "BABC";
string hyun = "CCAABB";

int sangcnt;
int changcnt;
int hyuncnt;


int main()
{
	cin >> N;
	cin >> a;
	int check = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[i] == sang[i % 3])
			sangcnt++;

		if (a[i] == chang[i % 4])
			changcnt++;

		if (a[i] == hyun[i % 6])
			hyuncnt++;
	}

	int result = 0;

	result = max(sangcnt, max(changcnt, hyuncnt));
    
    cout<<result<<endl;
	if (result == sangcnt)
		cout << "Adrian" << endl;
    if (result == changcnt)
        cout << "Bruno" << endl;
    if (result == hyuncnt)
		cout << "Goran" << endl;

	return 0;
}