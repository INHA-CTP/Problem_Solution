#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

// 코인 사기, 코인 팔기, 그냥 넘어가기

ll N,M,ans;
ll val[20];

ll buyMaxCoinCnt (ll coinValue, ll nowMoney) {
    return nowMoney / coinValue;
}

ll restMoney (ll coinValue, ll nowMoney) {
    return nowMoney % coinValue;
}

ll sellCoin (ll coinValue, ll coinCnt) {
    return coinValue * coinCnt;
}

void solve(ll day, ll money, ll coin) {
    if(day == N) {
        if(coin != 0) {
            money += sellCoin(val[day - 1], coin);
        }
        ans = max(ans, money);
        return;
    } else {
        ll newCoinCnt = coin + buyMaxCoinCnt(val[day], money);
        ll newRestMoney = restMoney(val[day], money);
        // 코인 수
        solve(day + 1, newRestMoney, newCoinCnt);

        // coin이 있으면 코인 있는거 팔고 넘어가기
        if(coin != 0) {
            ll newMoney = sellCoin(val[day], coin) + money;
            solve(day + 1, newMoney, 0);
        }

        // 그냥 넘어가기
        solve(day + 1, money, coin);
    }
}

int main() {
    freopen("input.txt","r",stdin);
    scanf("%lld %lld", &N ,&M);
    for(ll i = 0 ; i < N ; i++) 
        scanf("%lld", &val[i]);
    solve(0, M, 0);

    printf("%lld", ans);
}