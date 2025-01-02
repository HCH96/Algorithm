#include <bits/stdc++.h>
#include <unordered_map>
#include <deque>

using namespace std;

int T, N, M, V, H, K;
//int diff[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
//int diff3d[6][3] = { {-1,0,0}, {1,0,0}, {0,-1,0}, {0,1,0}, {0,0,1},{0,0,-1} };
//
//int arr[1000][1000];
long long dp[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i < 101; ++i)
	{
		dp[i] = dp[i - 2] + dp[i - 3];
	}
	
	while (T--)
	{
		cin >> N;

		cout << dp[N] << endl;
	}

	return 0;
}
