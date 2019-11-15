#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, cnt;
int map[30][30];
bool visited[30][30];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

vector<int> vt;

bool isposs(int y, int x) {
    return y>=0&&y<N&&x>=0&&x<N;
}

void dfs(int y, int x) {
    visited[y][x] = true;
    cnt++;
    for(int i = 0 ; i < 4 ; i++) {
        int yy = dy[i] + y;
        int xx = dx[i] + x;
        if(visited[yy][xx]) continue;
        if(!isposs(yy, xx)) continue;
        if(!map[yy][xx]) continue;
        dfs(yy,xx);
    }
}

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < N ; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    // for(int i = 0 ; i < N ; i++) {
    //     for(int j = 0 ; j < N ; j++) {
    //         printf("%d", map[i][j]);
    //     }
    //     puts("");
    // }

    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < N ; j++) {
            cnt = 0;
            if(map[i][j] && !visited[i][j]) {
                dfs(i, j);
                vt.push_back(cnt);
            }
        }
    }

    sort(vt.begin(), vt.end());
    printf("%d\n", vt.size());
    for(int i = 0 ; i < vt.size() ; i++){
        printf("%d\n", vt[i]);
    }
}