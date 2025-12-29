#include <iostream>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int N, Answer, BlackMax, WhiteMax;

vector<vector<int>> Board;
unordered_map<int, bool> Left;
unordered_map<int, bool> Right;


bool Check(int Row, int Col)
{
    int RightIdx = Row + Col;
    int LeftIdx = Row - Col + N - 1;

    return !(Right[RightIdx] || Left[LeftIdx]);
}

void Mark(int Row, int Col, bool Flag)
{
    int RightIdx = Row + Col;
    int LeftIdx = Row - Col + N - 1;

    Right[RightIdx] = Flag;
    Left[LeftIdx] = Flag;
}

void Sol(int Idx, int Count, bool IsWhite)
{
    if (IsWhite)
    {
        WhiteMax = max(WhiteMax, Count);
    }
    else
    {
        BlackMax = max(BlackMax, Count);
    }

    for (int i = Idx; i < 2 * N - 1; i= i+2)
    {
        int StartRow = min(i, N - 1);
        int StartCol = max(0, i - (N - 1));

        int Diff = StartRow - StartCol;

        for (int j = 0; j <= Diff; ++j)
        {
            int Row = StartRow - j;
            int Col = StartCol + j;

            if (Board[Row][Col] == 1 && Check(Row, Col))
            {
                Mark(Row, Col, true);
                Sol(i + 2, Count + 1, IsWhite);
                Mark(Row, Col, false);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    Board.resize(N, vector<int>(N));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Board[i][j];
        }
    }

    Sol(0, 0, true);
    Sol(1, 0, false);

    Answer = BlackMax + WhiteMax;

    cout << Answer;

    return 0;
}