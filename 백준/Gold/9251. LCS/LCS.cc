#include <bits/stdc++.h>

#define ll long long

using namespace std;

int N, M, K, V, X, V1, V2, A, B, C, E, T, W;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;

	vector<vector<int>> dp(s2.size(), vector<int>(s1.size(), 0));

	if (s1[0] == s2[0])
		dp[0][0] = 1;

	for (int i = 1; i < s1.size(); ++i)
	{
		if (s1[i] == s2[0])
			dp[0][i] = 1;

		dp[0][i] = max(dp[0][i], dp[0][i - 1]);
	}

	for (int i = 1; i < s2.size(); ++i)
	{
		if (s1[0] == s2[i])
			dp[i][0] = 1;

		dp[i][0] = max(dp[i][0], dp[i - 1][0]);
	}

	for (int i = 1; i < s2.size(); ++i)
	{
		for (int j = 1; j < s1.size(); ++j)
		{

			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

			if (s1[j] == s2[i])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			
		}
	}

	cout << dp[s2.size() - 1][s1.size() - 1];

	return 0;
}
