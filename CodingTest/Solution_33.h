#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        vector<int> copy(nums.begin(), nums.end());
        sort(copy.begin(), copy.end());

        int left = 0;
        int right = copy.size();
        int ans = -1;

        while (left < right)
        {
            int mid = (left + right) / 2;

            if (target == copy[mid])
            {
                ans = mid;
                break;
            }

            if (target > copy[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        if (ans == -1)
            return ans;

        int rot = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == copy[0])
            {
                rot = i;
            }
        }

        ans = (rot + ans) % nums.size();

        return ans;
    }
};