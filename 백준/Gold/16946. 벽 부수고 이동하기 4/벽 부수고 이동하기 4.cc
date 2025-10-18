#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int T, N, M, K, W, R, Q, S, G, P;

int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

vector<int> Parent;

int Find(int Cur)
{
    if (Parent[Cur] == Cur)
    {
        return Cur;
    }

    return Parent[Cur] = Find(Parent[Cur]);
}

bool Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x == y)
        return false;

    if (x > y)
        swap(x, y);
    Parent[y] = x;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    vector<vector<int>> v(N, vector<int>(M));
    vector<vector<int>> v2(N, vector<int>(M));
    Parent.resize(N * M);

    for (int i = 0; i < N * M; ++i)
    {
        Parent[i] = i;
    }

    for (int i = 0; i < N; ++i)
    {
        string tmp;
        cin >> tmp;

        for (int j = 0; j < M; ++j)
        {
            v[i][j] = tmp[j] - '0';
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (v[i][j] == 0 && visited[i][j] == false)
            {
                int Count = 0;

                vector<pair<int,int>> Empty;

                queue<pair<int, int>> q;
                visited[i][j] = true;
                q.push({ i,j });

                while (!q.empty())
                {
                    int Row = q.front().first;
                    int Col = q.front().second;
                    int CurIdx = Row * M + Col;
                    Empty.push_back({ Row,Col });
                    Count = (Count + 1) % 10;
                    q.pop();

                    for (int k = 0; k < 4; ++k)
                    {
                        int NRow = Row + dir[k][0];
                        int NCol = Col + dir[k][1];

                        if (NRow >= 0 && NCol>=0 && NRow < N && NCol < M && visited[NRow][NCol] == false && v[NRow][NCol] == 0)
                        {
                            int NIdx = NRow * M + NCol;
                            Union(CurIdx, NIdx);
                            visited[NRow][NCol] = true;
                            q.push({ NRow,NCol });
                        }
                    }
                }

                for (int k = 0; k < Empty.size(); ++k)
                {
                    v2[Empty[k].first][Empty[k].second] = Count;
                }
            }
        }
    }

    vector<vector<int>> Answer(N, vector<int>(M,0));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (v[i][j] == 1)
            {
                int Count = 0;

                set<int> s;

                for (int k = 0; k < 4; ++k)
                {
                    int NRow = i + dir[k][0];
                    int NCol = j + dir[k][1];

                    if (NRow >= 0 && NCol >= 0 && NRow < N && NCol < M && v[NRow][NCol] == 0)
                    {
                        s.insert(Find(NRow * M + NCol));
                    }
                }

                for (auto i : s)
                {
                    int Row = i / M;
                    int Col = i % M;
                    Count += v2[Row][Col];
                }

                Answer[i][j] = (Count + 1) % 10;
            }
        }
    }

    for(int i=0; i<N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cout << Answer[i][j];
        }
        cout << "\n";
    }


    return 0;
}