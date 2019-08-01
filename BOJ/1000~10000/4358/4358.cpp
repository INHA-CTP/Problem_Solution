#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<unordered_set>
#include<iomanip>
using namespace std;

int N;

struct Node
{
	int valid;
	Node* childrent[96];
	Node()
	{
		valid = 0;
		for (int i = 0; i < 96; i++)
		{
			childrent[i] = NULL;
		}
	}
	~Node()
	{
		for (int i = 0; i < 96; i++)
		{
			if (childrent[i])
				delete childrent[i];
		}
	}
};

void add(Node* node, string& s, int index)
{
	if (index == s.size())
	{
		node->valid++;
		return;
	}
	int c = s[index]-32;
	if (node->childrent[c] == NULL)
	{
		Node* next = new Node();
		node->childrent[c] = next;
	}
	add(node->childrent[c], s, index + 1);
}

void print(Node* node,string s)
{
	if (node->valid > 0)
	{
		cout << s << ' ' <<fixed<< setprecision(4) << 100.0*node->valid / N<<'\n';
	}
	for (int i = 0; i < 96; i++)
	{
		if (node->childrent[i] != NULL)
		{
			s.push_back((char)(i+32));
			print(node->childrent[i],s);
			s.pop_back();
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Node* root = new Node();
	string str;
	while (getline(cin,str))
	{
		N++;
		add(root, str, 0);
	}
	print(root,"");
	delete root;
	return 0;
}
