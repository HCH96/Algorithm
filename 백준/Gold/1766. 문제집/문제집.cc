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

    vector<int> InDeg(N+1);
    vector<vector<int>> Edge(N + 1);

    for (int i = 0; i < M; ++i)
    {
        int s, e;
        cin >> s >> e;

        Edge[s].push_back(e);
        ++InDeg[e];
    }

    priority_queue<int, vector<int>, greater<>> pq;

    for (int i = 1; i <= N; ++i)
    {
        if (InDeg[i] == 0)
        {
            pq.push(i);
        }
    }

    vector<int> Answer;

    while (!pq.empty())
    {
        int Cur = pq.top();
        pq.pop();

        Answer.push_back(Cur);

        for (auto Next : Edge[Cur])
        {
            if (--InDeg[Next] == 0)
            {
                pq.push(Next);
            }
        }
    }

    int n = Answer.size();

    for (int i = 0; i < n; ++i)
    {
        cout << Answer[i] << " ";
    }


    return 0;
}