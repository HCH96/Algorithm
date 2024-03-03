#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

// 상, 하, 좌, 우
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N;

int dp[500][500];
int m[500][500];

int ans;

void DFS(int y, int x)
{
	if (dp[y][x] != 0)
		return;

	int maxDepth = 0;

	for (int k = 0; k < 4; ++k)
	{
		int ny = y + dy[k];
		int nx = x + dx[k];

		// 범위 밖
		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;

		// 대나무 더 많지 않음
		if (m[ny][nx] <= m[y][x])
			continue;

		DFS(ny, nx);

		maxDepth = max(maxDepth, dp[ny][nx]);
	}

	dp[y][x] = maxDepth + 1;

	ans = max(ans, dp[y][x]);
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> m[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			DFS(i, j);
		}
	}

	cout << ans;

	return 0;
}
