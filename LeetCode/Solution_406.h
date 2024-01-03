#pragma once

#include "pch.h"

struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        if (a.first == b.first)
            return a.second > b.second;

        return a.first < b.first;
    }


};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        vector<vector<int>> ans;

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

        for (int i = 0; i < people.size(); ++i)
        {
            pq.push({ people[i][0], people[i][1]});
        }

        while (!pq.empty())
        {
            pair<int, int> p = pq.top();
            pq.pop();

            if (p.second >= ans.size())
            {
                ans.push_back({ p.first,p.second });
            }
            else
            {
                ans.insert(ans.begin() + p.second, { p.first,p.second });
            }

        }

        return ans;
    }
};