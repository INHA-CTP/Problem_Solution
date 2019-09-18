#include <cstdio>

typedef long long ll;

const ll MAX = 1e6;

ll m, n, k, tree[MAX * 4], input[MAX * 4], lazy[MAX * 4];

ll init(ll node, ll start, ll end) {

	if (start == end)
		return tree[node] = input[start];

	ll mid = (start + end) / 2;
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update_lazy(ll node, ll start, ll end) {
	if (lazy[node] != 0) {
		tree[node] += (end - start + 1)*lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(ll left, ll right, ll node, ll start, ll end, ll diff) {

	update_lazy(node, start, end);
	if (right < start || end < left)
		return;

	if (left <= start && end <= right) {
		tree[node] += (end - start + 1)*diff;
		if (start != end) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}

	ll mid = (start + end) / 2;
	update_range(left, right, node * 2, start, mid, diff);
	update_range(left, right, node * 2 + 1, mid + 1, end, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll sum(ll left, ll right, ll node, ll start, ll end) {

	update_lazy(node, start, end);

	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return tree[node];

	ll mid = (start + end) / 2;
	return sum(left, right, node * 2, start, mid) + sum(left, right, node * 2 + 1, mid + 1, end);
}

int main() {

	scanf("%lld %lld %lld", &n, &m, &k);

	for (ll i = 1; i <= n; i++)
		scanf("%lld", &input[i]);

	init(1, 1, n);

	ll qs = m + k;
	ll a, b, c, d;
	while (qs--) {
		scanf("%lld", &a);
		if (a == 1) {
			scanf("%lld %lld %lld", &b, &c, &d);
			update_range(b, c, 1, 1, n, d);
		}
		else if (a == 2) {
			scanf("%lld %lld", &b, &c);
			printf("%lld\n", sum(b, c, 1, 1, n));
		}
	}
}
