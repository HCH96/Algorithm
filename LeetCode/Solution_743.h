#pragma once
#include "pch.h"

struct cmp
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
};


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<int> dist(n + 1, INT_MAX);

        // index = start, first = end, second = weight
        vector<vector<pair<int, int>>> edge(n + 1);

        for (auto& t : times)
        {
            edge[t[0]].push_back({ t[1],t[2] });
        }

        dist[k] = 0;

        // first = node, second = weight
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        q.push({ k,0 });

        while (!q.empty())
        {
            pair<int, int> Cur = q.top();
            q.pop();

            int CurNode = Cur.first;
            int CurWeight = Cur.second;

            for (int i = 0; i < edge[CurNode].size(); ++i)
            {
                int NextNode = edge[CurNode][i].first;
                int NextWeight = edge[CurNode][i].second + CurWeight;


                if (dist[NextNode] > NextWeight)
                {
                    dist[NextNode] = NextWeight;
                    q.push({ NextNode, NextWeight });
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; ++i)
        {
            if (dist[i] == INT_MAX)
            {
                ans = -1;
                break;
            }
            else
            {
                if (dist[i] > ans)
                {
                    ans = dist[i];
                }
            }
        }

        return ans;

    }
};