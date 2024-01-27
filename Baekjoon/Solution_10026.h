#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int T, N, M;

// �� �� �� ��
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void dfs(vector<string>& v, int row, int col, char c)
{
	v[row][col] = '#';

	for (int i = 0; i < 4; ++i)
	{
		int nextRow = row + dy[i];
		int nextCol = col + dx[i];

		if (nextRow >= 0 && nextRow < N && nextCol >= 0 && nextCol < N && v[nextRow][nextCol] == c)
		{
			dfs(v, nextRow, nextCol, c);
		}
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	vector<string> v(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	vector<string> copy(v);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{

			if (copy[i][j] == 'G')
				copy[i][j] = 'R';

		}
	}


	// ���ϻ��� x
	int cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (v[i][j] != '#')
			{
				dfs(v, i, j, v[i][j]);
				++cnt;
			}
		}
	}

	cout << cnt << " ";

	cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (copy[i][j] != '#')
			{
				dfs(copy, i, j, copy[i][j]);
				++cnt;
			}
		}
	}

	cout << cnt << " ";


	return 0;
}