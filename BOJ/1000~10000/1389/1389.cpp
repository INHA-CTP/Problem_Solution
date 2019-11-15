#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 1e9;

int N, M;
int map[101][101];

//1 베이스

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1; j <= N ; j++){
            if(i == j)
                continue;
            map[i][j] = INF;
        }
    }
    
    for(int i = 0; i < M ; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
        map[b][a] = 1;
    }

    for(int k = 1 ; k <= N ; k++){
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= N ; j++){
                if(i == j)
                    continue;
                if(map[i][k] + map[k][j] < map[i][j])
                    map[i][j] = map[i][k] + map[k][j] + 1;
            }
        }
    }

    // for(int i = 1 ; i <= N ; i++){
    //     for(int j = 1 ; j <= N ; j++){
    //         printf("%d ", map[i][j]);
    //     }
    //     puts("");
    // }

    vector<pair<int, int> > vt;
    for(int i = 1 ; i <= N ; i++){
        int ts = 0;
        for(int j = 1 ; j <= N ; j++){
            ts += map[i][j];
        }
        vt.push_back(make_pair(ts,i));
    }

    sort(vt.begin(), vt.end());
    // for(int i = 0 ; i < N ; i++)
    //     printf("%d %d\n", vt[i].first, vt[i].second);
    printf("%d", vt[0].second);
}
