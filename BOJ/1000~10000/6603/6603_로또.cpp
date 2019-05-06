/*
Author : INSIK CHO
Date : 19.04.30
*/
#include <iostream>
#include <iostream>
#include <vector>
using namespace std;
int m, n;
int num[15];

void dfs(vector<int>& vt, int index) {
	if (vt.size() == 6) {
		for (int i = 0; i < 6; i++)
			printf("%d ", vt[i]);
		puts("");
		return;	
	}
	if (index > m) 
		return;

	//순서 중요
	vt.push_back(num[index]);	// vector.size가 6이 될때 까지 채워주고
	dfs(vt, index + 1);		// 6이 되면 출력, 6이 아니라면 push_back
	vt.pop_back();			// vcetor의 마지막 원소를 pop하고
	dfs(vt, index + 1);		//  인덱스++ 가 입력해준 숫자배열(num)의 인덱스를 넘으면 
					//  더 이상 vector에 추가하지 않고 한단계 전 인덱스의 수를 증가시킴
}
				 
int main() {
	while (scanf("%d", &m)) {
		if (m == 0) return 0;
		for (int i = 1; i <= m; i++)
			scanf("%d", &num[i]);
		vector<int> vt;
		dfs(vt, 1);		// 시작인덱스를 1로 해주면
					// 가장 끝 인덱스만 수정하는 것부터 가장 처음 수를 수정하기까지 실행됨
		puts("");
	}
	return 0;
}