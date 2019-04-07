/*
	author: Hyeoung Dong, Choi
	date: 19.04.04
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A;
int B;
int result;
vector<int> k;
vector<int> ::iterator P;

int main()
{
	for (int i = 0; i < 4; i++)
	{
		cin >> A >> B;
		result += (B - A);
		k.push_back(result);

	 }
	sort(k.begin(), k.end());
	P = k.end();
	P--;
	cout << *P << endl;
    
	return 0;
}