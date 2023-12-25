#pragma once

#include "pch.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end(), [](vector<int>& first, vector<int>& second)->bool{
            if (first[0] == second[0])
                return first[1] < second[1];
            else
                return first[0] < second[0];
            });

        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 0; i < intervals.size(); ++i)
        {
            if (intervals[i][0] <= end && intervals[i][1] > end)
            {
                end = intervals[i][1];
            }
            else if (intervals[i][0] > end)
            {
                ans.push_back({ start,end });
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        ans.push_back({ start,end });

        return ans;
    }
};
