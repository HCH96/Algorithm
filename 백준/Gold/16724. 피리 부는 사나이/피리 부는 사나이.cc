#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int T, N, M, K, W, R, Q, S;


vector<int> Parent;

int Find(int Cur)
{
    if (Parent[Cur] == Cur)
        return Cur;

    return Parent[Cur] = Find(Parent[Cur]);
}

bool Union(int First, int Second)
{
    int a = Find(First);
    int b = Find(Second);

    if (a == b)
        return false;

    if (a > b)
        swap(a, b);

    Parent[b] = a;

    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;

    vector<string> Map(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> Map[i];
    }
    
    Parent.resize(N * M);

    for (int i = 0; i < N * M; ++i)
    {
        Parent[i] = i;
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int CurIdx = i * M + j;
            int NextIdx = -1;
            switch (Map[i][j])
            {
            case 'D':
                NextIdx = CurIdx + M;
                break;
            case 'U':
                NextIdx = CurIdx - M;
                break;
            case 'L':
                NextIdx = CurIdx - 1;
                break;
            case 'R':
                NextIdx = CurIdx + 1;
                break;
            }

            Union(CurIdx, NextIdx);
        }
    }

    set<int> s;
    for (int i = 0; i < N * M; ++i)
    {
        s.insert(Find(Parent[i]));
    }

    cout << s.size();

    return 0;
}