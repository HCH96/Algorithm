#include <iostream>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int N, C, E;

int diff[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

vector<vector<bool>> visited;

bool Check(vector<vector<bool>>& visited,const vector<vector<int>>& v, int Row, int Col)
{
    if (v[Row][Col] == 0)
        return true;
    if (v[Row][Col] == 2)
        return false;

    bool Flag = true;

    for (int i = 0; i < 4; ++i)
    {
        int ny = Row + diff[i][0];
        int nx = Col + diff[i][1];
        if (ny >= 0 && ny < N && nx >= 0 && nx < N && visited[ny][nx] == false)
        {
            visited[ny][nx] = true;
            Flag = Flag && Check(visited, v, ny, nx);
        }
    }

    return Flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> C >> E;

    if (C + E >= N * N)
    {
        cout << "-1";
        return 0;
    }

    vector<vector<int>> v(N, vector<int>(N, 0));

    for (int i = 0; i < 2 * N - 1; ++i)
    {
        int StartRow = min(N - 1, i);
        int StartCol = max(0, i - (N - 1));

        int Len = StartRow - StartCol;
        for (int j = 0; j <= Len; ++j)
        {
            int Row = StartRow - j;
            int Col = StartCol + j;
            v[Row][Col] = 1;
            --C;

            if (C == 0)
                break;
        }

        if (C == 0)
            break;
    }

    for (int i = 2 * N - 2; i >=0 ; --i)
    {
        int StartRow = max(0, i - (N - 1));
        int StartCol = min(N - 1, i);

        int Len = StartCol - StartRow;
        
        for (int j = 0; j <= Len; ++j)
        {
            int Row = StartRow + j;
            int Col = StartCol - j;
            v[Row][Col] = 2;
            --E;

            if (E == 0)
                break;
        }

        if (E == 0)
            break;
    }

    visited.resize(N, vector<bool>(N, false));

    bool Flag = Check(visited, v, 0, 0);

    if (Flag)
    {
        cout << "1\n";

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                cout << v[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        cout << "-1";
    }
    
    return 0;
}
