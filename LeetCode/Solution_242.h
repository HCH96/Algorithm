#pragma once

#include "pch.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (t.size() != s.size())
            return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        bool flag = true;
        for (int i = 0; i < t.size(); ++i)
        {
            if (t[i] != s[i])
            {
                flag = false;
                break;
            }
        }

        return flag;

    }
};