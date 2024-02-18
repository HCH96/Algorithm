#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int N, M, ans;

// 상, 하, 좌, 우
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int m[500][500], visited[500][500];

// ㅜ
void ShapeCheck1(int y, int x)
{
	// ㅜ
	if (y + 1 < N && x + 2 < M)
	{
		ans = max(ans, m[y][x] + m[y][x + 1] + m[y][x + 2] + m[y + 1][x + 1]);
	}

	// ㅓ
	if (y + 2 < N && x - 1 >= 0)
	{
		ans = max(ans, m[y][x] + m[y + 1][x] + m[y + 1][x - 1] + m[y + 2][x]);
	}

	// ㅗ
	if (y - 1 >= 0 && x + 2 < M)
	{
		ans = max(ans, m[y][x] + m[y][x + 1] + m[y][x + 2] + m[y - 1][x + 1]);
	}

	// ㅏ
	if (y + 2 < N && x + 1 < M)
	{
		ans = max(ans, m[y][x] + m[y + 1][x] + m[y + 1][x + 1] + m[y + 2][x]);
	}

}

// 나머지
void ShapeCheck2(int depth, int sum, int y, int x)
{
	if (depth == 3)
	{
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int row = y + dy[i];
		int col = x + dx[i];

		if (row >= 0 && row < N && col >= 0 && col < M && visited[row][col] == false)
		{
			visited[row][col] = true;
			ShapeCheck2(depth + 1, sum + m[row][col], row, col);
			visited[row][col] = false;
		}
	}
}

void sol(int row, int col)
{
	// ㅗ
	ShapeCheck1(row, col);

	// 나머지
	visited[row][col] = true;
	ShapeCheck2(0, m[row][col], row, col);
	visited[row][col] = false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> m[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			sol(i, j);
		}
	}

	cout << ans;

	return 0;
}
