#pragma once
#include "pch.h"

class Solution {
public:
    string removeDuplicateLetters(string s) {

        string ans;

        unordered_map<char, int> m;
        unordered_map<char, int> check;
        
        stack<char> st;

        for (int i = 0; i < s.size(); ++i)
        {
            ++m[s[i]];
        }

        for (int i = 0; i < s.size(); ++i)
        {
            char Cur = s[i];
            --m[Cur];

            if (check[Cur] == 1)
                continue;

            while (!st.empty() && st.top() > Cur && m[st.top()] > 0)
            {
                char Prev = st.top();
                st.pop();
                --check[Prev];
            }

            st.push(Cur);
            ++check[Cur];
        }


        while (!st.empty())
        {
            ans.insert(ans.begin(), st.top());
            st.pop();
        }

        return ans;
    }
};
