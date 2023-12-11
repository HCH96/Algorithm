#pragma once
#include "pch.h"

void DFS(vector<int>& nums,vector<vector<int>>& ans,vector<int>& tmp, int start)
{
    ans.push_back(tmp);
    
    if (tmp.size() == nums.size())
    {
        return;
    }

    for (int i = start; i < nums.size(); ++i)
    {
        tmp.push_back(nums[i]);
        DFS(nums, ans, tmp, i+1);
        tmp.pop_back();
    }
}


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> tmp;

        DFS(nums,ans,tmp, 0);

        return ans;
    }
};