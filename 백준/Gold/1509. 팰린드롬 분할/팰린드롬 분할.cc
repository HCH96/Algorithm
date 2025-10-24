#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int T, N, M, K, W, R, Q, S, G, P;

int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int Size = s.size();

    vector<vector<bool>> dp(Size, vector<bool>(Size, 0));

    for (int i = 0; i < Size; ++i)
    {
        for (int j = i; j >= 0; --j)
        {
            if (s[i] != s[j])
                continue;

            int len = i - j + 1;
            if (len <= 2) dp[j][i] = true;
            else
                dp[j][i] = dp[j + 1][i - 1];

        }
    }

    vector<int> dp2(Size,INT_MAX);

    for (int i = 0; i < Size; ++i)
    {
        if (i == 0)
        {
            dp2[i] = 1;
        }
        else
        {
            if (dp[0][i] == 1)
            {
                dp2[i] = 1;
            }
            else
            {
                for (int j = 1; j <= i; ++j)
                {
                    if (dp[j][i] == 1)
                    {
                        dp2[i] = min(dp2[i], dp2[j - 1] + 1);
                    }
                }
            }
        }
    }

    cout << dp2[Size - 1];


    return 0;
}