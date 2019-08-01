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
	Node* children[10];
	Node()
	{
		valid = false;
		for (int i = 0; i < 10; i++)
		{
			children[i] = NULL;
		}
	}
	~Node()
	{
		for (int i = 0; i < 10; i++)
		{
			if (children[i])
			{
				delete children[i];
			}
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
	int c = s[index] - '0';
	if (node->children[c] == NULL)
	{
		node->children[c] = new Node();
	}
	add(node->children[c], s, index + 1);
}

bool check(Node* node)
{
	for (int i = 0; i < 10; i++)
	{
		if (node->children[i] != NULL)
		{
			if (node->valid == true)
			{
				return false;
			}
			else
			{
				if (!check(node->children[i]))
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
		Node* root = new Node();
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			add(root, a[i], 0);
		}
		if (check(root))
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
		delete root;
	}
	return 0;
}
