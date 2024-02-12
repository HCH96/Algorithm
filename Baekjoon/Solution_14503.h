#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int T, M, N, K, B, W, L, R, C, D;
int ans = 0;


int m[60][60];

// dy, dx
// 0 = ��, 1 = ��, 2 = ��, 3 = �� 
int offset[4][2] = {
	// dy, dx
	{  -1,	0},
	{	0,	1},
	{	1,	0},
	{	0, -1},
};

// 1. ���� ĭ�� ���� û�ҵ��� ���� ���, ���� ĭ�� û���Ѵ�.
//
// 2.���� ĭ�� �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� ���� ���,
//		�ٶ󺸴� ������ ������ ä�� �� ĭ ������ �� �ִٸ� �� ĭ �����ϰ� 1������ ���ư���.
//		�ٶ󺸴� ������ ���� ĭ�� ���̶� ������ �� ���ٸ� �۵��� �����.
//
// 3. ���� ĭ�� �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� �ִ� ���,
//		�ݽð� �������� 90�� ȸ���Ѵ�.
//		�ٶ󺸴� ������ �������� ���� ĭ�� û�ҵ��� ���� �� ĭ�� ��� �� ĭ �����Ѵ�.
//		1������ ���ư���.

// 0 = ���� û�� �ȵ� ����, 1 = ��, 2 = û�ҿϷ�
void Sol(int row, int col, int dir)
{
	while (true)
	{
		// 1��
		if (m[row][col] == 0)
		{
			m[row][col] = 2;
			++ans;
		}

		// 3��
		bool flag = false;

		for (int i = 0; i < 4; ++i)
		{
			// �ݽð� �������� ȸ��
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
		// û���� ���� �־���. 1������
		if (flag)
			continue;
		// û���� ���� ������. 2������
		else
		{
			// ���� ����
			int BackDir = (dir + 4 - 2) % 4;

			int BackRow = row + offset[BackDir][0];
			int BackCol = col + offset[BackDir][1];

			// ������ �� �ִٸ�(�ε��� ���� ��, �� x)
			if (BackRow >= 0 && BackCol >= 0 && m[BackRow][BackCol] != 1)
			{
				// ����, ������ �ٲ��� ����;
				row = BackRow;
				col = BackCol;
				continue;
			}
			// ������ �� ���ٸ�
			else
			{
				// ����
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

