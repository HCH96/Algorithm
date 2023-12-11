#pragma once

#include "pch.h"

bool ans;

void DFS(int cur, vector<int>& visited, unordered_map<int, vector<int>>& m)
{
    if (visited[cur] == 0)
    {
        visited[cur] = 1;
    }
    else if (visited[cur] == 1)
    {
        ans = false;
        return;
    }
    else
    {
        return;
    }

    const vector<int>& next = m[cur];

    for (int i = 0; i < next.size(); ++i)
    {
        DFS(next[i], visited, m);
    }

    visited[cur] = 2;
}

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        ans = true;

        vector<int> visited(numCourses, 0);
        unordered_map<int, vector<int>> m;

        for (int i = 0; i < prerequisites.size(); ++i)
        {
            int first = prerequisites[i][0];
            int second = prerequisites[i][1];

            m[first].push_back(second);
        }

        for (int i = 0; i < numCourses; ++i)
        {
            if (ans == true && visited[i] != 2)
            {
                DFS(i, visited, m);
            }
        }

        return ans;
    }
};