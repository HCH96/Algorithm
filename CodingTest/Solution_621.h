#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        priority_queue<pair<char, int>> pq;
        map<char, int> m;
        int ans = 0;

        for (int i = 0; i < tasks.size(); ++i)
        {
            ++m[tasks[i]];
        }

        for (auto& it : m)
        {
            pq.push({ it.first,it.second });
        }

        while (!pq.empty())
        {
            int size = pq.size();

            for (int i = 0; i < n; ++i)
            {
                pair<char,int> Cur = pq.top();
                pq.pop();



            }


        }



    }
};