#include <cstdio>

using namespace std;

int N;
char map[101][101];

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        getchar();
        for(int j = 0 ; j < N ; j++) {
            scanf("%c", &map[i][j]);
        }
    }

    // see you soon
}