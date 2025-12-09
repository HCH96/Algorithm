#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int R, C, M;

// 상, 하, 우, 좌
int Diff[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

vector<vector<int>> Sharks;
vector<vector<int>> Grid;
int Answer = 0;

void Capture(int CurCol)
{
    for (int i = 0; i < R; ++i)
    {
        if (Grid[i][CurCol] == -1)
            continue;

        int SharkIdx = Grid[i][CurCol];
        Sharks[SharkIdx][5] = 0;
        Answer += Sharks[SharkIdx][4];
        return;
    }
}

void MoveNextPos(int Idx)
{
    int Row = Sharks[Idx][0];
    int Col = Sharks[Idx][1];
    int Speed = Sharks[Idx][2];
    int Dir = Sharks[Idx][3];

    int RowCycle = R * 2 - 2;
    int ColCycle = C * 2 - 2;

    // 상하
    if (Dir < 2)
    {
        Speed = Speed % RowCycle;

        for (int i = 0; i < Speed; ++i)
        {
            Row = Row + Diff[Dir][0];

            if (Row < 0 || Row > R - 1)
            {
                Dir = (Dir + 1) % 2;

                for (int j = 0; j < 2; ++j)
                {
                    Row = Row + Diff[Dir][0];
                }
            }
        }
    }
    // 좌우
    else
    { 
        Speed = Speed % ColCycle;

        for (int i = 0; i < Speed; ++i)
        {
            Col = Col + Diff[Dir][1];

            if (Col < 0 || Col > C - 1)
            {
                if (Dir == 2)
                    Dir = 3;
                else
                    Dir = 2;

                for (int j = 0; j < 2; ++j)
                {
                    Col = Col + Diff[Dir][1];
                }
            }
        }
    }

    Sharks[Idx][0] = Row;
    Sharks[Idx][1] = Col;
    Sharks[Idx][3] = Dir;
}

void Move()
{
    vector<vector<int>> NewGrid(R, vector<int>(C, -1));

    for (int i = 0; i < M; ++i)
    {
        int Idx = i; 
        int Size = Sharks[Idx][4];
        int IsAlive = Sharks[Idx][5];

        if (!IsAlive)
            continue;

        MoveNextPos(Idx);

        int Row = Sharks[Idx][0];
        int Col = Sharks[Idx][1];

        if (NewGrid[Row][Col] == -1)
        {
            NewGrid[Row][Col] = Idx;
        }
        else
        {
            int PrevSharkIdx = NewGrid[Row][Col];
            int PrevSharkSize = Sharks[PrevSharkIdx][4];

            if (PrevSharkSize < Size)
            {
                Sharks[PrevSharkIdx][5] = 0;
                NewGrid[Row][Col] = Idx;
            }
            else
            {
                Sharks[Idx][5] = 0;
            }
        }
    }

    Grid = NewGrid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C >> M;

    Sharks.resize(M);
    Grid.resize(R, vector<int>(C, -1));

    for (int i = 0; i < M; ++i)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;

        Grid[r-1][c-1] = i;
        Sharks[i] = { r-1,c-1,s,d-1,z,1 };
    }

    for (int i = 0; i < C; ++i)
    {
        Capture(i);
        Move();
    }

    cout << Answer;

    return 0;
}