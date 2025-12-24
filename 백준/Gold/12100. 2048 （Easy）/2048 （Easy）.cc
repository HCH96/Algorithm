#include <iostream>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int N, Answer;

void Check(const vector<vector<int>>& board)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (board[i][j] > Answer)
            {
                Answer = board[i][j];
            }
        }
    }
}

void MoveRow(vector<vector<int>>& board, int CurRow, bool reverse)
{
    if (reverse)
    {
        int CurIdx = N - 1;

        for (int i = N - 1; i >= 0; --i)
        {
            if (board[CurRow][i] != 0)
            {
                int Tmp = board[CurRow][i];
                board[CurRow][i] = 0;
                board[CurRow][CurIdx--] = Tmp;
            }
        }
    }
    else
    {
        int CurIdx = 0;

        for (int i = 0; i < N; ++i)
        {
            if (board[CurRow][i] != 0)
            {
                int Tmp = board[CurRow][i];
                board[CurRow][i] = 0;
                board[CurRow][CurIdx++] = Tmp;
            }
        }
    }

}

void MoveCol(vector<vector<int>>& board, int CurCol, bool reverse)
{
    if (reverse)
    {
        int CurIdx = N - 1;

        for (int i = N - 1; i >= 0; --i)
        {
            if (board[i][CurCol] != 0)
            {
                int Tmp = board[i][CurCol];
                board[i][CurCol] = 0;
                board[CurIdx--][CurCol] = Tmp;
            }
        }
    }
    else
    {
        int CurIdx = 0;
        
        for (int i = 0; i < N; ++i)
        {
            if (board[i][CurCol] != 0)
            {
                int Tmp = board[i][CurCol];
                board[i][CurCol] = 0;
                board[CurIdx++][CurCol] = Tmp;
            }
        }
    }

}

void Move(vector<vector<int>>& board, int Dir)
{
    // 상
    if (Dir == 0)
    {
        for (int i = 0; i < N; ++i)
        {
            MoveCol(board, i, false);
        }
    }
    // 하
    else if (Dir == 1)
    {
        for (int i = 0; i < N; ++i)
        {
            MoveCol(board, i, true);
        }
    }
    // 좌
    else if (Dir == 2)
    {
        for (int i = 0; i < N; ++i)
        {
            MoveRow(board, i, false);
        }
    }
    // 우
    else if (Dir == 3)
    {
        for (int i = 0; i < N; ++i)
        {
            MoveRow(board, i, true);
        }
    }
}

void CompressRow(vector<vector<int>>& board, int CurRow, bool reverse)
{
    if (reverse)
    {
        int CurIdx = N - 2;
        while (CurIdx >= 0)
        {
            if (board[CurRow][CurIdx] == board[CurRow][CurIdx+1])
            {
                board[CurRow][CurIdx+1] *= 2;
                board[CurRow][CurIdx] = 0;
                CurIdx -= 2;
            }
            else
            {
                --CurIdx;
            }
        }
    }
    else
    {
        int CurIdx = 1;
        while (CurIdx < N)
        {
            if (board[CurRow][CurIdx] == board[CurRow][CurIdx-1])
            {
                board[CurRow][CurIdx-1] = board[CurRow][CurIdx-1] * 2;
                board[CurRow][CurIdx] = 0;
                CurIdx += 2;
            }
            else
            {
                ++CurIdx;
            }
        }
    }
}

void CompressCol(vector<vector<int>>& board, int CurCol, bool reverse)
{
    if (reverse)
    {
        int CurIdx = N - 2;
        while (CurIdx >= 0)
        {
            if (board[CurIdx][CurCol] == board[CurIdx + 1][CurCol])
            {
                board[CurIdx + 1][CurCol] *= 2;
                board[CurIdx][CurCol] = 0;
                CurIdx -= 2;
            }
            else
            {
                --CurIdx;
            }
        }
    }
    else
    {
        int CurIdx = 1;
        while (CurIdx < N)
        {
            if (board[CurIdx][CurCol] == board[CurIdx-1][CurCol])
            {
                board[CurIdx - 1][CurCol] = board[CurIdx - 1][CurCol] * 2;
                board[CurIdx][CurCol] = 0;
                CurIdx += 2;
            }
            else
            {
                ++CurIdx;
            }
        }
    }
}

void Compress(vector<vector<int>>& board, int Dir)
{
    // 상
    if (Dir == 0)
    {
        for (int i = 0; i < N; ++i)
        {
            CompressCol(board, i, false);
        }
    }
    // 하
    else if (Dir == 1)
    {
        for (int i = 0; i < N; ++i)
        {
            CompressCol(board, i, true);
        }
    }
    // 좌
    else if (Dir == 2)
    {
        for (int i = 0; i < N; ++i)
        {
            CompressRow(board, i, false);
        }
    }
    // 우
    else if (Dir == 3)
    {
        for (int i = 0; i < N; ++i)
        {
            CompressRow(board, i, true);
        }
    }
}

void Proc(vector<vector<int>>& board, int Dir)
{
    Move(board, Dir);
    Compress(board, Dir);
    Move(board, Dir);
}

void DFS(int depth, const vector<vector<int>>& board)
{
    if (depth == 5)
    {
        Check(board);
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        vector<vector<int>> Tmp = board;

        Proc(Tmp, i);

        DFS(depth + 1, Tmp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    vector<vector<int>> board(N, vector<int>(N));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
        }
    }

    DFS(0, board);

    cout << Answer;
  
    return 0;
}