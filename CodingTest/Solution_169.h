#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Solution {

    

public:
    int count(vector<int>& nums, int left, int right, int target)
    {
        int cnt = 0;
        for (int i = left; i < right; ++i)
        {
            if (nums[i] == target)
                ++cnt;
        }

        return cnt;
    }


    int Sol(vector<int>& nums, int left, int right)
    {
        if (right-left <= 1)
            return nums[left];

        int mid = (left + right) / 2;

        int leftMax = Sol(nums, left, mid-1);
        int RightMax = Sol(nums, mid, right);

        int CntLeft = count(nums, left, right, leftMax);
        int CntRight = count(nums, left, right, RightMax);

        return CntLeft > CntRight ? CntLeft : CntRight;
    }


    int majorityElement(vector<int>& nums) {

        return Sol(nums, 0, nums.size());
    }
};