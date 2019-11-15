#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 60;
const int INF = 1e6;

int N,ans;
int c[MAX+1][MAX+1];
int f[MAX+1][MAX+1];
vector<vector<int> > map;

int makeInt(char c) {
    if('a' <= c && c <= 'z') 
        return c - 'a' + 26;
    else 
        return c - 'A';
}

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    map.resize(MAX+1);
    for(int i = 0 ; i < N ; i++) {
        char a,b;
        int aa, bb;
        int cap;
        getchar();
        scanf("%c %c %d", &a, &b, &cap);
        aa = makeInt(a);
        bb = makeInt(b);
        c[aa][bb] += cap;
        c[bb][aa] += cap;
        // printf("%c %c %d\n", a, b, c[aa][bb]);

        map[aa].push_back(bb);
        map[bb].push_back(aa);
    }

    int s = makeInt('A');
    int e = makeInt('Z');
    int pre[MAX+1];

    while(1) {
        memset(pre, -1, sizeof(pre));
        queue<int> qu;
        qu.push(s);

        while(qu.size() != 0 && pre[e] == -1) {
            int here = qu.front();
            qu.pop();
            for(int i = 0 ; i < map[here].size() ; i++) {
                int next = map[here][i];
                if(c[here][next] - f[here][next] > 0 && pre[next] == -1) {
                    qu.push(next);
                    pre[next] = here;
                    if(next == e)
                        break;
                }
            }
        }

        if(pre[e] == -1)
            break;
        
        int minFlowValue = INF;
        for(int i = e ; i != s ; i = pre[i]) {
            minFlowValue = min(minFlowValue, c[pre[i]][i] - f[pre[i]][i]);
        }

        for(int i = e ; i != s ; i = pre[i]) {
            f[pre[i]][i] += minFlowValue;
            f[i][pre[i]] -= minFlowValue;
        }
        ans += minFlowValue;
    }
    printf("%d", ans);
}