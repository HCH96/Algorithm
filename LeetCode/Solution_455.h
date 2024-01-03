#pragma once
#include "pch.h"

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int ans = 0;
        int idx = 0;

        for (; ans < g.size() && idx < s.size();)
        {
            if (g[ans] <= s[idx])
            {
                ++ans;
            }
            ++idx;
        }

        return ans;
    }
};