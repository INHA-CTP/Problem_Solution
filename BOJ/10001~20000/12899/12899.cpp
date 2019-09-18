#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX_SIZE 2000100

using namespace std;

int n, T, X;
int nums[2000100];
vector<int> tree;

int update(int pos, int val, int node, int start, int end) {

	if (pos < start || end < pos)
		return tree[node];
	if (start == end)
		return tree[node] = val;

	int mid = (start + end) / 2;
	return tree[node] = update(pos, val, node * 2, start, mid) + update(pos, val, node * 2 + 1, mid + 1, end);
}

int kth(int node, int start, int end, int k) {

	if (start == end)
		return start;

	int mid = (start + end) / 2;
	if (k <= tree[node * 2])
		return kth(node * 2, start, mid, k);
	else
		return kth(node * 2 + 1, mid + 1, end, k - tree[node * 2]);
}

int main() {

	int h = (int)ceil(log2(MAX_SIZE));
	int ts = (1 << (h + 1));
	tree.resize(ts);

	int temp;
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &T, &X);
		if (T == 1) {
			nums[X]++;
			update(X, nums[X], 1, 1, MAX_SIZE);
		}
		else if (T == 2) {
			temp = kth(1, 1, MAX_SIZE, X);
			nums[temp]--;
			update(temp, nums[temp], 1, 1, MAX_SIZE);
			printf("%d\n", temp);
		}
	}
}
