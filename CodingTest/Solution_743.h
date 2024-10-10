#pragma once

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> m(n+1,vector<pair<int,int>>());
        vector<int> dist(n + 1, INT_MAX);

        // weight, node
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < times.size(); ++i)
        {
            int start = times[i][0];
            int end= times[i][1];
            int weight= times[i][2];

            m[start].push_back(make_pair(end, weight));
        }

        dist[k] = 0;
        pq.push({ 0,k });

        while (!pq.empty())
        {
            int CurWeight = -pq.top().first;
            int CurNode = pq.top().second;
            pq.pop();

            for (int i = 0; i < m[CurNode].size(); ++i)
            {
                int NextNode = m[CurNode][i].first;
                int NextWeight = m[CurNode][i].second;

                if (dist[NextNode] > CurWeight + NextWeight)
                {
                    dist[NextNode] = CurWeight + NextWeight;
                    pq.push({ -dist[NextNode] ,NextNode });
                }
            }
        }

        int ans = 0;

        for (int i = 1; i < n + 1; ++i)
        {
            if (dist[i] == INT_MAX)
            {
                return -1;
            }

            if (dist[i] > ans)
                ans = dist[i];
        }

        return ans;
    }
};
