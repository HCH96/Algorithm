#pragma once
#include "pch.h"

class Solution {
public:
    int BinarySearch(vector<int>& v, int left, int right, int target)
    {
        while (left < right)
        {
            int mid = (left + right) / 2;

            if (v[mid] < target)
            {
                left = mid + 1;
            }
            else if (v[mid] > target)
            {
                right = mid;
            }
            else
            {
                return mid;
            }

        }
        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {

        vector<int> ans;

        for (int i = 0; i < numbers.size(); ++i)
        {
            int tmp = BinarySearch(numbers, i + 1, numbers.size(), target - numbers[i]);
            if (tmp != -1)
            {
                ans.push_back(i + 1);
                ans.push_back(tmp + 1);
                return ans;
            }
        }

        return ans;
    }
};