#include <cstdio>

using namespace std;

int N; 
bool arr[1001];

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    arr[0] = true;
    arr[1] = true;
    for(int i = 2 ; i < 1001 ; i++) {
        if(arr[i] == true)
            continue;
        for(int j = i * i ; j < 1001 ; j += i) {
            arr[j] = true;
        }
    }

    int ans = 0;
    for(int i = 0 ; i < N ; i++) {
        int k;
        scanf("%d", &k);
        if(arr[k] == false)
            ans++;
    }

    printf("%d", ans);
}