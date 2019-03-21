/*
	Author : Young Jo,An
	Date : 19.03.21
	Problem Number: 10820
	Problem Name: 문자열 분석
*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    string s;
    while(getline(cin,s)) {
        int l=0,u=0,d=0,p=0;
        for(int i=0;i<s.size();i++) {
            if(isupper(s[i])) {
                u++;
            } else if(islower(s[i])) {
                l++;
            } else if(isdigit(s[i])) {
                d++;
            } else {
                p++;
            }
        }
        cout<<l<<' '<<u<<' '<<d<<' '<<p<<'\n';
    }
}