#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int T, N, K, W;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;

    while (T--)
    {
        cin >> N >> K;

        vector<int> Time(N + 1);
        vector<int> Dist(N + 1, -1);
        vector<int> InDeg(N + 1, 0);

        for (int i = 1; i <= N; ++i)
        {
            cin >> Time[i];
        }

        vector<vector<int>> Edge(N + 1);

        for (int i = 0; i < K; ++i)
        {
            int S, E;
            cin >> S >> E;
            Edge[S].push_back(E);
            ++InDeg[E];
        }

        cin >> W;

        queue<int> q;

        for (int i = 1; i <= N; ++i)
        {
            if (InDeg[i] == 0)
            {   
                Dist[i] = Time[i];
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int Cur = q.front();
            q.pop();

            for (auto Next : Edge[Cur])
            {
                if (Dist[Cur] + Time[Next] > Dist[Next])
                {
                    Dist[Next] = Dist[Cur] + Time[Next];
                    q.push(Next);
                }
            }
        }

        cout << Dist[W] << "\n";
    }

	return 0;
}