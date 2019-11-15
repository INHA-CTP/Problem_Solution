#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int N;
string six = "666";
vector<int> vt;


int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 666 ; i < 1e7 ; i++) {
        string str = to_string(i);
        if(str.find(six) != string::npos)
            vt.push_back(i);
    };
    printf("%d", vt[N-1]);
}