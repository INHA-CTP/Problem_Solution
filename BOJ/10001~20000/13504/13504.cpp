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
	Trie* children[2];
	Trie()
	{
		for (int i = 0; i < 2; i++)
		{
			children[i] = nullptr;
		}
	}
	~Trie()
	{
		for (int i = 0; i < 2; i++)
		{
			if (children[i])
				delete children[i];
		}
	}

	void insert(const char* key)
	{
		if (*key == '\0')
			return;
		else
		{
			int next = *key - '0';
			if (children[next] == nullptr)
			{
				children[next] = new Trie();
			}
			children[next]->insert(key + 1);
		}
	}

	void query(char* key)
	{
		if (*key == '\0')
			return;
		int next = *key - '0';
		next ^= 1;
		if (children[next])
		{
			*key = '1';
			children[next]->query(key + 1);
		}
		else
		{
			*key = '0';
			children[next ^ 1]->query(key + 1);
		}
	}
};

unsigned int arr[100001];
unsigned int pxor[100001];
char str[100001][33];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		Trie* root = new Trie();
		int N;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			scanf("%u", &arr[i]);
		}
		unsigned int maxx = 0;
		for (int i = 1; i <= N; i++)
		{
			pxor[i] = pxor[i - 1] ^ arr[i];
			maxx = max(maxx, pxor[i]);
		}
		for (int i = 1; i <= N; i++)
		{
			for (int j = 31; j >= 0; j--)
			{
				if (pxor[i] % 2)
					str[i][j] = '1';
				else
					str[i][j] = '0';
				pxor[i] /= 2;
			}
			str[i][32] = '\0';
		}
		for (int i = 1; i <= N; i++)
		{
			root->insert(str[i]);
		}

		for (int i = 1; i <= N; i++)
		{
			root->query(str[i]);
			unsigned int temp = 0;
			for (int j = 31; j >= 0; j--)
			{
				temp += (str[i][j] - '0')*pow(2, 31 - j);
			}
			maxx = max(maxx, temp);
		}
		printf("%u\n", maxx);
        delete root;
	}
	return 0;
}
