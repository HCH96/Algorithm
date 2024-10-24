#pragma once

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {

        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i)
        {
            dp[i] = max(dp[i - 2] + 1, dp[i - 1] + 1);
        }

        return dp[n];
    }
};