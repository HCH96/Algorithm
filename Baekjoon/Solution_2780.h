#pragma once
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int T, N;

int dp[1001][4][3];

// ╩С, го, аб, ©Л
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	vector<int> n;
	int maxi = 0;

	for (int i = 0; i < T; ++i)
	{
		cin >> N;
		n.push_back(N);
		maxi = max(N, maxi);
	}

	int* pInt = &dp[1][0][0];
	for (int i = 0; i < 10; ++i)
	{
		*(pInt + i) = 1;
	}

	for (int i = 2; i <= maxi; ++i)
	{
		for (int row = 0; row < 4; ++row)
		{
			for (int col = 0; col < 3; ++col)
			{
				if (row == 3 && (col == 1 || col == 2))
					continue;

				int sum = 0;

				for (int k = 0; k < 4; ++k)
				{
					int ny = row + dy[k];
					int nx = col + dx[k];

					if (ny >= 0 && ny < 4 && nx >= 0 && nx < 3)
					{
						if (ny == 3 && (nx == 1 || nx == 2))
							continue;
						else
							sum += dp[i - 1][ny][nx];
					}
				}

				dp[i][row][col] = sum % 1234567;
			}
		}
	}

	for (int i = 0; i < T; ++i)
	{
		int ans = 0;
		int Cur = n[i];

		int* pInt = &dp[Cur][0][0];

		for (int i = 0; i < 10; ++i)
		{
			ans += *(pInt + i);
		}

		ans %= 1234567;

		cout << ans << endl;
	}

	return 0;
}