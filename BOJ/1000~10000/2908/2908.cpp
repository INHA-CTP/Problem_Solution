/*
	Author : Young Jo,An
	Date : 19.03.21
	Problem Number: 2908
	Problem Name: 상수
*/
#include <iostream>
using namespace std;

int main() {
    int a,b;
    cin>>a>>b;
    int c,d;
    c=a/100+((a%100)/10)*10+(a%10)*100;
    d=b/100+((b%100)/10)*10+(b%10)*100;
    cout<<(c>d ? c : d);
}