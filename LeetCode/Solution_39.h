#pragma once

#include "pch.h"

void DFS(vector<int>& candidates, vector<int> tmp, int cur, int target, vector<vector<int>>& ans, int sum)
{
    if (sum == target)
    {
        ans.push_back(tmp);
        return;
    }

    if (sum > target)
    {
        return;
    }

    for (int i = cur; i < candidates.size(); ++i)
    {
        tmp.push_back(candidates[i]);
        DFS(candidates, tmp, i, target, ans, sum + candidates[i]);
        tmp.pop_back();
    }

}


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;

        DFS(candidates, tmp, 0, target, ans, 0);
        
        return ans;
    }
};