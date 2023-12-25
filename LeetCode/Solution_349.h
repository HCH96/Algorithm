#pragma once

#include "pch.h"

class Solution {
public:
    bool BinarySearch(vector<int>& v, int left, int right, int target)
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
                return true;
            }

        }
        return false;
    }


    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;
        unordered_map<int, bool> m;

        sort(nums2.begin(), nums2.end());



        for (int i = 0; i < nums1.size(); ++i)
        {
            if (BinarySearch(nums2, 0, nums2.size(), nums1[i]) && m.count(nums1[i]) == 0)
            {
                ans.push_back(nums1[i]);
                m[nums1[i]] = true;
            }
        }

        return ans;
    }
};