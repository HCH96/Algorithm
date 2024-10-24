#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        vector<vector<int>> ans;

        sort(people.begin(), people.end(), [](const vector<int>& A, const vector<int>& B)
            {
                if (A[0] == B[0])
                    return A[1] < B[1];
                return A[0] > B[0];
        });

        for (int i = 0; i < people.size(); ++i)
        {
            if (ans.size() > people[i][1])
            {
                ans.insert(ans.begin()+people[i][1], people[i]);
            }
            else
            {
                ans.push_back(people[i]);
            }
        }

        return ans;
    }
};