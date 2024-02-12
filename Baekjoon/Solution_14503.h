#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int T, M, N, K, B, W, L, R, C, D;
int ans = 0;


int m[60][60];

// dy, dx
// 0 = 북, 1 = 동, 2 = 남, 3 = 서 
int offset[4][2] = {
	// dy, dx
	{  -1,	0},
	{	0,	1},
	{	1,	0},
	{	0, -1},
};

// 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
//
// 2.현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
//		바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
//		바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
//
// 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
//		반시계 방향으로 90도 회전한다.
//		바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
//		1번으로 돌아간다.

// 0 = 아직 청소 안된 구역, 1 = 벽, 2 = 청소완료
void Sol(int row, int col, int dir)
{
	while (true)
	{
		// 1번
		if (m[row][col] == 0)
		{
			m[row][col] = 2;
			++ans;
		}

		// 3번
		bool flag = false;

		for (int i = 0; i < 4; ++i)
		{
			// 반시계 방향으로 회전
			dir = (dir + 4 - 1) % 4;

			int nextRow = row + offset[dir][0];
			int nextCol = col + offset[dir][1];

			if (m[nextRow][nextCol] == 0)
			{
				row = nextRow;
				col = nextCol;
				flag = true;
				break;
			}
		}
		// 청소할 곳이 있었음. 1번으로
		if (flag)
			continue;
		// 청소할 곳이 없었음. 2번으로
		else
		{
			// 후진 방향
			int BackDir = (dir + 4 - 2) % 4;

			int BackRow = row + offset[BackDir][0];
			int BackCol = col + offset[BackDir][1];

			// 후진할 수 있다면(인덱스 범위 안, 벽 x)
			if (BackRow >= 0 && BackCol >= 0 && m[BackRow][BackCol] != 1)
			{
				// 후진, 방향은 바뀌지 않음;
				row = BackRow;
				col = BackCol;
				continue;
			}
			// 후진할 수 없다면
			else
			{
				// 종료
				break;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// N x M
	cin >> N >> M;

	// Row, Col, Dir
	cin >> R >> C >> D;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> m[i][j];
		}
	}

	Sol(R, C, D);

	cout << ans;


	return 0;
}

