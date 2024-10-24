#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = 0;
        int col = matrix[0].size() - 1;

        while (row < matrix.size() && col >= 0)
        {
            int Cur = matrix[row][col];

            if (target == Cur)
                return true;

            if (target > Cur)
            {
                ++row;
            }
            else
            {
                --col;
            }
        }

        return false;

    }
};