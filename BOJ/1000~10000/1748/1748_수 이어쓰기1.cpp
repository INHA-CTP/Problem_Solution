/*
	author: Hyeoung Dong, Choi
	date: 19.04.04
*/

#include <iostream>
#include <string>
using namespace std;

int N;
int result;
int main()
{
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        int cnt =0;
        int temp = i;
        while(temp != 0)
        {
            temp /= 10;
            cnt++;
        }
        result += cnt;
    }
    
    cout<<result<<endl;
    return 0;
}