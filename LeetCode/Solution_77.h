#pragma once

#include "pch.h"

vector<vector<int>> ans;
vector<int> tmp;


void DFS(int n, int k, int cur)
{
    if (tmp.size() == k)
    {
        ans.push_back(tmp);
        return;
    }

    for (int i = cur; i <= n; ++i)
    {
        tmp.push_back(i);
        DFS(n, k, i + 1);
        tmp.pop_back();
    }
}



class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        tmp.clear();

        DFS(n, k, 1);

        return ans;
    }
};