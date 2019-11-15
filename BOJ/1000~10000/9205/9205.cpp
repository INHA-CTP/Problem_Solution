#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
const int INF = 1e9;
int N;


int main() {
    freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d", &N);
        int x[102], y[102], map[102][102];
        for(int i = 0 ; i < N+2 ; i++){
            int a,b;
            scanf("%d %d", &a, &b);
            x[i] = a;
            y[i] = b;
        }

        for(int i = 0 ; i < N+2 ; i++){
            for(int j = 0 ; j < N+2; j++) {
                int dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
                map[i][j] = dist <= 1000 ? 1 : INF;
            }
        }

        for(int k = 0 ; k < N+2; k++){
            for(int i = 0 ; i < N+2; i ++){
                for(int j = 0 ; j < N+2; j++){
                    map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
                }
            }
        }
        printf("%s\n", map[0][N+1] == INF ? "sad" : "happy");
    }
}