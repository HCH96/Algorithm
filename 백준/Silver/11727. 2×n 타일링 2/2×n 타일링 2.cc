#include <bits/stdc++.h>
#include <unordered_map>
#include <deque>

using namespace std;

int T, N, M, V, H, K;
//int diff[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
//int diff3d[6][3] = { {-1,0,0}, {1,0,0}, {0,-1,0}, {0,1,0}, {0,0,1},{0,0,-1} };

int dp[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= N; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] *2) % 10007;
	}

	cout << dp[N];

	return 0;
}
