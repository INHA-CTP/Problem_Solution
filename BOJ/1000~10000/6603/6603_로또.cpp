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

	//���� �߿�
	vt.push_back(num[index]);	// vector.size�� 6�� �ɶ� ���� ä���ְ�
	dfs(vt, index + 1);		// 6�� �Ǹ� ���, 6�� �ƴ϶�� push_back
	vt.pop_back();			// vcetor�� ������ ���Ҹ� pop�ϰ�
	dfs(vt, index + 1);		//  �ε���++ �� �Է����� ���ڹ迭(num)�� �ε����� ������ 
					//  �� �̻� vector�� �߰����� �ʰ� �Ѵܰ� �� �ε����� ���� ������Ŵ
}
				 
int main() {
	while (scanf("%d", &m)) {
		if (m == 0) return 0;
		for (int i = 1; i <= m; i++)
			scanf("%d", &num[i]);
		vector<int> vt;
		dfs(vt, 1);		// �����ε����� 1�� ���ָ�
					// ���� �� �ε����� �����ϴ� �ͺ��� ���� ó�� ���� �����ϱ���� �����
		puts("");
	}
	return 0;
}