#pragma once

#include "pch.h"

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;
        bool ans = true;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                st.push('(');
            }

            if (s[i] == '{')
            {
                st.push('{');
            }

            if (s[i] == '[')
            {
                st.push('[');
            }

            if (s[i] == ')')
            {
                if (st.empty() || st.top() != '(')
                {
                    ans = false;
                    break;
                }
                else
                {
                    st.pop();
                }
            }

            if (s[i] == '}')
            {
                if (st.empty() || st.top() != '{')
                {
                    ans = false;
                    break;
                }
                else
                {
                    st.pop();
                }
            }

            if (s[i] == ']')
            {
                if (st.empty() || st.top() != '[')
                {
                    ans = false;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
        }

        if (!st.empty())
        {
            ans = false;
        }


        return ans;
    }
};