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

struct Trie
{
	bool terminal;
	bool exist;
	bool del;
	Trie* children[128];
	Trie() :terminal(false),exist(false),del(false)
	{
		for (int i = 0; i < 128; i++)
		{
			children[i] = nullptr;
		}
	}
	~Trie()
	{
		for (int i = 0; i < 128; i++)
		{
			if (children[i])
				delete children[i];
		}
	}

	void insert(const char* key,bool ok)
	{
		if (*key == '\0')
		{
			terminal=ok;
			del=ok;
			return;
		}
		else
		{
			int next = *key;
			if (children[next] == nullptr)
			{
				children[next] = new Trie();
			}
			exist = true;
			del = ok;
			children[next]->insert(key+1,ok);
		}
	}

	int find()
	{
		int sum = 0;
		if (del)
		{
			return 1;
		}
		else if (terminal)
		{
			sum += 1;
		}
		for (int i = 0; i < 128; i++)
		{
			if (children[i])
				sum += children[i]->find();
		}
		return sum;
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
		Trie* root = new Trie();
		for (int i = 0; i < N; i++)
		{
			char str[21];
			scanf("%s", str);
			root->insert(str,true);
		}
		int M;
		scanf("%d", &M);
		for (int i = 0; i < M; i++)
		{
			char str[21];
			scanf("%s", str);
			root->insert(str, false);
		}
		printf("%d\n", root->find());
		delete root;
	}
	return 0;
}
//http://sejinik.tistory.com/105
//2018 ctp회장 갓세진 블로그
