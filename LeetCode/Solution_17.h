#pragma once
#include "pch.h"

vector<string> ans;
vector<string> input;


void DFS(int cur, int idx, string tmp)
{
    tmp += input[cur][idx];

    if (cur == input.size() - 1)
    {
        ans.push_back(tmp);
    }
    else
    {
        for (int i = 0; i < input[cur + 1].size(); ++i)
        {
            DFS(cur + 1, i,tmp);
        }
    }

}



class Solution {
public:
    vector<string> letterCombinations(string digits) {
        ans.clear();
        input.clear();

        if (digits.size() == 0) return ans;

        vector<string> v(8);
        v[0] = "abc";
        v[1] = "def";
        v[2] = "ghi";
        v[3] = "jkl";
        v[4] = "mno";
        v[5] = "pqrs";
        v[6] = "tuv";
        v[7] = "wxyz";

        for (int i = 0; i < digits.size(); ++i)
        {
            input.push_back(v[digits[i] - '2']);
        }

        string tmp;

        for (int i = 0; i < input[0].size(); ++i)
        {
            DFS(0, i, tmp);
        }



        return ans;
    }
};