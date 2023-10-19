#pragma once
#include "pch.h"

class Solution_238 {
public:
	vector<int> productExceptSelf(vector<int>& nums) {

		vector<int> arr1(nums.size(), 1);
		vector<int> arr2(nums.size(), 1);

		for (int i = 1; i < arr1.size(); ++i)
		{
			arr1[i] = arr1[i - 1] * nums[i - 1];
		}

		for (int i = arr2.size() - 2; i >= 0; --i)
		{
			arr2[i] = arr2[i + 1] * nums[i + 1];
		}

		for (int i = 0; i < nums.size(); ++i)
		{
			nums[i] = arr1[i] * arr2[i];
		}
		return nums;
	}
};