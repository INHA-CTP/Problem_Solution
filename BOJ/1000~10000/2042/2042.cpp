#include <cstdio>

typedef long long ll;

const ll MAX = 1e6;

ll n, m, k;
ll tree[MAX * 4 + 1];

ll update(ll pos, ll cost, ll node, ll start, ll end) {

	if (pos < start || end < pos) return tree[node];
	if (start == end) return tree[node] = cost;

	ll mid = (start + end) / 2;
	return tree[node] = update(pos, cost, node * 2, start, mid) + update(pos, cost, node * 2 + 1, mid + 1, end);
}

ll query(ll left, ll right, ll node, ll start, ll end) {

	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return tree[node];

	ll mid = (start + end) / 2;
	return query(left, right, node * 2, start, mid) + query(left, right, node * 2 + 1, mid + 1, end);
}

int main() {

	scanf("%lld %lld %lld", &n, &m, &k);

	ll a, b, c;
	for (ll i = 0; i < n; i++) {
		scanf("%lld", &a);
		update(i + 1, a, 1, 1, n);
	}

	ll qs = m + k;
	while (qs--) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1) {
			update(b, c, 1, 1, n);
		}
		else {
			printf("%lld\n", query(b, c, 1, 1, n));
		}
	}
}
