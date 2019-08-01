#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<unordered_set>
using namespace std;

unordered_set<string> st;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		st.insert(str);
	}
	int ans = 0;
	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;
		if (st.count(str))
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}
