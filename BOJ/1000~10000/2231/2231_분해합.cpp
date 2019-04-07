/*
	author: Hyeoung Dong, Choi
	date: 19.04.04
*/

#include <iostream>
using namespace std;

int main()
{
    int N =0;
    int result =0;
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        int temp = i;
        int sum =0;
        sum += i;
        while(temp != 0)
        {
            sum += temp%10;
            temp /=10;
        }
        
        if(sum == N)
        {
            result = i;
            break;
        }
    }
    
    cout<<result<<endl;
}