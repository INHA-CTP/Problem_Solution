/*
	Author : Young Jo,An
	Date : 19.03.20
	Problem Number: 11718
	Problem Name: 그대로 출력하기
*/
#include <iostream>
using namespace std;

int main() { 
	char c;
	//scanf -1 반환시 입력의끝(EOF) 의미
	while (scanf("%c", &c) != -1) {
		printf("%c", c);
	}
}