/*
	author: Hyeoung Dong, Choi
	date: 19.04.04
*/

#include <iostream>
using namespace std;

int N;
int arr[51][2];
int result[51];

int main()
{
    //freopen("input.txt","r",stdin);
    cin>>N;
    for(int i=0; i<N; i++)
    {
        int a,b=0;
        cin>>a>>b;
        arr[i][0] =a;
        arr[i][1] =b;
    }
  
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(i==j)
            continue;
            if(arr[i][0] > arr[j][0] && arr[i][1] > arr[j][1])
                result[j]++;
        }
    }

    for(int i=0; i<N; i++)
        cout<<result[i]+1<<" ";
        
}