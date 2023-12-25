#pragma once
#include "pch.h"

class Solution {
public:
    void swap(vector<int>& nums, int first, int second)
    {
        int tmp = nums[first];
        nums[first] = nums[second];
        nums[second] = tmp;
    }


    void sortColors(vector<int>& nums) {

        int left = 0;
        int mid = 0;
        int right = nums.size() - 1;

        int pivot = 1;

        while (mid <= right)
        {
            if (nums[mid] < pivot)
            {
                swap(nums, mid, left);
                ++mid;
                ++left;
            }
            else if (nums[mid] > pivot)
            {
                swap(nums, mid, right);
                --right;
            }
            else
            {
                ++mid;
            }


        }


    }
};