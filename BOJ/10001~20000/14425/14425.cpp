#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

struct Node
{
	bool valid;
	int children[26];
	Node()
	{
		valid = false;
		for (int i = 0; i < 26; i++)
		{
			children[i] = -1;
		}
	}
};

int init(vector<Node>& trie)
{
	Node x;
	trie.push_back(x);
	return trie.size() - 1;
}

void add(vector<Node>& trie, int node, string& s, int index)
{
	if (index == s.size())
	{
		trie[node].valid = true;
		return;
	}
	int c = s[index] - 'a';
	if (trie[node].children[c] == -1)
	{
		int next = init(trie);
		trie[node].children[c] = next;
	}
	add(trie, trie[node].children[c], s, index + 1);
}

bool check(vector<Node>& trie, int node, string& s, int index)
{
	if (index == s.size())
	{
		for (int i = 0; i < 26; i++)
		{
			if (trie[node].children[i] != -1)
			{
				return false;
			}
		}
		return true;
	}
	if (trie[node].children[s[index] - 'a'] != -1)
	{
		check(trie, trie[node].children[s[index] - 'a'], s, index + 1);
	}
	else
	{
		return false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	vector<string> a(N);
	vector<Node> trie;
	int root = init(trie);
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		add(trie, root, a[i], 0);
	}
	int ans = 0;
	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;
		if (check(trie, root, str, 0))
		{
			ans += 1;
		}
	}
	cout << ans << '\n';
	return 0;
}
