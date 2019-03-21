/*
	Author : Young Jo,An
	Date : 19.03.21
	Problem Number: 5622
	Problem Name: 다이얼
*/
#include <iostream>
#include <string>
using namespace std;

int t[26]={3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};

int main() 
{
	string s;
	cin>>s;
	int time=0;
	for(int i=0;i<s.size();i++)
	{
		time+=t[s[i]-'A'];
	}
	cout<<time;
}