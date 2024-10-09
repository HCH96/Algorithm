#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int diff[2][4]
{
    // ╩С, го, аб, ©Л 
    // dy
    {1, -1, 0, 0},
    // dx
    {0, 0, -1, 1},
};

class Solution {
public:
    void BFS(vector<vector<char>>& grid, queue<pair<int, int>>& q)
    {
        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();

            int CurY = cur.first;
            int CurX = cur.second;

            for (int i = 0; i < 4; ++i)
            {
                int nextY = CurY + diff[0][i];
                int nextX = CurX + diff[1][i];

                if (nextY >= 0 && nextY < grid.size() && nextX >= 0 && nextX < grid[0].size() && grid[nextY][nextX] == '1')
                {
                    grid[nextY][nextX] = '0';
                    q.push(make_pair(nextY, nextX));
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int ans = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    grid[i][j] = '0';
                    q.push(make_pair(i, j));
                    BFS(grid, q);
                    ++ans;
                }
            }
        }

        return ans;
    }
};