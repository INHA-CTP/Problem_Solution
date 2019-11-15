#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int N,map[20][20];
int dp[20][1<<17];
int nowState;
string firstState;

int main() {
    freopen("input.txt","r",stdin);
    memset(dp,-1,sizeof(dp));
    cin>>N;
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < N ; j++) {
            cin>>map[i][j];
        }
    }

    cin>>firstState;
    for(int i = 0 ; i < N; i++) {
        if(firstState[i] == 'Y') {
            nowState |= i;
        }
    }

    
}