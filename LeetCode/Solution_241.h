#pragma once
#include "pch.h"

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {

        vector<int> ans;

        for (int i = 0; i < expression.size(); ++i)
        {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
            {
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);

                vector<int> vecLeft = diffWaysToCompute(left);
                vector<int> vecRight = diffWaysToCompute(right);

                for (int j = 0; j < vecLeft.size(); ++j)
                {
                    for (int k = 0; k < vecRight.size(); ++k)
                    {
                        switch (expression[i])
                        {
                        case '+':
                        {
                            ans.push_back(vecLeft[j] + vecRight[k]);
                        }
                        break;

                        case '-':
                        {
                            ans.push_back(vecLeft[j] - vecRight[k]);
                        }
                        break;
                        case '*':
                        {
                            ans.push_back(vecLeft[j] * vecRight[k]);
                        }
                        break;
                        }
                    }
                }
            }
        }

        if (ans.size() == 0)
            ans.push_back(stoi(expression));

        return ans;
    }
};