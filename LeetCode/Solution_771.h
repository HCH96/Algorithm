#pragma once

#include "pch.h"

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {

        unordered_map<char, int> m;
        int ans = 0;


        for (int i = 0; i < stones.size(); ++i)
        {
            m[stones[i]]++;
        }

        for (int i = 0; i < jewels.size(); ++i)
        {
            ans += m[jewels[i]];
        }

        return ans;

    }
};