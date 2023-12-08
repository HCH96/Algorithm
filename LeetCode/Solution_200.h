#pragma once

#include "pch.h"

void DFS(vector<vector<char>>& grid, int row, int col)
{
    if (grid[row][col] != '1')
    {
        return;
    }

    grid[row][col] = '0';

    // ╩С
    if (row > 0)
    {
        DFS(grid, row - 1, col);
    }

    // го
    if (row < grid.size() -1)
    {
        DFS(grid, row + 1, col);
    }

    // аб
    if (col > 0)
    {
        DFS(grid, row, col - 1);
    }

    // ©Л
    if (col < grid[row].size() - 1)
    {
        DFS(grid, row, col + 1);
    }
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int ans = 0;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    DFS(grid, i, j);
                    ++ans;
                }
            }
        }

        return ans;
    }
};