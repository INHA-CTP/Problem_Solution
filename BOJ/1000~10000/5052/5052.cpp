#include<cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct Trie
{
	bool valid;
	Trie* children[10];

	Trie()
	{
		fill(children, children + 10, nullptr);
		valid = false;
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
			valid = true;
		else
		{
			int next = *key - '0';
			if (!children[next])
				children[next] = new Trie;
			children[next]->insert(key + 1);
		}
	}
	bool consistent()
	{
		for (int i = 0; i < 10; i++)
		{
			if (children[i])
			{
				if (valid)
				{
					return false;
				}
				else
				{
					if (!children[i]->consistent())
					{
						return false;
					}
				}
			}
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
			char tel[11];
			scanf("%s", tel);
			root->insert(tel);
		}
		puts(root->consistent() ? "YES" : "NO");
		delete root;
	}
	return 0;
}
