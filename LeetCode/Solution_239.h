#pragma once

#include "pch.h"

struct cmp
{
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        if (a.first == b.first)
            return a.second > b.second;

        return a.first < b.first;
    }

};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;

        // value, index
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            pq.push({ nums[i],i });
            
            if (i >= k - 1)
            {
                while (pq.top().second <= i - k)
                {
                    pq.pop();
                }

                ans.push_back(pq.top().first);
            }
        }

        return ans;
    }
};