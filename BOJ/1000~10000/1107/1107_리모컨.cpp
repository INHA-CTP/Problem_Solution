/*
Author : INSIK CHO
Date : 19.04.30
*/
#include <iostream>
#include <algorithm>
using namespace std;

bool button[10];
int n, m, current = 100, answer, calculate_sum;
//Ư�� ä���� ���峪�� ���� ���� ��ư���θ� �� �� �ִ��� Ȯ��
//�� �� �ִٸ� ä���� �ڸ�����ŭ�� �����ָ� ��
int check_num (int temp) {
	if (!temp) {
		if (button[0]) return 0;
		else return 1;
	}
	int num_length = 0;
	while (temp) {
		if (button[temp % 10]) return 0;
		temp /= 10;
		num_length++;
	}
	return num_length;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		button[x] = 1;
	}
	//'+', '-' ��ư���θ� �̵����� ���� Ƚ��
	answer = abs(n - current);
	//���ϴ� ä�ΰ� ���� ����� ���ڹ�ư���θ� �� �� �ִ� ä���� Ž��
	for (int i = 0; i < 1000000; i++) {
		if (check_num(i)) {
			calculate_sum = abs(n - i) + check_num(i);
			answer = min(answer, calculate_sum);
		}
	}
	printf("%d\n", answer);
	return 0;
}