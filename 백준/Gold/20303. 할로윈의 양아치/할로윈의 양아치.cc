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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    vector<int> v(N + 1, 0);
    vector<vector<int>> Edge(N+1);

    vector<bool> visited(N + 1, false);
    vector<long long> Candy;
    vector<int> Child;

    Candy.push_back(0);
    Child.push_back(0);

    for (int i = 1; i <= N; ++i)
    {
        cin >> v[i];
    }

    for (int i = 0; i < M; ++i)
    {
        int s, e;
        cin >> s >> e;
        Edge[s].push_back(e);
        Edge[e].push_back(s);
    }

    for (int i = 1; i <= N; ++i)
    {
        if (visited[i] == false)
        {
            long long CandySum = 0;
            int ChildCount = 0;

            queue<int> q;
            visited[i] = true;
            q.push(i);

            while (!q.empty())
            {
                int Cur = q.front();
                q.pop();

                CandySum += v[Cur];
                ++ChildCount;

                for (auto Next : Edge[Cur])
                {
                    if (visited[Next] == false)
                    {
                        visited[Next] = true;
                        q.push(Next);
                    }
                }
            }

            Candy.push_back(CandySum);
            Child.push_back(ChildCount);
        }
    }

    int CompSize = Candy.size();
    int MaxChildCount = K;

    vector<vector<long long>> dp(MaxChildCount, vector<long long>(CompSize, 0));

    for (int i = 1; i < K; ++i)
    {
        for (int j = 1; j < CompSize; ++j)
        {
            int CurChild = Child[j];
            int CurCandy = Candy[j];

            dp[i][j] = dp[i][j - 1];

            if (i >= CurChild)
            {
                dp[i][j] = max(dp[i][j], dp[i - CurChild][j - 1] + CurCandy);
            }
        }
    }

    cout << dp[MaxChildCount - 1][CompSize - 1];


    return 0;
}