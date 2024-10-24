#pragma once

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;

        for (int i = 0; i < expression.size(); ++i)
        {
            if (expression[i] == '+')
            {
                string leftStr = expression.substr(0, i);
                string rightStr = expression.substr(i+1);

                vector<int> left = diffWaysToCompute(leftStr);
                vector<int> right = diffWaysToCompute(rightStr);

                for (int i = 0; i < left.size(); ++i)
                {
                    for (int j = 0; j < right.size(); ++j)
                    {
                        int result = left[i] + right[j];

                        ans.push_back(result);
                    }
                }
            }

            if (expression[i] == '-')
            {
                string leftStr = expression.substr(0, i);
                string rightStr = expression.substr(i + 1);

                vector<int> left = diffWaysToCompute(leftStr);
                vector<int> right = diffWaysToCompute(rightStr);

                for (int i = 0; i < left.size(); ++i)
                {
                    for (int j = 0; j < right.size(); ++j)
                    {
                        int result = left[i] - right[j];

                        ans.push_back(result);
                    }
                }
            }

            if (expression[i] == '*')
            {
                string leftStr = expression.substr(0, i);
                string rightStr = expression.substr(i + 1);

                vector<int> left = diffWaysToCompute(leftStr);
                vector<int> right = diffWaysToCompute(rightStr);

                for (int i = 0; i < left.size(); ++i)
                {
                    for (int j = 0; j < right.size(); ++j)
                    {
                        int result = left[i] * right[j];

                        ans.push_back(result);
                    }
                }
            }

        }

        if (ans.size() == 0)
        {
            ans.push_back(stoi(expression));
        }

        return ans;
    }
};