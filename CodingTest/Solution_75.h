#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int left = 0;
        int mid = 0;
        int right = nums.size() - 1;

        while (mid < right)
        {
            if (nums[mid] < 1)
            {
                swap(nums[mid], nums[left]);
                ++left;
                ++mid;
                continue;
            }

            if (nums[mid] > 1)
            {
                swap(nums[mid], nums[right]);
                --right;
                continue;
            }

            ++mid;
        }
    }
};