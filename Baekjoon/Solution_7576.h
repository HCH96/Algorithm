#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;
int M, N;

// 상, 하, 좌, 우
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;

	vector<vector<int>> v(N, vector<int>(M));

	// v[0] : 날짜, v[1] : Row, v[2] : Col
	queue<vector<int>> q;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int tmp;
			cin >> tmp;
			v[i][j] = tmp;

			if (tmp == 1)
				q.push({ 0, i, j });
		}
	}

	int maxDay = 0;

	while (!q.empty())
	{
		int day = q.front()[0];
		int row = q.front()[1];
		int col = q.front()[2];

		maxDay = max(maxDay, day);

		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nextRow = row + dy[i];
			int nextCol = col + dx[i];

			if (nextRow >= 0 && nextCol >= 0 && nextRow < N && nextCol < M && v[nextRow][nextCol] == 0)
			{
				v[nextRow][nextCol] = 1;
				q.push({ day + 1,nextRow,nextCol });
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (v[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
		}
	}

	cout << maxDay;

	return 0;
}

