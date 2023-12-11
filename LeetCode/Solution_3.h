#pragma once

#include "pch.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int ans = 0;
        int left = 0;

        unordered_map<char, int> m;

        for (int right = 0; right < s.size(); ++right)
        {
            if (m[s[right]] == 0)
            {
                ++m[s[right]];
            }
            else
            {
                while (m[s[right]] > 0)
                {
                    --m[s[left]];
                    ++left;
                }

                m[s[right]] = 1;
            }

            cout << "left : " << left << ", right : " << right << endl;

            ans = max(ans, right - left + 1);
        }

        return ans;

    }
};