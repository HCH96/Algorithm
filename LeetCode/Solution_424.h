#pragma once
#include "pch.h"

class Solution {
public:
    int characterReplacement(string s, int k) {

        int ans = -1;
        int cnt = k;

        int left = 0;
        int right = 0;
        int retIdx = s.size();

        while (right < s.size())
        {
            if (s[right] != s[left])
            {
                --cnt;
                if (retIdx > right)
                    retIdx = right;
            }

            if (cnt == 0 && right < s.size()-1 && s[right+1] != s[left])
            {
                ans = max(ans, right - left + 1);
                
                if (retIdx == s.size())
                {
                    left = right + 1;
                    right = right + 1;
                    cnt = k;
                }
                else
                {
                    left = retIdx;
                    right = retIdx;
                    cnt = k;
                    retIdx = s.size();
                }
            }

            if (right == s.size() - 1)
            {
                ans = max(ans, right - left + 1 + cnt);

                left = retIdx;
                right = retIdx;
                cnt = k;
                retIdx = s.size();
            }

            ++right;
        }
    
        if (ans > s.size())
            ans = s.size();

        return ans;
    }
};