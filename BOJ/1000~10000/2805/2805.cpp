#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1000000];

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    int maxx=0;
    for(int i=0;i<N;i++)
    {
        scanf("%d",arr+i);
        maxx=max(maxx,arr[i]);
    }
    sort(arr,arr+N);
    int lo=0,hi=maxx;
    while(lo+1<hi)
    {
        int mid = (lo+hi)>>1;
        long long sum = 0;
        for(int i=0;i<N;i++)
            sum+=(arr[i]>mid?arr[i]-mid:0);
        if(sum>=M)
            lo=mid;
        else
            hi=mid;
    }
    printf("%d\n",lo);
    return 0;
}
