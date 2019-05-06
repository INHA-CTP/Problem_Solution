/*
Author : INSIK CHO
Date : 19.04.30
*/
#include <iostream>
#include <algorithm>
using namespace std;
int t;
pair<int, int> box[6];
//������ ���ڸ� �Ϸķ� �ִ� ���
int three(int i, int j, int k) {
	int w = box[i].first + box[j].first + box[k].first;
	int h = max(box[i].second, max(box[j].second, box[k].second));
	return w * h;
}
//�ΰ��� ���� ���� �ϳ��� ���ڰ� �ִ� ���
int twoonone(int i, int j, int k) {
	int w = max(box[i].second + box[j].second, box[k].second);
	int h = max(box[i].first, box[j].first) + box[k].first;
	return w * h;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < 3; i++) {
			scanf("%d%d", &box[i].first, &box[i].second);
			//i+3 ���� 90�� ȸ����Ų ���ڸ� ǥ�� 
			box[i + 3].first = box[i].second;
			box[i + 3].second = box[i].first;
		}
		int r = 1e9;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				for (int k = 0; k < 6; k++) {
					// �������� ���ٸ� ���� ���ڸ� �� �� �ִ°��̹Ƿ� ��ŵ
					if (i % 3 == j % 3 || j % 3 == k % 3 || k % 3 == i % 3) continue;
					r = min(r, three(i, j, k));
					r = min(r, twoonone(i, j, k));
				}
			}
		}
		printf("%d\n", r);
	}
	return 0;
}