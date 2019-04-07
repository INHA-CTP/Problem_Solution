/*
	author: Hyeoung Dong, Choi
	date: 19.04.04
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
int result = -1;
int arr[16][2];

void calc(int index , int val)
{
    if(index ==N && arr[index][0] ==1)
        result = max(result, val + arr[index][1]);
    
    
    if(index + arr[index][0] >N)
    {
        if(index + arr[index][0] -1 == N)
            result = max(result, val + arr[index][1]);
        else
            result = max(result,val);
        return;
    }

    for(int i=index + arr[index][0]; i<=N; i++)
    {
         calc(i, val + arr[index][1]);
    }

    return;
}

int main()
{
    //freopen("input.txt","r",stdin);
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        cin>>arr[i][0]>>arr[i][1];
    }
    int ans =-1;
    for(int i=1; i<=N; i++)
    {
        calc(i,0);
        ans = max(result,ans);
        result = -1;
    }
    
    cout<<ans<<endl;

    return 0;
}