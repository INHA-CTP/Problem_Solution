#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

const ll MAX = 1e18 + 10;
const ll SZ = 5e4 + 1;

ll n, maxd1[SZ], mind1[SZ], maxd2[SZ], mind2[SZ];
vector<p> vt;

// y좌표 기준 정렬을 위한 비교함수
bool comp(p& a, p& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {

	scanf("%lld", &n);

	ll a, b, t1 = MAX, t2 = -MAX;
	for (ll i = 0; i < n; i++) {

		scanf("%lld %lld", &a, &b);
		vt.push_back({ a,b });

		t1 = min(t1, b);
		t2 = max(t2, b);
	}

	// x좌표 기준 정렬
	sort(vt.begin(), vt.end());

	// 하나의 울타리만 만들 경우의 울타리 넓이
	ll origin = (vt.back().first - vt[0].first) * (t2 - t1);
	ll res = 0;

	// maxd1[i] = x좌표 기준 0 ~ i 까지의 y좌표값의 최댓값
	// mind1[i] = x좌표 기준 0 ~ i 까지의 y좌표값의 최솟값
	for (ll i = 0; i < vt.size(); i++) {
		if (i == 0) {
			maxd1[i] = vt[i].second;
			mind1[i] = vt[i].second;
		}
		else {
			maxd1[i] = max(maxd1[i - 1], vt[i].second);
			mind1[i] = min(mind1[i - 1], vt[i].second);
		}
	}

	// maxd2[i] = x좌표 기준 n-1 ~ i 까지의 y좌표값의 최댓값
	// mind2[i] = x좌표 기준 n-1 ~ i 까지의 y좌표값의 최솟값
	for (ll i = vt.size() - 1; i >= 0; i--) {
		if (i == vt.size() - 1) {
			maxd2[i] = vt[i].second;
			mind2[i] = vt[i].second;
		}
		else {
			maxd2[i] = max(maxd2[i + 1], vt[i].second);
			mind2[i] = min(mind2[i + 1], vt[i].second);
		}
	}

	ll temp1, temp2;

	// y축과 평행한 직선을 그어 두 개의 사각형으로 나누는 경우
	for (ll i = 0; i < n - 1; i++) {
		temp1 = maxd1[i] - mind1[i];
		temp2 = maxd2[i + 1] - mind2[i + 1];
		res = max(res, origin - temp1 * (vt[i].first - vt[0].first) - temp2 * (vt.back().first - vt[i + 1].first));
	}

	// y좌표 기준 정렬
	sort(vt.begin(), vt.end(), comp);

	// maxd1[i] = y좌표 기준 0 ~ i 까지의 x좌표값의 최댓값
	// mind1[i] = y좌표 기준 0 ~ i 까지의 x좌표값의 최솟값
	for (ll i = 0; i < vt.size(); i++) {
		if (i == 0) {
			maxd1[i] = vt[i].first;
			mind1[i] = vt[i].first;
		}
		else {
			maxd1[i] = max(maxd1[i - 1], vt[i].first);
			mind1[i] = min(mind1[i - 1], vt[i].first);
		}
	}

	// maxd2[i] = y좌표 기준 n-1 ~ i 까지의 x좌표값의 최댓값
	// mind2[i] = y좌표 기준 n-1 ~ i 까지의 x좌표값의 최솟값
	for (ll i = vt.size() - 1; i >= 0; i--) {
		if (i == vt.size() - 1) {
			maxd2[i] = vt[i].first;
			mind2[i] = vt[i].first;
		}
		else {
			maxd2[i] = max(maxd2[i + 1], vt[i].first);
			mind2[i] = min(mind2[i + 1], vt[i].first);
		}
	}

	// x축과 평행한 직선을 그어 두 개의 사각형으로 나누는 경우
	for (ll i = 0; i < n - 1; i++) {
		temp1 = maxd1[i] - mind1[i];
		temp2 = maxd2[i + 1] - mind2[i + 1];
		res = max(res, origin - temp1 * (vt[i].second - vt[0].second) - temp2 * (vt.back().second - vt[i + 1].second));
	}

	printf("%lld\n", res);
}
