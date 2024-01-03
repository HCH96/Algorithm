#pragma once
#include "pch.h"

class Solution {
public:
    string minWindow(string s, string t) {

        string ans;

        int minVal = INT_MAX;

        unordered_map<char, int> m;

        for (int i = 0; i < t.size(); ++i)
        {
            ++m[t[i]];
        }

        int left = 0;
        int right = 0;
        int cnt = 0;

        while (right < s.size())
        {
            if (m[s[right]] > 0)
            {
                ++cnt;
            }

            --m[s[right]];

            if (cnt == t.size())
            {
                while (left < right && m[s[left]] < 0)
                {
                    ++m[s[left]];
                    ++left;
                }

                if (right - left < minVal)
                {
                    ans = s.substr(left, right - left + 1);
                    minVal = right - left + 1;
                }
            }
            ++right;
        }

        return ans;
    }
};