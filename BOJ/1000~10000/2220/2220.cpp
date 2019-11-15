#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1e5;

int N;
int arr[MAX+1];



int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    arr[1] = 1;
    for(int i = 2 ; i <= N ; i++) {
        arr[i] = i;
        int j = i - 1;
        swap(arr[i], arr[i-1]);

        while(j / 2 != 0) {
            int temp = j / 2;
            swap(arr[j], arr[temp]);
            j /= 2;
        }
    }

    for(int i = 1; i <= N ; i++) 
        printf("%d ", arr[i]);
}