#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int R, C, T;

int m[50][50];
int tmp[50][50];

// ��, ��, ��, ��
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

// ��, ��, ��, ��
int dir_upper[4] = { 3, 0, 2, 1 };
// ��, ��, ��, ��
int dir_lower[4] = { 3, 1, 2, 0 };

// ���� 1�� ��Ʈ����
void spread_instance(int row, int col)
{
	// ��Ʈ�� ��
	int amount = m[row][col] / 5;

	for (int i = 0; i < 4; ++i)
	{
		int y = row + dy[i];
		int x = col + dx[i];

		// �ε��� ���� ��, ���� û���Ⱑ ������
		if (y >= 0 && y < R && x >= 0 && x < C && m[y][x] != -1)
		{
			// ����
			tmp[y][x] += amount;
			tmp[row][col] -= amount;
		}
	}
}

// ���� ��Ʈ����
void spread()
{
	// ���� �迭 �ʱ�ȭ
	memset(tmp, 0, sizeof(tmp));

	// ���� �迭 ä���
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

	// ���� �迭 ���ϱ�
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

// ���� û����
void clean(vector<pair<int, int>>& cleaner)
{
	// upper
	int r = cleaner[0].first;
	int c = cleaner[0].second;

	// �ʱ� ����
	int idx = 0;
	int dir = dir_upper[idx];
	// ó���� ����û�����ʿ��� �����ϴ� 0���� ����
	int prev = 0;

	do {
		// ���� ��ġ
		int y = r + dy[dir];
		int x = c + dx[dir];

		// ���� ��ġ�� ��ȿ�ϴٸ�
		if (y >= 0 && y < R && x >= 0 && x < C)
		{
			int t = prev;
			prev = m[y][x];
			m[y][x] = t;
		}
		// ��ȿ���� �ʴٸ�
		else
		{
			// ���� ��������(��, ��, ��, ��)
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

	// �ʱ� ����
	idx = 0;
	dir = dir_lower[idx];
	// ó���� ����û�����ʿ��� �����ϴ� 0���� ����
	prev = 0;

	do {
		// ���� ��ġ
		int y = r + dy[dir];
		int x = c + dx[dir];

		// ���� ��ġ�� ��ȿ�ϴٸ�
		if (y >= 0 && y < R && x >= 0 && x < C)
		{
			int t = prev;
			prev = m[y][x];
			m[y][x] = t;
		}
		// ��ȿ���� �ʴٸ�
		else
		{
			// ���� ��������(��, ��, ��, ��)
			++idx;
			dir = dir_lower[idx];
			continue;
		}

		r = y;
		c = x;

	} while (r != cleaner[0].first || c != cleaner[0].second);


	// ����� ���� û���� ����
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

