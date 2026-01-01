#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <unordered_set>

using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	vector<vector<long long>> dp(N+1, vector<long long>(10, 0));

	for (int i = 1; i < 10; ++i)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i < N + 1; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			long long count = 0;

			if (j > 0)
			{
				count += dp[i - 1][j - 1];
			}

			if (j < 9)
			{
				count += dp[i - 1][j + 1];
			}

			dp[i][j] = count % 1000000000;
		}
	}

	long long Answer = 0;

	for (int i = 0; i < 10; ++i)
	{
		Answer += dp[N][i];
		Answer = Answer % 1000000000;
	}

	cout << Answer;

	return 0;
}
