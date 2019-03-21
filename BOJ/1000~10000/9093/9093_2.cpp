/*
	Author : Young Jo,An
	Date : 19.03.21
	Problem Number: 9093
	Problem Name: 단어 뒤집기
*/
#include <iostream>
#include <cstring>

using namespace std;

char* pt;
char st[1000];
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++)
	{		
		cin.getline(st,1000);
		pt=strtok(st," ");
		while(pt!=NULL)
		{
			for(int j=strlen(pt)-1;j>=0;j--)
			{
				cout<<pt[j];
			}
			pt=strtok(NULL," ");
			cout<<" ";
		}
		cout<<"\n";
	}
}