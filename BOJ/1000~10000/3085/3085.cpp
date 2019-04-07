/*
	author: Hyeoung Dong, Choi
	date: 19.04.04
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
char arr[51][51];
int mx = 0;

void Maxlength(int a, int b , char color)
{
    int cnt =1;   
    for(int i = b+1; i<N; i++)
    {
        if(arr[a][i] == color)
            cnt++;
        else
            break;   
    }

    for(int i=b-1; i>=0; i--)
    {
        if(arr[a][i] == color)
            cnt++;
        else
            break;
        
    }    
    mx = max(mx,cnt);
    cnt =1;

    for(int i = a+1; i<N; i++)
    {
        if(arr[i][b] == color)
            cnt++;
        else
            break;
        
    }
    for(int i = a-1; i>=0; i--)
    {
        if(arr[i][b] == color)
            cnt++;
        else
            break;
    }

    mx = max(mx,cnt);

}

int main()
{
    //freopen("input.txt","r",stdin);
    cin>>N;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            Maxlength(i,j,arr[i][j]);
        }
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(i<N-1 && arr[i][j] != arr[i+1][j])
            {   char temp = arr[i][j];
                arr[i][j] = arr[i+1][j];
                arr[i+1][j] = temp;
                Maxlength(i,j,arr[i][j]);
                arr[i+1][j] = arr[i][j];
                arr[i][j] = temp;
            }
            if(i>0 && arr[i][j] != arr[i-1][j])
            {
                char temp = arr[i][j];
                arr[i][j] = arr[i-1][j];
                arr[i-1][j] = temp;
                Maxlength(i,j,arr[i][j]);
                arr[i-1][j] = arr[i][j];
                arr[i][j] = temp;
            }
            if(j<N-1 && arr[i][j] != arr[i][j+1])
            {
                char temp = arr[i][j];
                arr[i][j] = arr[i][j+1];
                arr[i][j+1] = temp;
                Maxlength(i,j,arr[i][j]);
                arr[i][j+1] = arr[i][j];
                arr[i][j] = temp;
            }
            if(j>0 && arr[i][j] != arr[i][j-1])
            {
                char temp = arr[i][j];
                arr[i][j] = arr[i][j-1];
                arr[i][j-1] = temp;
                Maxlength(i,j,arr[i][j]);
                arr[i][j-1] = arr[i][j];
                arr[i][j] = temp;
            }

        }
    }
    
    cout<<mx<<endl;

    return 0;
}