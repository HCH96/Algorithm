#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <unordered_set>

using namespace std;

int N, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    string s;
    cin >> s;

    vector<vector<int>> v(3);
    vector<int> Input(N);

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'B')
        {
            v[0].push_back(i);
            Input[i] = 0;
        }
        else if (s[i] == 'O')
        {
            v[1].push_back(i);
            Input[i] = 1;
        }
        else 
        {
            v[2].push_back(i);
            Input[i] = 2;
        }
    }

    vector<int> dist(N, INT_MAX);
    dist[0] = 0;

    queue<pair<int, int>> q;
    q.push({ 0,0 });
    while (!q.empty())
    {
        int CurIdx = q.front().first;
        int CurDist = q.front().second;
        q.pop();

        if (dist[CurIdx] < CurDist)
            continue;

        int Next = (Input[CurIdx] + 1) % 3;

        for (auto NextIdx : v[Next])
        {
            if (NextIdx <= CurIdx)
                continue;

            int NextDist = (NextIdx - CurIdx) * (NextIdx - CurIdx) + CurDist;
            if (dist[NextIdx] > NextDist)
            {
                dist[NextIdx] = NextDist;
                q.push({ NextIdx,NextDist });
            }
        }
    }

    if (dist[N-1] == INT_MAX)
        cout << -1;
    else
        cout << dist[N-1];

    return 0;
}
