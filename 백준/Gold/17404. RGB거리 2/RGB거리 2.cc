#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int T, N, K, W;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    vector<vector<int>> v(N, vector<int>(3));

    for (int i = 0; i < N; ++i)
    {
        int R, G, B;
        cin >> R >> G >> B;
        v[i][0] = R;
        v[i][1] = G;
        v[i][2] = B;
    }

    vector<vector<vector<int>>> dp(3,vector<vector<int>>(N, vector<int>(3, 1000000009)));

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (i == j)
                dp[i][0][j] = v[0][i];
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 1; j < N; ++j)
        {
            dp[i][j][0] = min(dp[i][j][0], dp[i][j - 1][1]+v[j][0]);
            dp[i][j][0] = min(dp[i][j][0], dp[i][j - 1][2]+v[j][0]);
            dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0]+v[j][1]);
            dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][2]+v[j][1]);
            dp[i][j][2] = min(dp[i][j][2], dp[i][j - 1][0]+v[j][2]);
            dp[i][j][2] = min(dp[i][j][2], dp[i][j - 1][1]+v[j][2]);
        }
    }

    int Answer = INT_MAX;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (i == j)
                continue;

            Answer = min(Answer, dp[i][N - 1][j]);
        }
    }

    cout << Answer;

	return 0;
}