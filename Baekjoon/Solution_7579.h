#pragma once
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int N, M;

// row : cost, col : N
int dp[10001][101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	// Cost, Byte
	vector<pair<int, int>> v(N + 1);
	v.push_back({ 0,0 });

	for (int i = 1; i <= N; ++i)
	{
		cin >> v[i].second;
	}

	for (int i = 1; i <= N; ++i)
	{
		cin >> v[i].first;
	}

	// dp
	for (int i = 0; i < 10001; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int cost = v[j].first;
			int byte = v[j].second;

			if (i >= cost)
			{
				dp[i][j] = max(dp[i][j - 1], dp[i - cost][j - 1] + byte);
			}
			else
			{
				dp[i][j] = dp[i][j - 1];
			}

			if (dp[i][j] >= M)
			{
				cout << i;
				return 0;
			}

		}
	}


	return 0;
}