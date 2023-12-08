#pragma once

#include "pch.h"

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {

		unordered_map<int, int> m;

		for (int i = 0; i < nums.size(); ++i)
		{
			m[nums[i]]++;
		}

		vector<pair<int, int>> v(m.begin(), m.end());

		sort(v.begin(), v.end(), [](pair<int, int>& m1, pair<int, int>& m2)->bool {return m1.second > m2.second; });


		vector<int> ans;

		for (int i = 0; i < k; ++i)
		{
			ans.push_back(v[i].first);
		}

		return ans;

	}
};