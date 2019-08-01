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

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
int score[9] = { 0,0,0,1,1,2,3,5,11 };
char board[4][5];
bool check[4][4];
vector<string> words;

struct Trie
{
	bool terminal;
	Trie* children[26];
	Trie():terminal(false)
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
			terminal = true;
			return;
		}
		else
		{
			int next = *key - 'A';
			if (children[next] == nullptr)
			{
				children[next] = new Trie();
			}
			children[next]->insert(key + 1);
		}
	}

	void search(int x, int y,string s)
	{
		if (s.size() == 8)
			return;
		check[x][y] = true;
		int next = board[x][y] - 'A';
		if (children[next] == nullptr)
		{
			check[x][y] = false;
			return;
		}
		s += board[x][y];
		if (children[next]->terminal)
			words.push_back(s);
		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4||check[nx][ny])
				continue;
			children[next]->search(nx, ny, s);
		}
		check[x][y] = false;
	}
};

int main()
{
	Trie* root = new Trie();
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		char str[9];
		scanf("%s", str);
		root->insert(str);
	}
	int T;
	scanf("%d", &T);
	while (T--)
	{
		for (int i = 0; i < 4; i++)
		{
			scanf("%s", board[i]);
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				root->search(i, j, "");
			}
		}
		sort(words.begin(), words.end());
		words.erase(unique(words.begin(), words.end()), words.end());
		int sum = 0;
		int cnt = 0;
		int maxx = 0;
		int idx = 0;
		for (int i = 0; i < words.size(); i++)
		{
			sum += score[words[i].size()];
			cnt += 1;
			if (maxx < words[i].size())
			{
				maxx = words[i].size();
				idx = i;
			}
		}
		printf("%d %s %d\n", sum, words[idx].c_str(), cnt);
		words.clear();
	}
	return 0;
}
