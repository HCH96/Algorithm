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

    vector<vector<int>> Edge(N + 1);
    vector<int> InDeg(N + 1, 0);

    for (int i = 0; i < M; ++i)
    {
        int left, right;
        cin >> left >> right;

        Edge[left].push_back(right);
        ++InDeg[right];
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
        Answer.push_back(Cur);
        q.pop();

        for (auto Next : Edge[Cur])
        {
            --InDeg[Next];
            if (InDeg[Next] == 0)
            {
                q.push(Next);
            }
        }
    }

    for (auto i : Answer)
    {
        cout << i << " ";
    }

	return 0;
}