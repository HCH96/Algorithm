#include <bits/stdc++.h>
#include <unordered_map>


using namespace std;

typedef long long ll;

int T, N, M;

// ╩С, го, аб, ©Л
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

bool m[26];
char v[20][20];

int cnt = 0;
int ans = 0;

void dfs(int row, int col)
{
	char cur = v[row][col];
	++cnt;

	if (cnt > ans)
		ans = cnt;

	for (int i = 0; i < 4; ++i)
	{
		int nextCol = col + dx[i];
		int nextRow = row + dy[i];

		if (nextCol >= 0 && nextRow >= 0 && nextCol < M && nextRow < N)
		{
			if (m[v[nextRow][nextCol] - 'A'] == false)
			{
				m[v[nextRow][nextCol] - 'A'] = true;
				dfs(nextRow, nextCol);
				m[v[nextRow][nextCol] - 'A'] = false;
			}
		}
	}

	--cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> v[i][j];
		}
	}

	m[v[0][0] - 'A'] = true;
	dfs(0, 0);

	cout << ans;

	return 0;
}