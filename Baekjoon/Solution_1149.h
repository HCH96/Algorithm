#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int T, N, M;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	vector<vector<int>> v(N);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			int tmp;
			cin >> tmp;
			v[i].push_back(tmp);
		}
	}

	vector<vector<int>> dp(N, vector<int>(3, 0));

	for (int i = 0; i < 3; ++i)
	{
		dp[0][i] = v[0][i];
	}

	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (j == 0)
			{
				dp[i][j] = v[i][j] + min(dp[i - 1][1], dp[i - 1][2]);
			}

			if (j == 1)
			{
				dp[i][j] = v[i][j] + min(dp[i - 1][0], dp[i - 1][2]);
			}

			if (j == 2)
			{
				dp[i][j] = v[i][j] + min(dp[i - 1][0], dp[i - 1][1]);
			}
		}
	}

	int ans = INT_MAX;

	for (int i = 0; i < 3; ++i)
	{
		if (dp[N - 1][i] < ans)
			ans = dp[N - 1][i];
	}

	cout << ans;

	return 0;
}

