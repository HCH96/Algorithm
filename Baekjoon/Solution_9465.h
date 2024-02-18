#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int T, M, N, K, B;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T--)
	{
		cin >> N;

		vector<vector<int>> v(2, vector<int>(N));

		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> v[i][j];
			}
		}

		vector<vector<int>> dp(2, vector<int>(N));
		dp[0][0] = v[0][0];
		dp[1][0] = v[1][0];

		for (int col = 1; col < N; ++col)
		{
			int MaxFirst = dp[1][col - 1];
			int MaxSecond = dp[0][col - 1];

			if (col > 1)
			{
				MaxFirst = max(MaxFirst, dp[1][col - 2]);

				MaxSecond = max(MaxSecond, dp[0][col - 2]);
			}

			dp[0][col] = MaxFirst + v[0][col];
			dp[1][col] = MaxSecond + v[1][col];
		}

		int ans = 0;

		for (int j = 0; j < 2; ++j)
		{
			ans = max(ans, dp[j][N-1]);
		}

		cout << ans << endl;

	}

	return 0;
}

