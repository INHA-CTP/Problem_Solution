/*
	Author : Young Jo,An
	Date : 19.03.21
	Problem Number: 3062
	Problem Name: 수 뒤집기
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		string a,b;
		cin>>a;
		b=a;
		reverse(b.begin(), b.end());
		a=to_string(stoi(a)+stoi(b));
		bool same=true;
		for(int j=0,k=a.size()-1;j<=k && same;j++,k--)
		{
			if(a[j]!=a[k])
			{
				same=false;
			}
		}
		if(same)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
}