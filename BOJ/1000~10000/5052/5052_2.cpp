#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
const int MAX = 1000000;
const int MOD = 1000000007;

struct Trie
{
	bool terminal;
	bool goexist;
	Trie* children[10];
	Trie() :terminal(false), goexist(false)
	{
		for (int i = 0; i < 10; i++)
		{
			children[i] = NULL;
		}
	}
	~Trie()
	{
		for (int i = 0; i < 10; i++)
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
			int next = *key - '0';
			if (children[next] == NULL)
				children[next] = new Trie;
			goexist = true;
			children[next]->insert(key + 1);
		}
	}
	bool query()
	{
		if (terminal&&goexist)
			return false;
		for (int i = 0; i < 10; i++)
		{
			if (children[i] && !children[i]->query())
				return false;
		}
		return true;
	}
};

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		Trie* root = new Trie;
		for (int i = 0; i < N; i++)
		{
			char str[11];
			scanf("%s", str);
			root->insert(str);
		}
		puts(root->query() ? "YES" : "NO");
		delete root;
	}
	return 0;
}
