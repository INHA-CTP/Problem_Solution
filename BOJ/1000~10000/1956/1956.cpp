#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int N,M;
int map[401][401];

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N ,&M);

    for(int i = 1 ; i <= N ; i++){
        for(int j= 1 ; j <= N ; j++){
            // if(i == j) continue;
            map[i][j] = INF;
        }
    }
    
    for(int i = 0 ; i < M ; i++){
        int a,b,c;
        scanf("%d %d %d", &a,&b,&c);
        map[a][b] = c;
    }


    for(int k = 1 ; k <= N ; k++){
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1; j <= N ; j++){
                map[i][j] = min(map[i][j], map[i][k] +map[k][j]);
            }
        }
    }


    int ans = INF;
    for(int i = 1 ; i <= N ; i++){
        ans = min(ans, map[i][i]);
    }

    printf("%d", ans == INF ? -1 : ans);
}