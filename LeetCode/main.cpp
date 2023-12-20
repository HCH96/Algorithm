#include "pch.h"
#include <iostream>

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        vector<int> ans;

        vector<vector<int>> v(n, vector<int>());
        vector<int> dist(n, -1);

        for (int i = 0; i < edges.size(); ++i)
        {
            int first = edges[i][0];
            int second = edges[i][1];

            v[first].push_back(second);
            v[second].push_back(first);
        }

        queue<int> q;

        // i ¹ø ³ëµå
        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i].size() == 1)
            {
                dist[i] = 0;
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int CurNode = q.front();
             q.pop();

            for (int i = 0; i < v[CurNode].size(); ++i)
            {
                int NextNode = v[CurNode][i];
                if (dist[NextNode] < dist[CurNode] + 1)
                {
                    dist[NextNode] = dist[CurNode] + 1;

                    if (v[NextNode].size() != 1)
                    {
                        q.push(NextNode);
                    }
                }
            }
        }

        int minVal = INT_MAX;
        for (int i = 0; i < dist.size(); ++i)
        {
            minVal = min(minVal, dist[i]);
        }


        for (int i = 0; i < dist.size(); ++i)
        {
            if (dist[i] == minVal)
            {
                ans.push_back(i);
                cout << i << endl;
            }
        }



        return ans;

    }
};
int main() {
    
    Solution s;

    vector<vector<int>> v = { {1,0},{1,2},{1,3} };

    s.findMinHeightTrees(4, v);

    return 0;
}