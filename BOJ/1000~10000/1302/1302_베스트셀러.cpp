/*
	author: Ji Hoon, Bae
	date: 19.04.04
*/

#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int N;
map<string,int> mp;
vector<string > vt;

int main(){
	freopen("input.txt","r",stdin);
	scanf("%d", &N);
	for(int i = 0 ; i < N ; i++){
		string in;
		cin>>in;
		mp[in]++;
	}

	int maxCnt = -1;
	for(auto it = mp.begin() ; it != mp.end() ; it++)
		maxCnt = max(maxCnt, it->second);
	
	for(auto it = mp.begin() ; it != mp.end() ; it++)
		if(maxCnt == it->second){
			vt.push_back(it->first);
		}

	sort(vt.begin(), vt.end());
	cout<<vt[0];
}