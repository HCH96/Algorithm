#pragma once

#include "pch.h"

vector<vector<int>> ans;

void DFS(vector<int>& nums, unordered_map<int, bool>& visited, vector<int> tmp)
{
    if (tmp.size() == nums.size())
    {
        ans.push_back(tmp);
        return;
    }


    for (int i = 0; i < nums.size(); ++i)
    {
        if (visited[nums[i]] == false)
        {
            visited[nums[i]] = true;
            tmp.push_back(nums[i]);
            DFS(nums, visited, tmp);

            visited[nums[i]] = false;
            tmp.pop_back();
        }
    }
}


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();

        vector<int> tmp;
        unordered_map<int, bool> visited;

        DFS(nums, visited, tmp);

        return ans;
    }
};