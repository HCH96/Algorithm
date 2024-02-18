#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int R, C, T;

int m[50][50];
int tmp[50][50];

// 상, 하, 좌, 우
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

// 우, 상, 좌, 하
int dir_upper[4] = { 3, 0, 2, 1 };
// 우, 하, 좌, 상
int dir_lower[4] = { 3, 1, 2, 0 };

// 먼지 1개 퍼트리기
void spread_instance(int row, int col)
{
	// 퍼트릴 양
	int amount = m[row][col] / 5;

	for (int i = 0; i < 4; ++i)
	{
		int y = row + dy[i];
		int x = col + dx[i];

		// 인덱스 범위 내, 공기 청정기가 없으면
		if (y >= 0 && y < R && x >= 0 && x < C && m[y][x] != -1)
		{
			// 누적
			tmp[y][x] += amount;
			tmp[row][col] -= amount;
		}
	}
}

// 먼지 퍼트리기
void spread()
{
	// 누적 배열 초기화
	memset(tmp, 0, sizeof(tmp));

	// 누적 배열 채우기
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (m[i][j] > 0)
			{
				spread_instance(i, j);
			}
		}
	}

	// 누적 배열 더하기
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (tmp[i][j] != 0)
			{
				m[i][j] += tmp[i][j];
			}
		}
	}
}

// 공기 청정기
void clean(vector<pair<int, int>>& cleaner)
{
	// upper
	int r = cleaner[0].first;
	int c = cleaner[0].second;

	// 초기 방향
	int idx = 0;
	int dir = dir_upper[idx];
	// 처음엔 공기청정기쪽에서 시작하니 0으로 세팅
	int prev = 0;

	do {
		// 다음 위치
		int y = r + dy[dir];
		int x = c + dx[dir];

		// 다음 위치가 유효하다면
		if (y >= 0 && y < R && x >= 0 && x < C)
		{
			int t = prev;
			prev = m[y][x];
			m[y][x] = t;
		}
		// 유효하지 않다면
		else
		{
			// 다음 방향으로(우, 상, 좌, 하)
			++idx;
			dir = dir_upper[idx];
			continue;
		}

		r = y;
		c = x;

	} while (r != cleaner[0].first || c != cleaner[0].second);

	// lower
	r = cleaner[1].first;
	c = cleaner[1].second;

	// 초기 방향
	idx = 0;
	dir = dir_lower[idx];
	// 처음엔 공기청정기쪽에서 시작하니 0으로 세팅
	prev = 0;

	do {
		// 다음 위치
		int y = r + dy[dir];
		int x = c + dx[dir];

		// 다음 위치가 유효하다면
		if (y >= 0 && y < R && x >= 0 && x < C)
		{
			int t = prev;
			prev = m[y][x];
			m[y][x] = t;
		}
		// 유효하지 않다면
		else
		{
			// 다음 방향으로(우, 하, 좌, 상)
			++idx;
			dir = dir_lower[idx];
			continue;
		}

		r = y;
		c = x;

	} while (r != cleaner[0].first || c != cleaner[0].second);


	// 사라진 공기 청정기 복구
	for (int i = 0; i < cleaner.size(); ++i)
	{
		m[cleaner[i].first][cleaner[i].second] = -1;
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<pair<int, int>> cleaner;

	cin >> R >> C >> T;

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			int n;
			cin >> n;
			m[i][j] = n;

			if (n == -1)
			{
				cleaner.push_back({ i,j });
			}
		}
	}

	while (T--)
	{
		spread();
		clean(cleaner);
	}

	int ans = 0;

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (m[i][j] == -1)
				continue;

			ans += m[i][j];
		}
	}

	cout << ans;


	return 0;
}

