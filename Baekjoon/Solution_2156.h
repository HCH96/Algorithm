#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int N, M;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	vector<int> v(N);
	vector<int> dp(N, 0);

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	dp[0] = v[0];
	dp[1] = v[0] + v[1];

	dp[2] = max(dp[1], dp[0] + v[2]);
	dp[2] = max(dp[2], v[1] + v[2]);

	for (int i = 3; i < N; ++i)
	{
		// i를 안마시는 경우
		dp[i] = max(dp[i - 1], dp[i]);

		// i를 마시고, i-1을 안마시는 경우
		dp[i] = max(dp[i - 2] + v[i], dp[i]);

		// i를 마시고, i-2를 안마시는 경우
		dp[i] = max(dp[i - 3] + v[i - 1] + v[i], dp[i]);
	}

	cout << dp[N - 1];


	return 0;
}
