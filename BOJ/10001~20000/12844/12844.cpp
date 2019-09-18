#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 5e5;

int n, m, tree[MAX * 4], lazy[MAX * 4], input[MAX * 4];

int init(int node, int start, int end) {

	if (start == end)
		return tree[node] = input[start];

	int mid = (start + end) / 2;
	return tree[node] = init(node * 2, start, mid) ^ init(node * 2 + 1, mid + 1, end);
}

void update_lazy(int node, int start, int end) {

	if (lazy[node]) {
		tree[node] ^= lazy[node] * ((end - start + 1) % 2);
		if (start != end) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(int left, int right, int node, int start, int end, int val, int depth) {

	update_lazy(node, start, end);
	if (right < start || end < left) return;

	if (left <= start && end <= right) {
		tree[node] ^= val * ((end - start + 1) % 2);
		if (start != end) {
			lazy[node * 2] ^= val;
			lazy[node * 2 + 1] ^= val;
		}
		return;
	}

	int mid = (start + end) / 2;

	update_range(left, right, node * 2, start, mid, val, depth + 1);
	update_range(left, right, node * 2 + 1, mid + 1, end, val, depth + 1);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int query(int left, int right, int node, int start, int end) {

	update_lazy(node, start, end);
	if (right < start || end < left)
		return 0;
	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return query(left, right, node * 2, start, mid) ^ query(left, right, node * 2 + 1, mid + 1, end);
}

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &input[i]);

	init(1, 1, n);

	scanf("%d", &m);
	int t, a, b, c, minn, maxn;
	while (m--) {
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d %d %d", &a, &b, &c);
			minn = min(a, b);
			maxn = max(a, b);
			update_range(minn + 1, maxn + 1, 1, 1, n, c, 1);
		}
		else if (t == 2) {
			scanf("%d %d", &a, &b);
			minn = min(a, b);
			maxn = max(a, b);
			printf("%d\n", query(minn + 1, maxn + 1, 1, 1, n));
		}
	}
}
