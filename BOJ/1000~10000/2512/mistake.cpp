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
    while(lo+1<hi)
    {
        int mid =(lo+hi)>>1;
        long long sum=0;
        for(int i=0;i<N;i++)
            sum+=(mid>=arr[i]?arr[i]:mid);
        if(sum<=M)
            lo=mid;
        else
            hi=mid;
    }
    int sum=0;
    for(int i=0;i<N;i++)
        sum+=(maxx>=arr[i]?arr[i]:maxx);
    if(sum<=M)
        printf("%d\n",maxx);
    else
        printf("%d\n",lo);
    return 0;
}
