#include <cstdio>
#include <algorithm>
using namespace std;

long long arr[10000];

int main()
{
    int K,N;
    scanf("%d %d",&K,&N);
    for(int i=0;i<K;i++)
    {
        scanf("%lld",arr+i);
    }
    sort(arr,arr+K);
    long long lo=0,hi=arr[K-1];
    while(lo+1<hi)
    {
        long long mid = (lo+hi)>>1;
        long long cnt=0;
        for(int i=0;i<K;i++)
        {
            cnt += arr[i]/mid;
        }
        if(cnt>=N)
            lo=mid;
        else
            hi=mid;
    }
    int cnt=0;
    for(int i=0;i<K;i++)
        cnt+=arr[i]/arr[K-1];
    if(cnt>=N)
        printf("%lld\n",arr[K-1]);
    else
        printf("%lld\n",lo);
    return 0;
}
