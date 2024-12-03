#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C, H, W, ans;

int diff[4][2] = {
                     {0,1}, //    t, 0
    {1,-1},  {1,0},  {1,1}  // 1, 2, 3
};

pair<int, int> Combi[4] = { {0,2}, {0,3}, {1,2}, {2,3} };

void Solution(vector<vector<bool>>& board)
{
    // 게임판을 다 덮었는지 확인
    bool flag = true;
    vector<int> target = { -1,-1 };
    for (int i = 0; i < board.size(); ++i)
    {
        if (flag == false)
            break;

        for (int j = 0; j < board[i].size(); ++j)
        {
            if (board[i][j] == false)
            {
                flag = false;
                target[0] = i;
                target[1] = j;
                break;
            }
        }
    }

    if (flag == true)
    {
        ++ans;
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int Subset1 = Combi[i].first;
        int Subset2 = Combi[i].second;

        int Subset1NextY = target[0] + diff[Subset1][0];
        int Subset1NextX = target[1] + diff[Subset1][1];

        int Subset2NextY = target[0] + diff[Subset2][0];
        int Subset2NextX = target[1] + diff[Subset2][1];

        // Subset1의 범위가 board를 넘어갔을 경우
        if (Subset1NextY < 0 || Subset1NextY >= H || Subset1NextX < 0 || Subset1NextX >= W)
            continue;

        // Subset2의 범위가 board를 넘어갔을 경우
        if (Subset2NextY < 0 || Subset2NextY >= H || Subset2NextX < 0 || Subset2NextX >= W)
            continue;

        if (board[Subset1NextY][Subset1NextX] == false && board[Subset2NextY][Subset2NextX] == false)
        {
            board[Subset1NextY][Subset1NextX] = true;
            board[Subset2NextY][Subset2NextX] = true;
            board[target[0]][target[1]] = true;

            Solution(board);

            board[Subset1NextY][Subset1NextX] = false;
            board[Subset2NextY][Subset2NextX] = false;
            board[target[0]][target[1]] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> C;

    while (C--)
    {
        cin >> H >> W;

        vector<vector<bool>> board(H, vector<bool>(W, false));
        ans = 0;
        int count = 0;

        for (int i = 0; i < H; ++i)
        {
            for (int j = 0; j < W; ++j)
            {
                char tmp;
                cin >> tmp;

                if (tmp == '#')
                {
                    board[i][j] = true;
                }
                else
                {
                    ++count;
                }
            }
        }
        if (count % 3 == 0)
        {
            Solution(board);
        }

        cout << ans << endl;
    }

    return 0;
}
