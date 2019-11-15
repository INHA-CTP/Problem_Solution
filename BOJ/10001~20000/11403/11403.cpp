/*
    JIHOON BAE
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int N,M;
int map[401][401];

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 1 ; i <= N ; i++){
        for(int j= 1 ; j <= N ; j++){
            int a;
            scanf("%d", &a);
            if(a == 0){
                map[i][j] = INF;
                continue;
            }
            map[i][j] = a;
        }
    }

    for(int k = 1 ; k <= N ; k++){
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1; j <= N ; j++){
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }


    for(int i = 1 ; i <= N ; i++){
        for(int j= 1 ; j <= N ; j++){
            printf("%d ", map[i][j] == INF ? 0 : 1);
        }
        puts("");
    }
}