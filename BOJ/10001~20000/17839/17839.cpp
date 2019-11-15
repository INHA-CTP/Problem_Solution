#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
map<string, vector<string> > mp;
map<string, int> visited;
// map<string, string>::iterator it;
vector<string> vt;

const string findValue = "Baba";

void dfs(string here) {
    // cout<<"dfs:" <<here<<"\n";
    if(here == "")
        return;
    auto it = mp.find(here);
    vector<string> nowVector = it->second;
    for(int i = 0 ; i < nowVector.size() ; i++) {
        string there = nowVector[i];
        if(there == "")
            continue;
        if(visited.find(nowVector[i])->second == 0 && mp.find(nowVector[i]) != mp.end()) {
            visited[there]++;
            vt.push_back(there);
            dfs(there);
        }
    }
}


int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        string a,is,b;
        cin>>a>>is>>b;
        // cout<<a<<" "<<is<<" "<<b<<endl;
        mp[a].push_back(b);
        mp[b].push_back("");
        visited[a] = 0;
        visited[b] = 0;
    }

    auto it = mp.find(findValue);
    if(it == mp.end()) {
        // printf("aa");
        return 0;
    }
        
    
    vector<string> BabeVector = it->second;
    for(int i = 0 ; i < BabeVector.size() ; i++)  {
        if(visited.find(BabeVector[i])->second == 0) {
            // cout<<BabeVector[i]<<endl;
            visited[BabeVector[i]]++;
            vt.push_back(BabeVector[i]);
            dfs(BabeVector[i]);
        }
    }
    // if(it == mp.end())
    //     return 0;
    
    // while(1) {
    //     if(it == mp.end()) {
    //         if(vt.size() == 0)
    //             return 0;
    //         break;
    //     }
            

    //     string nowValue = it->second;
    //     vt.push_back(nowValue);
    //     it = mp.find(nowValue);
    // }

    sort(vt.begin(), vt.end());
    // cout<<"size: "<<vt.size()<<endl;
    for(int i = 0 ; i < vt.size() ; i++) {
        if(vt[i] == "")
            continue;
        cout<<vt[i]<<"\n";
    }
        
}