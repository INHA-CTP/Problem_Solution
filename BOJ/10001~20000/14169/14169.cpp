#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

typedef struct {
	int x, y, dir, cnt;
} info;

typedef pair<int, int> p;

int n, xl, yl, xb, yb;

vector<p> point;
vector<int> x, y;
vector<vector<int>> vt_x, vt_y;

set<p> disc, temp;

int get_idx(vector<int>& vt, int num) {
	return lower_bound(vt.begin(), vt.end(), num) - vt.begin();
}

int main() {

	scanf("%d %d %d %d %d", &n, &xl, &yl, &xb, &yb);

	int a, b;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		point.push_back({ a,b });
		temp.insert({ a,b });
		x.push_back(a);
		y.push_back(b);
	}

	if (xl == xb || yl == yb) {
		puts("0"); return 0;
	}

	point.push_back({ xb,yb });
	temp.insert({ xb,yb });
	x.push_back(xb);
	y.push_back(yb);

	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());

	sort(y.begin(), y.end());
	y.erase(unique(y.begin(), y.end()), y.end());

	vt_x.resize(x.size());
	vt_y.resize(y.size());

	for (int i = 0; i < n; i++) {
		a = point[i].first;
		b = point[i].second;

		vt_x[get_idx(x, a)].push_back(b);
		vt_y[get_idx(y, b)].push_back(a);
	}

	vt_x[get_idx(x, xb)].push_back(yb);
	vt_y[get_idx(y, yb)].push_back(xb);

	queue<info> qu;
	qu.push({ xl,yl,1,-1 });
	qu.push({ xl,yl,2,-1 });

	disc.insert({ xl,yl });

	int res = 0, flag = 0;

	while (qu.size()) {

		int hx = qu.front().x;
		int hy = qu.front().y;
		int dir = qu.front().dir;
		int cnt = qu.front().cnt;
		qu.pop();
		 
		if (hx == xb && hy == yb) {
			flag = 1; res = cnt; break;
		}

		int idx_x = get_idx(x, hx);
		int idx_y = get_idx(y, hy);

		int nx, ny;
		if (dir == 1) {
			for (int i = 0; i < vt_x[idx_x].size(); i++) {
				ny = vt_x[idx_x][i];
				if (disc.find({ hx,ny }) != disc.end() || temp.find({ hx,ny }) == temp.end()) continue;
				qu.push({ hx,ny, 2, cnt + 1 });
				disc.insert({ hx,ny });
			}
		}
		else {
			for (int i = 0; i < vt_y[idx_y].size(); i++) {
				nx = vt_y[idx_y][i];
				if (disc.find({ nx,hy }) != disc.end() || temp.find({ nx,hy }) == temp.end()) continue;
				qu.push({ nx,hy, 1, cnt + 1 });
				disc.insert({ nx,hy });
			}
		}
	}

	if (flag)
		printf("%d\n", res);
	else puts("-1");
}
