#pragma once

#include "pch.h"

class Solution_15 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());


        for (int i = 0; i < nums.size()-2; ++i)
        {
            if (i>0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0)
                {
                    ans.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    ++left;
                    --right;

                    int leftVal = nums[left];
                    int rightVal = nums[right];

                    while (left < right && nums[left] == leftVal)
                        ++left;
                    while (left < right && nums[right] == rightVal)
                        --right;

                }
                else if (sum < 0)
                {
                    ++left;
                }
                else
                {
                    --right;
                }
            }
        }

        return ans;
    }
};