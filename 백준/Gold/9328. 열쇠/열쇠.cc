#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int T, h, w;

int Diff[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

void BFS(vector<vector<char>>& Grid, unordered_map<char, bool>& keys, int& Answer)
{
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(h + 2, vector<bool>(w + 2, false));
    vector<pair<int, int>> waiting[26];

    q.push({ 0,0 });
    visited[0][0] = true;

    while (!q.empty())
    {
        int CurRow = q.front().first;
        int CurCol = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int NextRow = CurRow + Diff[i][0];
            int NextCol = CurCol + Diff[i][1];

            if (NextRow < 0 || NextRow >Grid.size() - 1 || NextCol <0 || NextCol >Grid[0].size() - 1 || visited[NextRow][NextCol] == true)
                continue;

            char NextChar = Grid[NextRow][NextCol];

            if (NextChar >= 'a' && NextChar <= 'z')
            {
                keys[toupper(NextChar)] = true;
                Grid[NextRow][NextCol] = '.';
                q.push({ NextRow,NextCol });
                visited[NextRow][NextCol] = true;

                for (auto it : waiting[NextChar - 'a'])
                {
                    Grid[it.first][it.second] = '.';
                    q.push({ it.first,it.second });
                    visited[it.first][it.second] = true;
                }
                waiting[NextChar - 'a'].clear();

            }
            else if (NextChar >= 'A' && NextChar <= 'Z')
            {
                if (keys[NextChar] == true)
                {
                    Grid[NextRow][NextCol] = '.';
                    q.push({ NextRow,NextCol });
                    visited[NextRow][NextCol] = true;
                }
                else
                {
                    waiting[NextChar-'A'].push_back({NextRow,NextCol});
                }
            }
            else if (NextChar == '.')
            {
                q.push({ NextRow,NextCol });
                visited[NextRow][NextCol] = true;
            }
            else if (NextChar == '$')
            {
                ++Answer;
                Grid[NextRow][NextCol] = '.';
                q.push({ NextRow,NextCol });
                visited[NextRow][NextCol] = true;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--)
    {
        int Answer = 0;

        cin >> h >> w;

        vector<vector<char>> Grid(h + 2, vector<char>(w + 2, '.'));

        for (int i = 1; i < h + 1; ++i)
        {
            for (int j = 1; j < w + 1; ++j)
            {
                cin >> Grid[i][j];
            }
        }

        string s;
        cin >> s;

        unordered_map<char, bool> keys;

        if (s != "0")
        {
            for (auto c : s)
            {
                keys[toupper(c)] = true;
            }
        }

        BFS(Grid, keys, Answer);

        cout << Answer << endl;

    }

    return 0;
}