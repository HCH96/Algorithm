#pragma once

#include "pch.h"






class Solution {
public:
    vector<string> ans;

    void DFS(const string& Cur, unordered_map<string, multiset<string>>& m)
    {
        multiset<string>& s = m[Cur];

        while (!s.empty())
        {
            string next = *s.begin();
            s.erase(s.begin());
            DFS(next, m);
        }

        ans.insert(ans.begin(), Cur);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        // Key = From, Value = {To}
        unordered_map<string, multiset<string>> Edge;


        for (int i = 0; i < tickets.size(); ++i)
        {
            string first = tickets[i][0];
            string second = tickets[i][1];

            Edge[first].insert(second);
        }

        DFS("JFK", Edge);

        return ans;
    }
};
