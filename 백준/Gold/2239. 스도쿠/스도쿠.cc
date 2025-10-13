#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int T, N, M, K, W, R, Q, S;

string Arr[9];
int board[9][9];
vector<pair<int, int>> blanks;
bool IsEnd = false;



bool Check(int Row, int Col, int Value)
{
    for (int i = 0; i < 9; ++i)
    {
        if (board[Row][i] == Value)
            return false;
        if (board[i][Col] == Value)
            return false;
    }

    int StartX = (Col / 3) * 3;
    int StartY = (Row / 3) * 3;

    for (int i = StartX; i < StartX + 3; ++i)
    {
        for (int j = StartY; j < StartY + 3; ++j)
        {
            if (board[j][i] == Value)
                return false;
        }
    }

    return true;
}


void DFS(int Cur)
{
    if (IsEnd)
        return;

    if (blanks.size() == Cur)
    {
        for (int i = 0; i < 9; ++i)
        {
            for(int j=0; j<9; ++j)
            {
                cout << board[i][j];
            }
            cout << "\n";
        }

        IsEnd = true;
        return;
    }

    int CurRow = blanks[Cur].first;
    int CurCol = blanks[Cur].second;

    for (int i = 1; i <= 9; ++i)
    {
        if (Check(CurRow, CurCol, i) && !IsEnd)
        {
            board[CurRow][CurCol] = i;
            DFS(Cur + 1);
            board[CurRow][CurCol] = 0;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 9; ++i)
    {
        cin >> Arr[i];
    }

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            board[i][j] = Arr[i][j] - '0';

            if (board[i][j] == 0)
            {
                blanks.push_back({ i,j });
            }
        }
    }

    DFS(0);

	return 0;
}