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
	int children[10];
	Node()
	{
		valid = false;
		for (int i = 0; i < 10; i++)
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
	int c = s[index] - '0';
	if (trie[node].children[c] == -1)
	{
		int next = init(trie);
		trie[node].children[c] = next;
	}
	add(trie, trie[node].children[c], s, index + 1);
}

bool check(vector<Node>& trie, int node)
{
	for (int i = 0; i < 10; i++)
	{
		if (trie[node].children[i] != -1)
		{
			if (trie[node].valid == true)
			{
				return false;
			}
			else
			{
				if (!check(trie, trie[node].children[i]))
				{
					return false;
				}
			}
		}
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<string> a(n);
		vector<Node> trie;
		int root = init(trie);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			add(trie, root, a[i], 0);
		}
		if (check(trie, root))
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}
