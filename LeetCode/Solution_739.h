#pragma once

#include "pch.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        // index, ¿Âµµ
        stack<pair<int, int>> st;
        vector<int> ans(temperatures.size(), 0);


        for (int i = 0; i < temperatures.size(); ++i)
        {
            while (!st.empty() && st.top().second < temperatures[i])
            {
                ans[st.top().first] = i - st.top().first;
                st.pop();
            }

            st.push(make_pair(i, temperatures[i]));
        }

        return ans;

    }
};