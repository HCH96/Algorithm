#pragma once
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int N;

void Sol(vector<int>& v)
{
	int n = v.size() - 1;

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	for (int l = 2; l <= n; ++l)
	{
		for (int i = 1; i <= n - l + 1; ++i)
		{
			int j = i + l - 1;
			dp[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; ++k)
			{
				int q = dp[i][k] + dp[k + 1][j] + v[i - 1] * v[k] * v[j];
				if (q < dp[i][j])
				{
					dp[i][j] = q;
				}
			}
		}
	}

	cout << dp[1][n];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	vector<int> v;

	for (int i = 0; i < 2; ++i)
	{
		int tmp;
		cin >> tmp;

		v.push_back(tmp);
	}

	for (int i = 0; i < N - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(b);
	}


	Sol(v);


	return 0;
}