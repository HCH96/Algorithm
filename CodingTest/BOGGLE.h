#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C, N;

string Board[5];

// dy, dx
int diff[8][2] = { {-1,-1} , {-1, 0} , {-1, 1},
                   { 0,-1} ,           { 0, 1},
                   { 1,-1} , { 1, 0} , { 1, 1} };

bool Solution(int depth, int y, int x, const string& CurString)
{
    if (depth == CurString.size())
        return true;

    if (y < 0 || y >= 5 || x < 0 || x >= 5)
        return false;

    if (CurString[depth] != Board[y][x])
        return false;

    for (int i = 0; i < 8; ++i)
    {
        if (Solution(depth + 1, y + diff[i][0], x + diff[i][1], CurString))
            return true;
    }

    return false;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> C;

    while (C--)
    {
        for (int i = 0; i < 5; ++i)
        {
            cin >> Board[i];
        }

        cin >> N;

        vector<string> Word(N);
        vector<bool> ans(N, false);

        for (int i = 0; i < N; ++i)
        {
            cin >> Word[i];
        }

        for (int i = 0; i < N; ++i)
        {
            for (int y = 0; y < 5; ++y)
            {
                for (int x = 0; x < 5; ++x)
                {
                    if (ans[i] == false)
                    {
                        ans[i] = ans[i] || Solution(0, y, x, Word[i]);
                    }
                }
            }
        }

        for (int i = 0; i < N; ++i)
        {
            const string& CurString = Word[i];
            bool CurAns = ans[i];

            cout << CurString << " ";

            if (CurAns)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }


    return 0;
}
