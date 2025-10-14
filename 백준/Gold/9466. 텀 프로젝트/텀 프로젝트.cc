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
    
    cin >> T;

    while (T--)
    {
        cin >> N;

        vector<int> v(N + 1);
        vector<int> InDeg(N + 1, 0);

        for (int i = 1; i <= N; ++i)
        {
            cin >> v[i];
            ++InDeg[v[i]];
        }

        int Answer = 0;

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
            
            ++Answer;

            if (--InDeg[v[Cur]] == 0)
            {
                q.push(v[Cur]);
            }
        }

        cout << Answer << "\n";
    }

    return 0;
}