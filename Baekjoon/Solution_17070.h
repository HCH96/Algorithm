#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int N;

int ans = 0;

// dir : 0 = ������, 1 = ������ �Ʒ�, 2 = �Ʒ�
void dfs(vector<vector<int>>& v, int row, int col, int dir)
{
	if (row == N - 1 && col == N - 1)
	{
		++ans;
		return;
	}

	// ������
	if (dir != 2 && col + 1 < N && v[row][col + 1] == 0)
	{
		dfs(v, row, col + 1, 0);
	}

	// ������ �Ʒ�
	if (col + 1 < N && row + 1 < N && v[row][col + 1] == 0 && v[row + 1][col] == 0 && v[row + 1][col + 1] == 0)
	{
		dfs(v, row + 1, col + 1, 1);
	}

	// �Ʒ�
	if (dir != 0 && row + 1 < N && v[row + 1][col] == 0)
	{
		dfs(v, row + 1, col, 2);
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	vector <vector<int>> v(N, vector<int>(N));

	// �Է�
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> v[i][j];
		}
	}

	dfs(v, 0, 1, 0);

	cout << ans;

	return 0;
}

// dp
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int N;

// 0 : ����, 1 : �밢��, 2 : ����
int dp[100][100][3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	vector<vector<int>> v(N, vector<int>(N));

	// �Է�
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> v[i][j];
		}
	}

	// dp �ʱⰪ
	dp[0][1][0] = 1;

	for (int i = 2; i < N; ++i)
	{
		if (v[0][i] == 0)
			dp[0][i][0] = dp[0][i - 1][0];
	}

	for (int i = 1; i < N; ++i)
	{
		for (int j = 2; j < N; ++j)
		{
			if (v[i][j] == 0)
			{
				// ����
				dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1];

				// ����
				dp[i][j][2] = dp[i - 1][j][1] + dp[i - 1][j][2];

				// �밢��
				if (v[i - 1][j] == 0 && v[i][j - 1] == 0)
					dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
			}
		}
	}

	int ans = dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];

	cout << ans;


	return 0;
}


