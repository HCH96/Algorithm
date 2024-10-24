#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int Chungong(vector<string>& stream) {

        vector<pair<char, int>> tree(pow(2, 31), { -1,-1 });

        vector<int> ans;

        for (int i = 0; i < stream.size(); ++i)
        {
            int idx = 0;
            int refIdx = 0;

            string CurStr = stream[i];

            for (int j = 0; j < CurStr.size(); ++j)
            {
                char c = CurStr[j];

                if (c - '0' == 0)
                {
                    idx = idx * 2 + 1;
                }
                else
                {
                    idx = idx * 2 + 2;
                }

                if (tree[idx].second == -1)
                {
                    tree[idx].first = c - '0';
                    tree[idx].second = i + 1;
                }
                else
                {
                    refIdx = tree[idx].second;
                    tree[idx].second = i + 1;
                }
            }

            ans.push_back(refIdx);
        }

    }
};
