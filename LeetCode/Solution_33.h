#pragma once

#include "pch.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx = -1;

        vector<int> tmp(nums.begin(), nums.end());
        sort(tmp.begin(), tmp.end());

        int left = 0;
        int right = tmp.size();

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (tmp[mid] < target)
            {
                left = mid + 1;
            }
            else if (tmp[mid] > target)
            {
                right = mid;
            }
            else 
            {
                idx = mid;
                break;
            }
        }

        if (idx == -1)
        {
            return -1;
        }

        int minVal = tmp[0];

        int ans = find(nums.begin(), nums.end(), minVal) - nums.begin();

        ans += idx;
        if (ans > tmp.size())
        {
            ans -= tmp.size();
        }
        
        return ans;
    }
};