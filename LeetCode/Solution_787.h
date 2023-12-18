#pragma once

#include "pch.h"

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int, int>>> edge(n);

        for (const auto& f : flights)
        {
            edge[f[0]].emplace_back(f[1],f[2]);
        }

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        // get<0> : Cost, get<1> : Node, get<2> LeftMove
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;

        dist[src][k + 1] = 0;

        q.push({ dist[src][k + 1],src, k + 1 });

        while (!q.empty())
        {
            tuple<int, int, int> Cur = q.top();
            q.pop();

            int CurCost = get<0>(Cur);
            int CurNode = get<1>(Cur);
            int LeftMove = get<2>(Cur);


            if (CurNode == dst)
            {
                return CurCost;
            }

            if (LeftMove == 0)
                continue;

            for (int i = 0; i < edge[CurNode].size(); ++i)
            {
                int NextNode = edge[CurNode][i].first;
                int NextCost = edge[CurNode][i].second + CurCost;


                if (dist[NextNode][LeftMove - 1] > NextCost)
                {
                    dist[NextNode][LeftMove - 1] = NextCost;
                    q.push({ NextCost , NextNode, LeftMove - 1 });
                }
            }
        }

        return -1;

    }
};