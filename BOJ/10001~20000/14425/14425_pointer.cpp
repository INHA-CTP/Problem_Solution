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
	Node* children[26];
	Node()
	{
		valid = false;
		for (int i = 0; i < 26; i++)
		{
			children[i] = NULL;
		}
	}
	~Node() 
	{
		for (int i = 0; i < 26; i++)
		{
			if (children[i])
				delete children[i];
		}
	}
};

void add(Node* node, string& s, int index)
{
	if (index == s.size())
	{
		node->valid = true;
		return;
	}
	int c = s[index] - 'a';
	if (node->children[c] == NULL)
	{
		node->children[c] = new Node();
	}
	add(node->children[c], s, index + 1);
}

bool check(Node* node, string& s, int index)
{
	if (index == s.size())
	{
		for (int i = 0; i < 26; i++)
		{
			if (node->children[i] != NULL)
			{
				return false;
			}
		}
		return true;
	}
	if (node->children[s[index]-'a'] != NULL)
	{
		check(node->children[s[index] - 'a'], s, index + 1);
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
	Node* root = new Node();
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		add(root, a[i], 0);
	}
	int ans = 0;
	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;
		if (check(root, str, 0))
		{
			ans += 1;
		}
	}
	cout << ans << '\n';
	delete root;
	return 0;
}
