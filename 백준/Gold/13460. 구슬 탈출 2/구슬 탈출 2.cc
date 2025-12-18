#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, M;

int Diff[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
bool Flag = false;
int Answer = INT_MAX;
vector<vector<char>> Grid;
int Dist[11][11][11][11];

vector<int> move(int BlueRow, int BlueCol, int RedRow, int RedCol, int Dir)
{
    int NextBlueRow = BlueRow;
    int NextBlueCol = BlueCol;
    
    int NextRedRow = RedRow;
    int NextRedCol = RedCol;

    while (Grid[NextBlueRow + Diff[Dir][0]][NextBlueCol + Diff[Dir][1]] == '.')
    {
        NextBlueRow += Diff[Dir][0];
        NextBlueCol += Diff[Dir][1];
    }

    if (Grid[NextBlueRow + Diff[Dir][0]][NextBlueCol + Diff[Dir][1]] == 'O')
    {
        NextBlueRow += Diff[Dir][0];
        NextBlueCol += Diff[Dir][1];
    }

    while (Grid[NextRedRow + Diff[Dir][0]][NextRedCol + Diff[Dir][1]] == '.')
    {
        NextRedRow += Diff[Dir][0];
        NextRedCol += Diff[Dir][1];
    }

    if (Grid[NextRedRow + Diff[Dir][0]][NextRedCol + Diff[Dir][1]] == 'O')
    {
        NextRedRow += Diff[Dir][0];
        NextRedCol += Diff[Dir][1];
    }

    if (NextBlueRow == NextRedRow && NextBlueCol == NextRedCol && Grid[NextBlueRow][NextBlueCol] != 'O')
    {
        // 상
        if (Dir == 0)
        {
            if (BlueRow > RedRow)
            {
                NextBlueRow -= Diff[Dir][0];
                NextBlueCol -= Diff[Dir][1];
            }
            else
            {
                NextRedRow -= Diff[Dir][0];
                NextRedCol -= Diff[Dir][1];
            }

        }
        // 하
        else if (Dir == 1)
        {
            if (BlueRow < RedRow)
            {
                NextBlueRow -= Diff[Dir][0];
                NextBlueCol -= Diff[Dir][1];
            }
            else
            {
                NextRedRow -= Diff[Dir][0];
                NextRedCol -= Diff[Dir][1];
            }
        }
        // 좌
        else if (Dir == 2)
        {
            if (BlueCol > RedCol)
            {
                NextBlueRow -= Diff[Dir][0];
                NextBlueCol -= Diff[Dir][1];
            }
            else
            {
                NextRedRow -= Diff[Dir][0];
                NextRedCol -= Diff[Dir][1];
            }
        }
        // 우
        else if (Dir == 3)
        {
            if (BlueCol < RedCol)
            {
                NextBlueRow -= Diff[Dir][0];
                NextBlueCol -= Diff[Dir][1];
            }
            else
            {
                NextRedRow -= Diff[Dir][0];
                NextRedCol -= Diff[Dir][1];
            }
        }
    }

    return { NextBlueRow,NextBlueCol,NextRedRow,NextRedCol };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    Grid.resize(N, vector<char>(M, '#'));
    fill(&Dist[0][0][0][0], &Dist[0][0][0][0] + 11 * 11 * 11 * 11, INT_MAX);

    pair<int, int> Blue;
    pair<int, int> Red;
    pair<int, int> Hole;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> Grid[i][j];
            if (Grid[i][j] == 'B')
            {
                Blue = { i,j };
                Grid[i][j] = '.';
            }

            if (Grid[i][j] == 'R')
            {
                Red = { i,j };
                Grid[i][j] = '.';
            }

            if (Grid[i][j] == 'O')
            {
                Hole = { i,j };
            }
        }
    }

    queue<vector<int>> q;
    Dist[Blue.first][Blue.second][Red.first][Red.second] = 0;
    q.push({ 0, Blue.first, Blue.second, Red.first, Red.second });

    bool Flag = false;

    while (!q.empty())
    {
        if (Flag == true)
            break;

        vector<int> Tmp = q.front();
        int Depth = Tmp[0];
        int BlueRow = Tmp[1];
        int BlueCol = Tmp[2];
        int RedRow = Tmp[3];
        int RedCol = Tmp[4];
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            vector<int> Res = move(BlueRow, BlueCol, RedRow, RedCol, i);
            int NextBlueRow = Res[0];
            int NextBlueCol = Res[1];
            int NextRedRow = Res[2];
            int NextRedCol = Res[3];

            if (NextBlueRow == Hole.first && NextBlueCol == Hole.second)
            {
                continue;
            }
            
            if (NextRedRow == Hole.first && NextRedCol == Hole.second)
            {
                Answer = min(Answer, Depth + 1);
                Flag = true;
                break;
            }

            if (Dist[NextBlueRow][NextBlueCol][NextRedRow][NextRedCol] > Depth + 1 && Depth+1 < 10)
            {
                Dist[NextBlueRow][NextBlueCol][NextRedRow][NextRedCol] = Depth + 1;
                q.push({ Depth + 1, NextBlueRow , NextBlueCol , NextRedRow , NextRedCol });
            }
        }
    }

    if (Answer == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << Answer;
    }

    return 0;
}