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

    cin >> N;

    vector<vector<int>> v(N, vector<int>(3));
    const int INF = 1e9;

    for (int i = 0; i < N; ++i)
    {
        int R, G, B;
        cin >> R >> G >> B;
        v[i][0] = R;
        v[i][1] = G;
        v[i][2] = B;
    }

    int Answer = INT_MAX;


    for (int i = 0; i < 3; ++i)
    {
        vector<int> Prev = { INF,INF,INF };
        Prev[i] = v[0][i];

        for (int j = 1; j < N; ++j)
        {
            vector<int> Cur(3);

            Cur[0] = min(Prev[1], Prev[2]) + v[j][0];
            Cur[1] = min(Prev[0], Prev[2]) + v[j][1];
            Cur[2] = min(Prev[0], Prev[1]) + v[j][2];

            Prev = Cur;
        }

        for (int j = 0; j < 3; ++j)
        {
            if (i == j)
                continue;

            Answer = min(Answer, Prev[j]);
        }

    }

    cout << Answer;

	return 0;
}