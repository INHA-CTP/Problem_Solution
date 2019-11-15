#include <cstdio>

using namespace std;


int N,M,arr[1000001];
bool visited[1000001];

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N ; i++) {
        getchar();
        for(int j = 0 ; j < M ; j++) {
            char in = getchar();
            int y,x;
            if(in == 'S') {
                y = i + 1;
                x = j;
            } else if (in == 'W') {
                y = i;
                x = j - 1;
            } else if (in == 'N') {
                y = i - 1;
                x = j;
            } else if (in == 'E') {
                y = i;
                x = j + 1;
            }
            arr[i * M + j] = y * M + x;
        }
    }


    
}