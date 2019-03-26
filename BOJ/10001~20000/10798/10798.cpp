/*
	Author : Ji heon, Kim
	Date : 19.03.26
	Problem Number: 10798 세로읽기
	Problem Name: 세로읽기
*/

#include <iostream>
#include <string>
using namespace std;

string a[5];

int main()
{
    for (int i = 0; i < 5; i++){
        getline(cin, a[i]);
    }
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 5; j++){
            if (a[j].length() > i)
                cout << a[j][i];
        }
    }
}