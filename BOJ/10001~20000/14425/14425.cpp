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
using namespace std;
const int INF = 1000000000;

struct Trie
{
	bool terminal;
	Trie* children[26];
	Trie() :terminal(false)
	{
		for (int i = 0; i < 26; i++)
		{
			children[i] = NULL;
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
			terminal = true;
			return;
		}
		else
		{
			int next = *key - 'a';
			if (children[next] == NULL)
				children[next] = new Trie();
			children[next]->insert(key + 1);
		}
	}

	bool find(const char* key)
	{
		if (*key == '\0' && terminal)
			return true;
		int next = *key - 'a';
		if (!children[next])
			return false;
		else
			children[next]->find(key + 1);
	}
};

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	Trie* root = new Trie();
	for (int i = 0; i < N; i++)
	{
		char str[501];
		scanf("%s", str);
		root->insert(str);
	}
	int ret = 0;
	for (int i = 0; i < M; i++)
	{
		char str[501];
		scanf("%s", str);
		if (root->find(str))
			ret++;
	}

	printf("%d\n", ret);
	delete root;

	return 0;
}
