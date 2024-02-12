#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int T, M, N, K, B;

// ╩С, го, аб, ©Л

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void BFS(vector<vector<bool>>& v, int row, int col)
{
	queue<pair<int, int>> q;

	v[row][col] = false;
	q.push({ row,col });

	while (!q.empty())
	{
		int row = q.front().first;
		int col = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NextRow = row + dy[i];
			int NextCol = col + dx[i];

			if (NextRow >= 0 && NextRow < N && NextCol >= 0 && NextCol < M && v[NextRow][NextCol])
			{
				v[NextRow][NextCol] = false;
				q.push({ NextRow,NextCol });
			}
		}
	}
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T--)
	{
		cin >> M >> N >> K;

		int ans = 0;

		vector<vector<bool>> v(N, vector<bool>(M, false));

		for (int i = 0; i < K; ++i)
		{
			int row, col;
			cin >> col >> row;

			v[row][col] = true;
		}

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (v[i][j])
				{
					BFS(v, i, j);
					++ans;
				}
			}
		}

		cout << ans << endl;

	}


	return 0;
}

