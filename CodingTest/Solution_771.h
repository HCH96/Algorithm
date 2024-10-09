#pragma once

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {

        unordered_map<char, bool> m;

        for (int i = 0; i < jewels.size(); ++i)
        {
            m[jewels[i]] = true;
        }

        int ans = 0;

        for (int i = 0; i < stones.size(); ++i)
        {
            if (m.find(stones[i]) != m.end())
            {
                ++ans;
            }
        }

        return ans;
    }
};
