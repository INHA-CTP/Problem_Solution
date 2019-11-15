#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll N, total;
ll map[1001][1001];

ll func(ll mid) {
    ll sum = 0;
    for(ll i = 0 ; i < N ; i++) {
        for(ll j = 0 ; j < N ; j++) {
            if(mid >= map[i][j]) {
                sum += map[i][j];
            } else {
                sum += mid;
            }
        }
    }
    return sum;
}

ll solve(ll start, ll end) {
    ll base = (total / 2) + 0.5;
    ll ret = 1e10;
    while(start < end) {
        ll mid = (start + end) / 2;
        ll result = func(mid);
        if(base < result) {
            end = mid;
            ret = min(ret, mid);
        } else {
            start = mid + 1;
            
        }
    }
    return ret;
}

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(ll i = 0 ; i < N ; i++) {
        for(ll j = 0 ; j < N ; j++) {
            scanf("%d", &map[i][j]);
            total += map[i][j];
        }
    }

    // for(ll i = 0 ; i < N ; i++) {
    //     for(ll j = 0 ; j < N ; j++) {
    //         prllf("%d", map[i][j]);
    //     }
    //     puts("");
    // }

    printf("%d", solve(0, 10000000));
}