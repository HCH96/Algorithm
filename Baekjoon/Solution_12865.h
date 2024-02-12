#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;
int N, K;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	vector<pair<int, int>> v;
	v.push_back({ 0,0 });

	vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));

	for (int i = 0; i < N; ++i)
	{
		int W, V;
		cin >> W >> V;
		v.push_back({ W,V });
	}

	for (int i = 1; i < K + 1; ++i)
	{
		for (int j = 1; j < N + 1; ++j)
		{
			int Weight = v[j].first;
			int Value = v[j].second;

			if (Weight <= i)
			{
				dp[i][j] = max(dp[i][j - 1], dp[i - Weight][j - 1] + Value);
			}
			else
			{
				dp[i][j] = dp[i][j - 1];
			}
		}
	}

	cout << dp[K][N];

	return 0;
}

