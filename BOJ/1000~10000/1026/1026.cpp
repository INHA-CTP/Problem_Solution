/*
	Author : Ji heon, Kim
	Date : 19.03.26
	Problem Number: 1026 
	Problem Name: 보물
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, sum, array1[51], array2[51];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> array1[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> array2[i];
    }
    
    sort(array1, array1 + N);
    sort(array2, array2 + N);

    for (int i = 0; i < N; i++) {
        sum += array1[i] * array2[N - i - 1];
    }
    cout << sum << endl;
}
