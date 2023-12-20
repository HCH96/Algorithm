#pragma once
#include "pch.h"

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        vector<int> ans;

        vector<vector<int>> v(n, vector<int>());
        vector<int> count(n, 0);

        for (int i = 0; i < edges.size(); ++i)
        {
            int first = edges[i][0];
            int second = edges[i][1];

            v[first].push_back(second);
            v[second].push_back(first);

            ++count[first];
            ++count[second];
        }

        queue<int> q;

        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i].size() == 1)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {   
            ans.clear();
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                int Cur = q.front();
                q.pop();
                ans.push_back(Cur);
                for (int j = 0; j < v[Cur].size(); ++j)
                {
                    if (--count[v[Cur][j]] == 1)
                    {
                        q.push(v[Cur][j]);
                    }
                }
            }

        }


        return ans;

    }
};
