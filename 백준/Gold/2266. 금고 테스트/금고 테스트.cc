#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <unordered_set>

using namespace std;

int N, K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;

	int Answer = -1;

	vector<vector<int>> dp(N + 1, (vector<int>(K + 1, 0)));
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= K; ++j)
		{
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + 1;

			if (dp[i][j] >= N)
			{
				Answer = i;
				break;
			}
		}

		if (Answer != -1)
		{
			break;
		}
	}

	cout << Answer;

	return 0;
}
