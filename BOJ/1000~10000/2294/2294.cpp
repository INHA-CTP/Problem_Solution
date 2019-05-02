/*
	Author : JIHOON BAE
	Date : 19.05.02
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 98765421;

int N,K;
int coin[101];
int cache[100001]; // n을 만드는데 만드는 최소 갯수

int solve(int cost){
    if(cost == 0)
        return 0;

    int& ret = cache[cost];
    if(ret != -1)
        return ret;
    
    ret = INF;
    for(int i = N-1; i >= 0 ; i--){
        if(cost - coin[i] >= 0)
            ret = min(ret, solve(cost - coin[i]) + 1);
    }
    return ret;   
}

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &coin[i]);
    }
    memset(cache,-1,sizeof(cache));
    int ans = solve(K);
    printf("%d", ans == INF ? -1 : ans);
}