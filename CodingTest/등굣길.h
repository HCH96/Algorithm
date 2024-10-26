#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

    for (int i = 0; i < puddles.size(); ++i)
    {
        dp[puddles[i][0]][puddles[i][1]] = -1;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (i == 1 && j == 1)
            {
                dp[i][j] = 1;
                continue;
            }

            if (dp[i][j] == -1)
                continue;

            long long up = dp[i - 1][j] == -1 ? 0 : dp[i - 1][j];
            long long left = dp[i][j - 1] == -1 ? 0 : dp[i][j - 1];

            dp[i][j] = (up + left) % 1000000007;
        }
    }

    answer = dp[n][m];

    return answer;
}