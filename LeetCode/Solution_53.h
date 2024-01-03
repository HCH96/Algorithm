#pragma once
#include "pch.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        vector<int> dp(nums.size(), 0);

        dp[0] = nums[0];

        for (int i = 1; i < dp.size(); ++i)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        }

        int ans = INT_MIN;
        for (int i = 0; i < dp.size(); ++i)
        {
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
