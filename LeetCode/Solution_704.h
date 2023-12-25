#pragma once
#include "pch.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int ans = -1;

        int left = 0;
        int right = nums.size();

        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid;
            }
            else
            {
                ans = mid;
                break;
            }
        }
        return ans;
    }
};