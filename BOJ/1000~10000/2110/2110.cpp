#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
int arr[200000];

int main()
{
    int N,C;
    scanf("%d %d",&N,&C);
    for(int i=0;i<N;i++)
        scanf("%d",arr+i);
    sort(arr,arr+N);
    int lo=arr[0],hi=arr[N-1];
    while(lo+1<hi)
    {
        int mid = (lo+hi)>>1;
        int cnt=1;
        int last=arr[0];
        for(int i=1;i<N;i++)
        {
            if(arr[i]-mid>=last)
            {
                cnt++;
                last=arr[i];
            }
        }
        if(cnt<C)
            hi=mid;
        else
            lo=mid;
    }
    printf("%d\n",lo);
    return 0;
}
