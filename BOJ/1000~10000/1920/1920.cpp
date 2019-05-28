#include <cstdio>
#include <algorithm>
using namespace std;

int arr[100000];

int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",arr+i);
    sort(arr,arr+N);
    int M;
    scanf("%d",&M);
    for(int i=0;i<M;i++)
    {
        int num;
        scanf("%d",&num);
        int lo=0,hi=N;
        while(lo+1<hi)
        {
            int mid = (lo + hi)>>1;
            if(arr[mid]>num)
                hi=mid;
            else
                lo=mid;
        }
        printf("%d\n",arr[lo]==num?1:0);
    }
    
    
    return 0;
}
