#include <cstdio>
#include <string>
#include <map>
#include <iostream>

using namespace std;

int N,M;
map <string, int> mp1;
map <string, int> mp2;
map <string, int>::iterator it;

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N ; i++) {
        string str;
        cin>>str;
        mp1[str]++;
    }

    for(int i = 0 ; i < M ; i++) {
        string str;
        cin>>str;
        mp1[str]++;
    }

    for(it = mp1.begin(); it != mp1.end(); it++) {
        if(it->second == 2)
            mp2[it->first]++;
    }

    cout<<mp2.size()<<"\n";
    for(it = mp2.begin(); it != mp2.end(); it++) {
        cout<<it->first<<"\n";
    }
}