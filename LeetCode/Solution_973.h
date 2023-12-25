#pragma once

#include "pch.h"

class Solution {
public:
    bool cmp(vector<int>& first, vector<int>& second)
    {
        int LengthFirst = pow(first[0], 2) + pow(first[1], 2);
        int LengthSecond = pow(second[0], 2) + pow(second[1], 2);

        return LengthFirst < LengthSecond;
    }


    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        
        sort(points.begin(), points.end(), cmp);

        for (int i = 0; i < k; ++i)
        {
            ans.push_back(points[i]);
        }

        return ans;
    }
};