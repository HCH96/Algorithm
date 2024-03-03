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

	vector<int> v(N);
	vector<int> dp(K + 1, INT_MAX);

	for (int i = 0; i < N; ++i)
	{
		int t;
		cin >> t;

		v[i] = t;
		dp[t] = 1;
	}

	for (int i = 1; i < K + 1; ++i)
	{
		for (int j = 0; j < v.size(); ++j)
		{
			// 현재 동전
			int Cur = v[j];

			if (Cur <= i && dp[i - Cur] != INT_MAX)
			{
				dp[i] = min(dp[i], dp[i - Cur] + 1);
			}
		}
	}

	if (dp[K] == INT_MAX)
	{
		cout << -1;
	}
	else
	{
		cout << dp[K];
	}

	return 0;
}
