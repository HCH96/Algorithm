#pragma once
#include "pch.h"
class Solution {
public:
    int hammingDistance(int x, int y) {

        int ans = 0;
        int tmp = x^y;

        while (tmp > 0)
        {
            if (tmp % 2 == 1)
            {
                ++ans;
            }
            tmp /= 2;
        }

        return ans;
    }
};