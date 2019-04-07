/*
	author: Hyeoung Dong, Choi
	date: 19.04.04
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int T;
int K;
int result[4000];
int arr[45];
bool check;



int main()
{
    //freopen("input.txt","r",stdin);
    cin>>T;
     for(int i=1; i<45; i++)
            arr[i] = i*(i+1)/2;
       
        for(int i=1; i<45; i++)
        {
            for(int j=i; j<45; j++)
            {
                for(int l = j; l<45; l++)
                {
                  result[arr[i] + arr[j] + arr[l]] =1;  
                }
            }
        }
    while(T--)
    {
        cin>>K;
        cout<<result[K]<<endl;

    }
   

    return 0;
}