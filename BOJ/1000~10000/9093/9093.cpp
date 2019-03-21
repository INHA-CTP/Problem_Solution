/*
	Author : Young Jo,An
	Date : 19.03.21
	Problem Number: 9093
	Problem Name: 단어 뒤집기
*/
#include <cstdio>
#include <cstring>

using namespace std;

char st[1000];
char c;
int main() 
{
	int n;
	scanf("%d",&n);
	while(scanf("%s",st)!=-1) {
		int len=strlen(st);
		for(int i=len-1;i>=0;i--) {
			printf("%c",st[i]);
		}
		scanf("%c",&c);
		printf("%c",c);
	}
}