#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int T, N, M;

// ╩С, го, аб, ©Л
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	vector<string> v(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	queue<pair<int, int>> q;

	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			if (v[i][j] == 'I')
				q.push({ i,j });
		}
	}

	int ans = 0;

	while (!q.empty())
	{
		int CurRow = q.front().first;
		int CurCol = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NextRow = CurRow + dy[i];
			int NextCol = CurCol + dx[i];

			if (NextRow >= 0 && NextRow < N && NextCol >= 0 && NextCol < M)
			{
				if (v[NextRow][NextCol] == 'O')
				{
					v[NextRow][NextCol] = 'X';
					q.push({ NextRow,NextCol });
				}

				if (v[NextRow][NextCol] == 'P')
				{
					++ans;
					v[NextRow][NextCol] = 'X';
					q.push({ NextRow,NextCol });
				}

			}
		}
	}

	if (ans == 0)
	{
		cout << "TT";
	}
	else
	{
		cout << ans;
	}


	return 0;
}