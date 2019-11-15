/*
    JIHOON BAE
*/

#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

vector<string> vt;
priority_queue<pair<int, pair<int, int> > > pq;

vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        internal.push_back(temp);
    }
 
    return internal;
}

void combinate (string str1, string str2, int i, int j) {
    int totalScore;
    int num1, num2;
    if('0' <= str1[0] && str1[0] <= '9')
        num1 = str1[0] - '0';
    else 
        num1 = str1[0] - 'a' + 10;

    if('0' <= str2[0] && str2[0] <= '9')
        num2 = str2[0] - '0';
    else 
        num2 = str2[0] - 'a' + 10;
    if((num1 + 1 == num2 || num1 - 1 == num2) || (num1 == 1 && num2 == 15) || (num1 == 15 && num2 == 1)) {
        totalScore += 3;
    } else if(num1 == num2) {
        totalScore += 2;
    } else {
        totalScore += 1;
    }
    totalScore *= 10;

    if(str1[1] == str2[1])
        totalScore += 2;
    else
        totalScore += 1;
    totalScore *= 100;

    if(num1 > num2) {
        totalScore += num1;
    } else 
        totalScore += num2;
    totalScore *= 100;

    if(num1 > num2) {
        totalScore += num2;
    } else 
        totalScore += num1;
    totalScore *= 10;

    if(num1 > num2 && str1[1] == 'b')
        totalScore += 2;
    else if(num1 < num2 && str2[1] == 'b')
        totalScore += 2;

    pq.push(make_pair(totalScore, make_pair(i, j)));
}


int main() {
    string str;
    cin>>str;
    vt = split(str, ',');

    for(int i = 0 ; i < 6 ; i++) {
        for(int j = i+1 ; j < 6 ; j++) {
            combinate(vt[i], vt[j], i, j);
        }
    }
    
    int size = pq.size();
    for(int i = 0 ; i < size ; i++) {
        int idx1 = pq.top().second.first;
        int idx2 = pq.top().second.second;
        pq.pop();

        cout<<vt[idx1]<<vt[idx2]<<"\n";
    }
}