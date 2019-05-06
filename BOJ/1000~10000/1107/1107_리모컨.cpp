/*
Author : INSIK CHO
Date : 19.04.30
*/
#include <iostream>
#include <algorithm>
using namespace std;

bool button[10];
int n, m, current = 100, answer, calculate_sum;
//특정 채널이 고장나지 않은 숫자 버튼으로만 갈 수 있는지 확인
//갈 수 있다면 채널의 자릿수만큼만 눌러주면 됨
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
	//'+', '-' 버튼으로만 이동했을 때의 횟수
	answer = abs(n - current);
	//원하는 채널과 가장 가까운 숫자버튼으로만 갈 수 있는 채널을 탐색
	for (int i = 0; i < 1000000; i++) {
		if (check_num(i)) {
			calculate_sum = abs(n - i) + check_num(i);
			answer = min(answer, calculate_sum);
		}
	}
	printf("%d\n", answer);
	return 0;
}