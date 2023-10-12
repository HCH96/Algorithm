#pragma once
#include <vector>
#include <string>
#include <algorithm>

#include <unordered_map>

using namespace std;


class Solution_49
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> ans;
        unordered_map<string, int> table;

        ans.reserve(100);

        int idx = 0;
        for (string s : strs)
        {
            string tmp(s);
            sort(tmp.begin(), tmp.end());
            if (table.find(tmp) == table.end())
            {
                table[tmp] = idx++;
                ans.push_back(vector<string>());
            }
            ans[table[tmp]].push_back(s);
        }

        return ans;
    }

};