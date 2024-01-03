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

        // first : ���� �ֱٿ� ���� �ε��� , second : ���� ����
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
            // pq�� �ֻ��� ��Ұ� ���� ������ �� �� ���� �� ���� �̱�
            while (!pq.empty() && pq.top().first + n >= idx)
            {
                tmp.push_back(pq.top());
                pq.pop();
            }

            // ���� �� �ִ� ��Ұ� �ִٸ�
            if (!pq.empty())
            {
                pair<int, int> p = pq.top();
                pq.pop();

                // ���� ���Ҵٸ� �ٽ� pq�� �ֱ�
                if (p.second - 1 > 0)
                {
                    pq.push({ idx ,p.second - 1 });
                }
            }

            // tmp�� ���������� �ٽ� �־� ����
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