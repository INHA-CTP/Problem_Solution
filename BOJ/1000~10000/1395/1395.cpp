#include <cstdio>

const int MAX = 1e5;

int n, m, o, s, t;
int tree[MAX * 4], lazy[MAX * 4], onoff[MAX * 4];

void update_lazy(int node, int start, int end) {

	if (lazy[node] != 0) {
		tree[node] = (end - start + 1) - tree[node];
		if (start != end) {
			lazy[node * 2] = 1 - lazy[node * 2];
			lazy[node * 2 + 1] = 1 - lazy[node * 2 + 1];
		}
		lazy[node] = 0;
	}
}

void update_range(int left, int right, int node, int start, int end) {

	update_lazy(node, start, end);

	if (right < start || end < left)
		return;
	if (left <= start && end <= right) {
		tree[node] = (end - start + 1) - tree[node];
		if (start != end) {
			lazy[node * 2] = 1 - lazy[node * 2];
			lazy[node * 2 + 1] = 1 - lazy[node * 2 + 1];
		}
		return;
	}

	int mid = (start + end) / 2;

	update_range(left, right, node * 2, start, mid);
	update_range(left, right, node * 2 + 1, mid + 1, end);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int left, int right, int node, int start, int end) {

	update_lazy(node, start, end);

	if (right < start || end < left)
		return 0;
	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return query(left, right, node * 2, start, mid) + query(left, right, node * 2 + 1, mid + 1, end);
}

int main() {

	scanf("%d %d", &n, &m);

	while (m--) {
		scanf("%d %d %d", &o, &s, &t);
		if (o == 0) {
			update_range(s, t, 1, 1, n);
		}
		else if (o == 1) {
			printf("%d\n", query(s, t, 1, 1, n));
		}
	}
}
