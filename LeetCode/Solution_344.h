#pragma once
#include "pch.h"

class Solution {
public:
    void reverseString(vector<char>& s) {

        char tmp;

        int size = s.size();

        for (int i = 0; i < size / 2; ++i)
        {
            tmp = s[i];
            s[i] = s[size - i - 1];
            s[size - i - 1] = tmp;
        }

        return;
    }
};
