#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<functional>
#include<iomanip>
using namespace std;
const int INF = 1000000000;

long long sum;

struct Trie
{
	bool terminal;
	int jason;
	int cnt;
	Trie* children[26];
	Trie() :terminal(false), jason(0),cnt(0)
	{
		for (int i = 0; i < 26; i++)
		{
			children[i] = nullptr;
		}
	}
	~Trie()
	{
		for (int i = 0; i < 26; i++)
		{
			if (children[i])
				delete children[i];
		}
	}

	void insert(const char* key)
	{
		if (*key == '\0')
		{
			terminal=true;
			return;
		}
		else
		{
			int next = *key - 'a';
			if (children[next] == nullptr)
			{
				jason++;
				children[next] = new Trie();
			}
			cnt++;
			children[next]->insert(key+1);
		}
	}

	void find()
	{
		if (terminal || jason > 1)
		{
			sum += cnt;
		}
		for (int i = 0; i < 26; i++)
		{
			if (children[i])
				children[i]->find();
		}
	}
};

int main()
{
	int N;
	while (scanf("%d", &N) == 1)
	{
		sum = 0;
		Trie* root = new Trie();
		for (int i = 0; i < N; i++)
		{
			char str[81];
			scanf("%s", str);
			root->insert(str);
		}
		root->find();
		if (root->jason == 1)
			sum += N;
		double ans = (double)sum / (double)N;
		printf("%.2lf\n", ans);
		delete root;
	}
	return 0;
}
