#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int T, N, M, K, W, R, Q, S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;

    vector<vector<int>> Edges(N + 1);
    vector<int> InDeg(N + 1, 0);

    for (int i = 0; i < M; ++i)
    {
        cin >> K;

        int Prev;
        int Cur;

        cin >> Prev;

        for (int j = 1; j < K; ++j)
        {
            cin >> Cur;
            Edges[Prev].push_back(Cur);
            ++InDeg[Cur];
            Prev = Cur;
        }
    }

    vector<int> Answer;

    queue<int> q;

    for (int i = 1; i <= N; ++i)
    {
        if (InDeg[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int Cur = q.front();
        q.pop();

        Answer.push_back(Cur);

        for (auto Next : Edges[Cur])
        {
            if (--InDeg[Next] == 0)
            {
                q.push(Next);
            }
        }
    }

    if (Answer.size() != N)
    {
        cout << 0;
    }
    else
    {
        for (int i = 0; i < Answer.size(); ++i)
        {
            cout << Answer[i] << "\n";
        }
    }

    return 0;
}