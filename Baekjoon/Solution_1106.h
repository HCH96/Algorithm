#pragma once
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int C, N;
int dp[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> C >> N;

	vector<pair<int, int>> v;
	int ans = INT_MAX;

	for (int i = 0; i < N; ++i)
	{
		int cost, people;
		cin >> cost >> people;

		v.push_back({ cost, people });
	}

	for (int i = 1; i < 100001; ++i)
	{
		for (int j = 0; j < v.size(); ++j)
		{
			int cost = v[j].first;
			int people = v[j].second;

			int maxi = 0;

			if (i - cost >= 0)
			{
				maxi = max(dp[i - cost] + people, dp[i - 1]);
			}
			else
			{
				maxi = max(dp[i - 1], dp[i]);
			}

			dp[i] = max(dp[i], maxi);

			if (dp[i] >= C)
			{
				cout << i;
				return 0;
			}
		}
	}


	return 0;
}