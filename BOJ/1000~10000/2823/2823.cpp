#include <cstdio>
#include <vector>

using namespace std;

int N,M;
char map[11][11];
vector<pair<int, int> > vt;
int cnt;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

bool isposs(int y, int x) {
    return y>=0 && x>=0 && y < N && x < M;
}

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N ,&M);
    for(int i = 0 ; i < N; i++){
        getchar();
        for(int j = 0 ; j < M ; j++) {
            scanf("%c", &map[i][j]);
            if(map[i][j] == '.'){
                vt.push_back(make_pair(i,j));
            }
        }
    }

    // for(int i = 0 ; i < N ; i++) {
    //     for(int j = 0 ; j < M ;j ++)
    //         printf("%c", map[i][j]);
        
    //     puts("");
    // }
    for(int i = 0 ; i < vt.size(); i++) {
        int y = vt[i].first;
        int x = vt[i].second;
        int temp = 0;
        for(int j = 0 ; j < 4; j++) {
            int yy = y + dy[j];
            int xx = x + dx[j];
            if(isposs(yy, xx) && map[yy][xx] == '.'){
                temp++;
            }
        }

        if(temp >= 2)
            cnt++;
    }
    printf("%d", cnt == vt.size() ? 0 : 1);
}
