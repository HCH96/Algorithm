#pragma once
#include "pch.h"

struct cmp
{
    bool operator()(pair<int, int>& a, pair<int, int>& b)
    {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> m;
        for (int i = 0; i < tasks.size(); ++i)
        {
            ++m[tasks[i]];
        }

        // first : 가장 최근에 넣은 인덱스 , second : 남은 개수
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

        unordered_map<char, int>::iterator iter = m.begin();
        for (; iter != m.end(); ++iter)
        {
            pq.push({ -101,iter->second });
        }

        vector<pair<int, int>> tmp;

        int idx = 0;

        while (!pq.empty())
        {
            // pq의 최상위 요소가 현재 순서에 들어갈 수 있을 때 까지 뽑기
            while (!pq.empty() && pq.top().first + n >= idx)
            {
                tmp.push_back(pq.top());
                pq.pop();
            }

            // 넣을 수 있는 요소가 있다면
            if (!pq.empty())
            {
                pair<int, int> p = pq.top();
                pq.pop();

                // 아직 남았다면 다시 pq에 넣기
                if (p.second - 1 > 0)
                {
                    pq.push({ idx ,p.second - 1 });
                }
            }

            // tmp에 꺼내놓은것 다시 넣어 놓기
            for (int i = 0; i < tmp.size(); ++i)
            {
                pq.push(tmp[i]);
            }
            tmp.clear();

            ++idx;
        }

        return idx;
    }
};