#pragma once

#include "global.h"

class Solution_5
{
public:
    string longestPalindrome(string s) {
        string ans = "";

        int max = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            pair<int, int> tmp1 = Sol(s, i, i + 1);
            pair<int, int> tmp2 = Sol(s, i, i);

            int len1 = tmp1.second - tmp1.first + 1;
            int len2 = tmp2.second - tmp2.first + 1;

            if (max < len1)
            {
                ans = s.substr(tmp1.first, len1);
                max = len1;
            }

            if (max < len2)
            {
                ans = s.substr(tmp2.first, len2);
                max = len2;
            }
        }

        return ans;
    }

    pair<int, int> Sol(const string& s, int left, int right)
    {
        if (s[left] != s[right])
        {
            return make_pair(0, 0);
        }

        while (left > 0 && right < s.length() - 1 && s[left - 1] == s[right + 1])
        {
            left--;
            right++;
        }

        return make_pair(left, right);
    }
};