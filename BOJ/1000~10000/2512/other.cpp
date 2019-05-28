#include <cstdio>
#include <algorithm>
using namespace std;

int arr[10000];

int main()
{
    int N;
    scanf("%d",&N);
    int maxx=0;
    for(int i=0;i<N;i++)
    {
        scanf("%d",arr+i);
        maxx=max(maxx,arr[i]);
    }
    sort(arr,arr+N);
    int M;
    scanf("%d",&M);
    int lo=0,hi=maxx;
    while(lo<=hi)
    {
        int mid =(lo+hi)>>1;
        long long sum=0;
        for(int i=0;i<N;i++)
            sum+=(mid>=arr[i]?arr[i]:mid);
        if(sum<=M)
            lo=mid+1;
        else
            hi=mid-1;
    }
    printf("%d\n",hi);
    return 0;
}
