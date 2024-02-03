#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int T, N, M;

int ans = 0;

// ╩С, го , аб, ©Л
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };


void sol(vector<vector<int>> v)
{
	queue<pair<int, int>> q;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (v[i][j] == 2)
			{
				q.push({ i,j });
			}
		}
	}

	while (!q.empty())
	{
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NRow = row + dy[i];
			int NCol = col + dx[i];

			if (NRow >= 0 && NRow < N && NCol >= 0 && NCol < M && v[NRow][NCol] == 0)
			{
				v[NRow][NCol] = 2;
				q.push({ NRow,NCol });
			}
		}
	}

	int cnt = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (v[i][j] == 0)
				++cnt;
		}
	}


	ans = max(cnt, ans);
}


void dfs(int depth, int row, int col, vector<vector<int>> v)
{
	if (depth == 3)
	{
		sol(v);
		return;
	}

	for (int i = row; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (i == row && j < col)
				continue;

			if (v[i][j] == 0)
			{
				v[i][j] = 1;
				dfs(depth + 1, i, j, v);
				v[i][j] = 0;
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	vector<vector<int>> v(N, vector<int>(M));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> v[i][j];
		}
	}

	dfs(0, 0, 0, v);

	cout << ans;

	return 0;
}

