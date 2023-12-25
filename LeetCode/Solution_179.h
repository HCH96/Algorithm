#pragma once

#include "pch.h"
struct cmp {
    bool operator()(string& a, string& b) {
        return a + b < b + a;
    }
};


class Solution {
public:
    string largestNumber(vector<int>& nums) {

        priority_queue<string, vector<string>, cmp> q;

        for (int i = 0; i < nums.size(); ++i)
        {
            q.push(to_string(nums[i]));
        }

        string ans = "";

        while (!q.empty())
        {
            ans += q.top();
            cout << q.top() << " ";
            q.pop();
        }

        if (ans[0] == '0') return "0";

        return ans;
    }
};