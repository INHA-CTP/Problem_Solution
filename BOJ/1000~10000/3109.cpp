#include <cstdio>
using namespace std;

int N, M;
char board[10000][501];
bool visit[10000][500];
int dx[3] = { -1,0,1 };
int dy[3] = { 1,1,1 };
int ans;

bool dfs(int x, int y)
{
	visit[x][y] = true;
	if (y == M - 1)
		return true;
	bool flag = false;
	for (int i = 0; i < 3; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny]||board[nx][ny]=='x')
			continue;
		else
		{
			flag=dfs(nx, ny);
			if (flag)
				return true;
		}
	}
	return false;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", board[i]);
	}
	for(int i=0;i<N;i++)
		ans+=dfs(i, 0);
	printf("%d\n", ans);
	return 0;
}
