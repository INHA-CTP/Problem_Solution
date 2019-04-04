/*
	author: Ji Hoon, Bae
	date: 19.04.04
*/

#include <cstdio>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	int tc;
	scanf("%d", &tc);
	while(tc--){
		priority_queue<int> maxpq;
		priority_queue<int, vector<int>, greater<int> > minpq;
		map<int, int> mp;

		int N;
		scanf("%d", &N);
		for(int i = 0 ; i < N ; i++){
			getchar();
			char q = getchar();
			int number;
			scanf("%d", &number);
			if(q == 'I'){
				maxpq.push(number);
				minpq.push(number);
				mp[number]++;
			}else if(q == 'D'){
				if(number == 1){
					while(!maxpq.empty() && mp[maxpq.top()] == 0){
						maxpq.pop();
					}
					if(!maxpq.empty()){
						mp[maxpq.top()]--;
						maxpq.pop();	
					}
				} else if(number == -1){
					while(!minpq.empty() && mp[minpq.top()] == 0){
						minpq.pop();
					}
					if(!minpq.empty()){
						mp[minpq.top()]--;
						minpq.pop();	
					}
				}
			}
		}

		while(!maxpq.empty() && mp[maxpq.top()] == 0){
			maxpq.pop();
		}
		while(!minpq.empty() && mp[minpq.top()] == 0){
			minpq.pop();
		}

		if(maxpq.empty()){
			printf("EMPTY\n");
		}else{
			printf("%d %d\n", maxpq.top(), minpq.top());
		}
	}
}